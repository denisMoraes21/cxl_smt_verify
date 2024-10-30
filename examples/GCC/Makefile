CC = g++
CFLAGS = -Wall -Wextra -g
TARGET = gcc_example
SRC = gcc_example.cpp
BEAR_OUTPUT = compile_commands.json

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
	rm -f $(BEAR_OUTPUT)
