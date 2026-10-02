$CC = GCC
$CFLAGS = -Wall -Iinclude -Wextra -g

execute: main.c src/lib.c
	$(CC) $(CFLAGS) -o execute main.c src/lib.c

clean: execute
	rm execute
