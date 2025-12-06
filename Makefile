# Compiler and flags
CC      = gcc
CFLAGS  = -std=c11 -Wall -Wextra -Werror
TARGET  = flashcards
SRC     = flashcards.c

# Default target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

# Optional: rebuild from scratch
rebuild: clean all

.PHONY: all run clean rebuild
