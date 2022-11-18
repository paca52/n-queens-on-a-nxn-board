
all: main

main: main.cpp
	g++ $< -o $@

clean:
	del main.exe