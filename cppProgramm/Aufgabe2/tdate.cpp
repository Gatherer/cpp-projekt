#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

#include "tdate.h"

/* Allgemeiner Konstruktor */
tdate::tdate(int Day, int Month, int Year)
{
	set(Day, Month, Year);
}

/* Standardkonstruktor */
tdate::tdate()
{
  time_t t;                                           /* Zeitstructur anlegen */

  t = time(0);                                        /* aktuelle Zeil holen */
  struct tm * now = localtime(&t);

  this -> day = now->tm_mday;                         /* Tag des Monats - [1,31] */
  this -> month = now->tm_mon+1;                      /* Monat im Jahr - [0,11] */
  this -> year = now->tm_year+1900;                   /* Jahr seit 1900 */
}

void tdate::print()
{
  cout << setfill('0');                               /* bei einstelligen Zahlen Fuellwert 0 */
  cout << setw(2) << day << "."			              /* setw() ist volatile */
	   << setw(2) << month << "." 
	   << setw(4) << year;
}

void tdate::set(int day, int month, int year)
{
  this -> day = day;
  this -> month = month;
  this -> year = year;
}