CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11
TARGET = compress
SRC = src/main.c src/parser/parser.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: all clean