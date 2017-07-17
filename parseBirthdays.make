parseBirthdays:	parseBirthdays.o
	g++ -std=c++11 -o getName parseBirthdays.cpp

parseBirthdays.o:	parseBirthdays.cpp
	g++ -std=c++11 parseBirthdays.cpp
