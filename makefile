# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Find all .c files in task subdirectories within lab05
SOURCES := $(shell find . -type f -name "*.c")

# Generate executable names based on source files
EXECUTABLES := $(SOURCES:.c=)

# Default target to compile all executables
all: $(EXECUTABLES)

# Compile each .c file into an executable in its own subdirectory
./%: ./%.c
	$(CC) $(CFLAGS) -o $@ $<

# Run a specific executable, e.g., "make run task=task1/task1"
run:
	@if [ -z "$(task)" ]; then \
		echo "Please specify the task to run, e.g., 'make run task=task1/task1'"; \
	else \
		if [ -f $(task) ]; then \
			echo "Running $(task)..."; \
			./$(task); \
		else \
			echo "Executable $(task) not found. Ensure it is compiled."; \
		fi \
	fi

# Clean up executables
clean:
	rm -f $(EXECUTABLES)

# Display help message
help:
	@echo "Available targets:"
	@echo "  make all             - Compile all executables in task subdirectories"
	@echo "  make [task/task]     - Compile a specific file (e.g., make task1/task1)"
	@echo "  make run task=task   - Run a specific executable (e.g., make run task=task1/task1)"
	@echo "  make clean           - Remove all executables"
	@echo "  make help            - Display this help message"
