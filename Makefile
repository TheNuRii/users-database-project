TARGET_SRV = bin/dbserver
TARGET_CLI = bin/dbcli

SRC_SRV = $(wildcard src/server_site/*.c)
OBJ_SRV = $(SRC_SRV:src/server_site/%.c=obj/srv/%.o)

SRC_CLI = $(wildcard src/client_site/*.c)
OBJ_CLI = $(SRC_CLI:src/client_site/%.c=obj/cli/%.o)

run: clean default
	./$(TARGET_SRV) -f ./mynewdb.db -n -p 8080 &
	./$(TARGET_CLI) 127.0.0.1
	kill -9 $$(pidof dbserver)

default: $(TARGET_SRV) $(TARGET_CLI)

clean:
	rm -f obj/srv/*.o
	rm -f bin/*
	rm -f *.db

$(TARGET_SRV): $(OBJ_SRV)
	gcc -o $@ $?

$(OBJ_SRV): obj/srv/%.o: src/server_site/%.c
	gcc -c $< -o $@ -Iinclude

$(TARGET_CLI): $(OBJ_CLI)
	gcc -o $@ $?

$(OBJ_CLI): obj/cli/%.o: src/client_site/%.c
	gcc -c $< -o $@ -Iinclude