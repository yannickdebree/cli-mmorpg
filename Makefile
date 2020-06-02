all: compile run

compile:
	g++ -o ./build/rpg -I includes ./src/*.cpp ./src/**/*.cpp

run:
	./build/rpg