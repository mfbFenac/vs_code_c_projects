# Define compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Define source files and object files
SOURCES = main.c adding.c subtracting.c multiplying.c dividing.c
OBJECTS = $(SOURCES:.c=.o)

# Define the target executable
TARGET = program

# Default rule to compile each source file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build the target executable by linking object files
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Clean rule to remove generated files
clean:
	rm -f $(OBJECTS) $(TARGET)

