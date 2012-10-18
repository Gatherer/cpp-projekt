all: cppProject

cppProject: tdate.o ttime.o cppProject.o
	g++ tdate.o ttime.o cppProject.o -o cppProject

tdate.o: tdate.cpp tdate.h
	g++ -c tdate.cpp

ttime.o: ttime.cpp ttime.h
	g++ -c ttime.cpp

cppProject.o: cppProject.cpp ttime.cpp ttime.h tdate.cpp tdate.h
	g++ -c cppProject.cpp

clean:
	rm -rf *o cppProject