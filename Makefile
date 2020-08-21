.PHONY: all
all: compile run

.PHONY: compile
compile: build build/rpg

.PHONY: run
run: build/rpg
	./build/rpg

build:
	mkdir build

build/rpg:
	g++ -o ./build/rpg -I includes ./src/*.cpp ./src/**/*.cpp