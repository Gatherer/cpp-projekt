all: cppProject

cppProject: tdate.o ttime.o tmoney.o tcustomer.o taccount.o tbank.o tbooking.o cppProject.o 
	g++ tdate.o ttime.o tmoney.o tcustomer.o taccount.o tbank.o tbooking.o cppProject.o -o cppProject

tcustomer.o: tcustomer.cpp tcustomer.h tdate.cpp tdate.h taccount.cpp taccount.h
	g++ -c tcustomer.cpp

tbank.o: tbank.cpp tbank.h taccount.cpp taccount.h
	g++ -c tbank.cpp

tbooking.o: tbooking.cpp tbooking.h taccount.cpp taccount.h tmoney.cpp tmoney.h ttime.cpp ttime.h tdate.cpp tdate.h
	g++ -c tbooking.cpp

tmoney.o: tmoney.cpp tmoney.h
	g++ -c tmoney.cpp

tdate.o: tdate.cpp tdate.h
	g++ -c tdate.cpp

ttime.o: ttime.cpp ttime.h
	g++ -c ttime.cpp

taccount.o: taccount.cpp taccount.h tcustomer.cpp tcustomer.h tmoney.cpp tmoney.h tbank.cpp tbank.h
	g++ -c taccount.cpp

cppProject.o: cppProject.cpp ttime.cpp ttime.h tdate.cpp tdate.h tmoney.cpp tmoney.h tcustomer.cpp tcustomer.h taccount.cpp taccount.h tbank.cpp tbank.h tbooking.cpp tbooking.h
	g++ -c cppProject.cpp

clean:
	rm -rf *o cppProject

run:
	xterm -geometry 100x40 -e ./cppProject