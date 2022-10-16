Include := -I include
Libs := -lglfw

all:
	make source
	make clean
	clear

source: main.o window.o glad.o
	g++ *.o $(Libs) -o executable

main.o: src/main.cpp
	g++ -c src/main.cpp $(Include) -o main.o

window.o: src/headers/window.cpp
	g++ -c src/headers/window.cpp $(Include) -o window.o

glad.o: src/headers/glad.c
	g++ -c src/headers/glad.c $(Include) -o glad.o

clean:
	rm -f *.o