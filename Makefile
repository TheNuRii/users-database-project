TARGET = bin/dbview
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

run: clean default
	./$(TARGET) -f ./mynewdb.db -n
	./$(TARGET) -f ./mynewdb.db -a "John Doe, 123 Main Street, 120"
	./$(TARGET) -f ./mynewdb.db -l 
	./$(TARGET) -f ./mynewdb.db -r "John Doe"
	./$(TARGET) -f ./mynewdb.db -s "John Doe"

default: $(TARGET)

clean:
	rm -f obj/*.o
	rm -f bin/*
	rm -f *.db

$(TARGET): $(OBJ)
	gcc -o $@ $?

obj/%.o : src/%.c
	gcc -c $< -o $@ -Iinclude


