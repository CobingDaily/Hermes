CC = gcc
FLAGS = -Wall -Wextra -pedantic -g -Iinclude

build: | build_dir
	$(CC) $(FLAGS) src/*.c -o build/server

run: build
	./build/server 6767

build_dir:
	mkdir -p build

clean:
	rm -rf build

.PHONY: build run clean build_dir
