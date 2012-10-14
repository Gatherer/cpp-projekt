#include "ttime.h"
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

ttime::ttime(int newHour, int newMin, int newSec)
{
  ttime::set(newHour, newMin, newSec);
}

ttime::ttime()
{
  time_t t;										/* Zeitstructur anlegen */

  t = time(0);									/* aktuelle Zeil holen */
  struct tm * now = localtime(&t);

  A_ttime.sec = now->tm_sec;					/* Sekunden - [0,61] */
  A_ttime.min = now->tm_min;					/* Minuten - [0,59] */
  A_ttime.hour = now->tm_hour;					/* Stunden - [0,23] */
}

void ttime::print()
{
  cout << setfill('0');							/* bei einstelligen Zahlen Füllwert 0 */
  cout << setw(2) << A_ttime.hour << ":"        /* setw() ist volatile */
	   << setw(2) << A_ttime.min << ":" 
	   << setw(2) << A_ttime.sec;
}

void ttime::set(int newHour, int newMin, int newSec)
{
  A_ttime.sec = newSec;
  A_ttime.min = newMin;
  A_ttime.hour = newHour;
}

s_ttime ttime::get()
{
	return A_ttime;
}