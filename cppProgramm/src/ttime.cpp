#include "ttime.h"
#include <ctime>
#include <iostream>
using namespace std;

ttime::ttime(int newHour, int newMin, int newSec)
{
  sec = newSec;
  min = newMin;
  hour = newHour;
}

ttime::ttime()
{
  time_t t;				// Zeitstructur anlegen

  t = time(0);			// aktuelle Zeil holen
  struct tm * now = localtime(&t);

  sec = now->tm_sec;		/* Sekunden - [0,61] */
  min = now->tm_min;		/* Minuten - [0,59] */
  hour = now->tm_hour;		/* Stunden - [0,23] */
}

void ttime::print()
{
  cout << hour <<":" << min << ":" << sec;
}
