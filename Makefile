.PHONY: all
all: compile run

.PHONY: compile
compile: build
	g++ -o ./build/rpg -I includes ./src/*.cpp ./src/**/*.cpp ./src/**/**/*.cpp

.PHONY: run
run: build/rpg
	./build/rpg

build:
	mkdir build

build/rpg:
	compile