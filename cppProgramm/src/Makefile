all: cppProject

cppProject: tdate.o ttime.o cppProject.o
	g++ tdate.o ttime.o cppProject.o -o cppProject

tdate.o: tdate.cpp
	g++ -c tdate.cpp

ttime.o: ttime.cpp
	g++ -c ttime.cpp

cppProject.o: cppProject.cpp
	g++ -c cppProject.cpp

clean:
	rm -rf *o cppProject
