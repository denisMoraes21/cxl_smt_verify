# Código lib glibc
Link: https://github.com/bminor/glibc/blob/master/nptl/pthread_mutex_init.c

    int ___pthread_mutex_init (pthread_mutex_t *mutex, const pthread_mutexattr_t *mutexattr)
    {
    const struct pthread_mutexattr *imutexattr;
    
    ASSERT_TYPE_SIZE (pthread_mutex_t, __SIZEOF_PTHREAD_MUTEX_T);
    
    /* __kind is the only field where its offset should be checked to
    avoid ABI breakage with static initializers.  */
    ASSERT_PTHREAD_INTERNAL_OFFSET (pthread_mutex_t, __data.__kind,
    __PTHREAD_MUTEX_KIND_OFFSET);
    ASSERT_PTHREAD_INTERNAL_MEMBER_SIZE (pthread_mutex_t, __data.__kind, int);
    
    imutexattr = ((const struct pthread_mutexattr *) mutexattr
    ?: &default_mutexattr);
    
    /* Sanity checks.  */
    switch (__builtin_expect (imutexattr->mutexkind
    & PTHREAD_MUTEXATTR_PROTOCOL_MASK,
    PTHREAD_PRIO_NONE
    << PTHREAD_MUTEXATTR_PROTOCOL_SHIFT))
    {
    case PTHREAD_PRIO_NONE << PTHREAD_MUTEXATTR_PROTOCOL_SHIFT:
    break;
    
        case PTHREAD_PRIO_INHERIT << PTHREAD_MUTEXATTR_PROTOCOL_SHIFT:
          if (__glibc_unlikely (prio_inherit_missing ()))
        return ENOTSUP;
          break;
    
        default:
          /* XXX: For now we don't support robust priority protected mutexes.  */
          if (imutexattr->mutexkind & PTHREAD_MUTEXATTR_FLAG_ROBUST)
        return ENOTSUP;
          break;
        }
    
    /* Clear the whole variable.  */
    memset (mutex, '\0', __SIZEOF_PTHREAD_MUTEX_T);
    
    /* Copy the values from the attribute.  */
    int mutex_kind = imutexattr->mutexkind & ~PTHREAD_MUTEXATTR_FLAG_BITS;
    
    if ((imutexattr->mutexkind & PTHREAD_MUTEXATTR_FLAG_ROBUST) != 0)
    {
    #ifndef __ASSUME_SET_ROBUST_LIST
    if ((imutexattr->mutexkind & PTHREAD_MUTEXATTR_FLAG_PSHARED) != 0
    && !__nptl_set_robust_list_avail)
    return ENOTSUP;
    #endif
    
          mutex_kind |= PTHREAD_MUTEX_ROBUST_NORMAL_NP;
        }
    
    switch (imutexattr->mutexkind & PTHREAD_MUTEXATTR_PROTOCOL_MASK)
    {
    case PTHREAD_PRIO_INHERIT << PTHREAD_MUTEXATTR_PROTOCOL_SHIFT:
    mutex_kind |= PTHREAD_MUTEX_PRIO_INHERIT_NP;
    break;
    
        case PTHREAD_PRIO_PROTECT << PTHREAD_MUTEXATTR_PROTOCOL_SHIFT:
          mutex_kind |= PTHREAD_MUTEX_PRIO_PROTECT_NP;
    
          int ceiling = (imutexattr->mutexkind
                 & PTHREAD_MUTEXATTR_PRIO_CEILING_MASK)
                >> PTHREAD_MUTEXATTR_PRIO_CEILING_SHIFT;
          if (! ceiling)
        {
          /* See __init_sched_fifo_prio.  */
          if (atomic_load_relaxed (&__sched_fifo_min_prio) == -1)
            __init_sched_fifo_prio ();
          if (ceiling < atomic_load_relaxed (&__sched_fifo_min_prio))
            ceiling = atomic_load_relaxed (&__sched_fifo_min_prio);
        }
          mutex->__data.__lock = ceiling << PTHREAD_MUTEX_PRIO_CEILING_SHIFT;
          break;
    
        default:
          break;
        }
    
    /* The kernel when waking robust mutexes on exit never uses
    FUTEX_PRIVATE_FLAG FUTEX_WAKE.  */
    if ((imutexattr->mutexkind & (PTHREAD_MUTEXATTR_FLAG_PSHARED
    | PTHREAD_MUTEXATTR_FLAG_ROBUST)) != 0)
    mutex_kind |= PTHREAD_MUTEX_PSHARED_BIT;
    
    /* See concurrency notes regarding __kind in struct __pthread_mutex_s
    in sysdeps/nptl/bits/thread-shared-types.h.  */
    atomic_store_relaxed (&(mutex->__data.__kind), mutex_kind);
    
    /* Default values: mutex not used yet.  */
    // mutex->__count = 0;	already done by memset
    // mutex->__owner = 0;	already done by memset
    // mutex->__nusers = 0;	already done by memset
    // mutex->__spins = 0;	already done by memset
    // mutex->__next = NULL;	already done by memset
    
    LIBC_PROBE (mutex_init, 1, mutex);
    
    return 0;
    }

# Código lib ESBMC gcc
Link: https://github.com/esbmc/esbmc/blob/master/src/c2goto/library/pthread_lib.c#L292

    int pthread_mutex_init(
    pthread_mutex_t *mutex,
    const pthread_mutexattr_t *mutexattr)
    {
    __ESBMC_HIDE:;
    __ESBMC_atomic_begin();
    __ESBMC_mutex_lock_field(*mutex) = 0;
    __ESBMC_mutex_count_field(*mutex) = 0;
    __ESBMC_mutex_owner_field(*mutex) = 0;
    __ESBMC_atomic_end();
    return 0;
    }

# Código kernel linux
Link: https://github.com/torvalds/linux/blob/v5.15/include/linux/slab.h

    static __always_inline void *kmalloc(size_t size, gfp_t flags)
    {
    if (__builtin_constant_p(size)) {
    #ifndef CONFIG_SLOB
    unsigned int index;
    #endif
    if (size > KMALLOC_MAX_CACHE_SIZE)
    return kmalloc_large(size, flags);
    #ifndef CONFIG_SLOB
    index = kmalloc_index(size);
    
            if (!index)
                return ZERO_SIZE_PTR;
    
            return kmem_cache_alloc_trace(
                    kmalloc_caches[kmalloc_type(flags)][index],
                    flags, size);
    #endif
    }
    return __kmalloc(size, flags);
    }

# Código kernel ESBMC
Link: https://github.com/esbmc/esbmc/blob/f99415911b46d9a01b93ab38f56388f5412d9630/src/c2goto/library/kernel.c#L43

    void *kmalloc(int size, int flags)
    {
    // Check size greater than  zero and less than max
    assert(size > 0 && size <= MAX_ALLOC_SIZE);
    //check flags greater than zero
    assert(flags > 0);
    
        //check if flags have corresponding valid values
        check_gfp_flags(flags);
        // If the size is larger than the KMALLOC_MAX_CACHE_SIZE, then handle in kmalloc_large
        if (size > KMALLOC_MAX_CACHE_SIZE)
        {
            // Call to kmalloc_large or equivalent function can be here.
            return __kmalloc_large(size, flags);
        }
    
        (void)flags; // Ignore flags.
        return __kmalloc(size, flags);
    }

# Estruturas aninhadas ESBMC pthread
Link: https://github.com/esbmc/esbmc/blob/master/src/c2goto/headers/pthread.h#L54

    typedef union
    {
    struct __pthread_mutex_s __data;
    char __size[40];
    long int __align;
    } pthread_mutex_t;

Link: https://github.com/esbmc/esbmc/blob/master/regression/esbmc-unix/github_1009_success/main.c#L517

    struct __pthread_mutex_s
    {
    int __lock;
    unsigned int __count;
    int __owner;
    unsigned int __nusers;
    int __kind;
    short __spins;
    short __elision;
    __pthread_list_t __list;
    };

Link: https://github.com/esbmc/esbmc/blob/master/regression/esbmc-unix/github_1009_success/main.c#L512

    typedef struct __pthread_internal_list
    {
    struct __pthread_internal_list *__prev;
    struct __pthread_internal_list *__next;
    } __pthread_list_t;

# Estruturas aninhadas GLIBC pthread
Link: https://github.com/bminor/glibc/blob/master/sysdeps/nptl/bits/pthreadtypes.h#L72

    typedef union
    {
    struct __pthread_mutex_s __data;
    char __size[__SIZEOF_PTHREAD_MUTEX_T];
    long int __align;
    } pthread_mutex_t;

Link: https://github.com/bminor/glibc/blob/master/sysdeps/x86/nptl/bits/struct_mutex.h#L22

    struct __pthread_mutex_s
    {
    int __lock;
    unsigned int __count;
    int __owner;
    #ifdef __x86_64__
    unsigned int __nusers;
    #endif
    /* KIND must stay at this position in the structure to maintain
    binary compatibility with static initializers.  */
    int __kind;
    #ifdef __x86_64__
    short __spins;
    short __elision;
    __pthread_list_t __list;
    # define __PTHREAD_MUTEX_HAVE_PREV      1
    #else
    unsigned int __nusers;
    __extension__ union
    {
    struct
    {
    short __espins;
    short __eelision;
    # define __spins __elision_data.__espins
    # define __elision __elision_data.__eelision
        } __elision_data;
        __pthread_slist_t __list;
    };
    # define __PTHREAD_MUTEX_HAVE_PREV      0
    #endif
    };

Link: https://github.com/bminor/glibc/blob/master/sysdeps/nptl/bits/thread-shared-types.h#L55

    typedef struct __pthread_internal_list
    {
    struct __pthread_internal_list *__prev;
    struct __pthread_internal_list *__next;
    } __pthread_list_t;

