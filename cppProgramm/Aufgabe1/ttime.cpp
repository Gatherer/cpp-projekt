#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

#include "ttime.h"

ttime::ttime(int hour, int min, int sec)
{
  set(hour, min, sec);
}

ttime::ttime()
{
  time_t t;                                           /* Zeitstructur anlegen */

  t = time(0);                                        /* aktuelle Zeil holen */
  struct tm * now = localtime(&t);

  this -> sec = now->tm_sec;                          /* Sekunden - [0,61] */
  this -> min = now->tm_min;                          /* Minuten - [0,59] */
  this -> hour = now->tm_hour;                        /* Stunden - [0,23] */
}

void ttime::print()
{
  cout << setfill('0');                               /* bei einstelligen Zahlen Fuellwert 0 */
  cout << setw(2) << hour << ":"              /* setw() ist volatile */
	   << setw(2) << min << ":" 
	   << setw(2) << sec;
}

void ttime::set(int hour, int min, int sec)
{
  this -> sec = sec;
  this -> min = min;
  this -> hour = hour;
}