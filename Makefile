# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -O2

# Raylib libraries (adjust for your system)
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11  # Linux
# LDFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm  # Windows (MinGW)

# Source files
SRCS = main.c
OBJS = $(SRCS:.c=.o)

# Output binary
TARGET = game

# Default build
all: $(TARGET)

# Compile
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)
