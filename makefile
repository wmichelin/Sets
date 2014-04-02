all: exec

exec: driver.o Set.o Complex.o
	g++ driver.o Set.o Complex.o -o exec

driver.o: driver.cpp
	g++ -c driver.cpp

Set.o: Set.cpp
	g++ -c Set.cpp

Complex.o: Complex.cpp
	g++ -c Complex.cpp

clean:
	rm -rf *o exec