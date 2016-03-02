all: hextrim

hextrim: main.o 
	g++ main.o Finder.o functions.o -o hextrim

main.o: main.cpp functions.o Finder.o 
	g++ -c main.cpp

functions.o: functions.cpp
	g++ -c functions.cpp

Finder.o: Finder.cpp
	g++ -c Finder.cpp
clean:
	rm *.o
