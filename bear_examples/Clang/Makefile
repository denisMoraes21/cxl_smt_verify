CC = clang++
CFLAGS = -Wall -Wextra -stdlib=libc++
TARGET = clang_example
SRC = clang_example.cpp

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
