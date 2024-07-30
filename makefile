CC = gcc
CFLAGS = -Iinclude -Wall
SRC = src/main.c src/pitx.c
OBJ = bin/main.o bin/pitx.o
TARGET = bin/pitx

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

bin/%.o: src/%.c
	@mkdir -p bin
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)