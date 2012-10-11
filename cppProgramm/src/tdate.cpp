#include "tdate.h"
#include <ctime>
#include <iostream>
using namespace std;

tdate::tdate(int newDay, int newMonth, int newYear)
{
  day = newDay;
  month = newMonth;
  year = newYear;
}

tdate::tdate()
{
  time_t t;				// Zeitstructur anlegen

  t = time(0);			// aktuelle Zeil holen
  struct tm * now = localtime(&t);

  day = now->tm_mday;		/* Tag des Monats - [1,31] */
  month = now->tm_mon+1;    /* Monat im Jahr - [0,11] */
  year = now->tm_year+1900; /* Jahr seit 1900 */
}

void tdate::print()
{
  cout << day << "." << month << "." << year;
}
