
all: main tester

main: main.cpp
	g++ main.cpp -o main

tester: f.cpp f.h tester.cpp
	g++ tester.cpp f.cpp -o tester

f.cpp: f.cpp
