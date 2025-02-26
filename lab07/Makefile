FILE = debugMe_2024

build: $(FILE).c
	gcc -Wall -g $(FILE).c -o $(FILE) -lm -fno-pie -no-pie


.PHONY: db

db:
	gdb -tui $(FILE)

run:
	./$(FILE)