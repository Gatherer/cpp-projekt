#include "tdate.h"
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

tdate::tdate(int newDay, int newMonth, int newYear)
{
	tdate::set(newDay, newMonth, newYear);
}

tdate::tdate()
{
  time_t t;										/* Zeitstructur anlegen */

  t = time(0);									/* aktuelle Zeil holen */
  struct tm * now = localtime(&t);

  A_tdate.day = now->tm_mday;					/* Tag des Monats - [1,31] */
  A_tdate.month = now->tm_mon+1;			    /* Monat im Jahr - [0,11] */
  A_tdate.year = now->tm_year+1900;				/* Jahr seit 1900 */
}

void tdate::print()
{
  cout << setfill('0');							/* bei einstelligen Zahlen Füllwert 0 */
  cout << setw(2) << A_tdate.day << ":"         /* setw() ist volatile */
	   << setw(2) << A_tdate.month << ":" 
	   << setw(4) << A_tdate.year;
}

void tdate::set(int newDay, int newMonth, int newYear)
{
  A_tdate.day = newDay;
  A_tdate.month = newMonth;
  A_tdate.year = newYear;
}

s_tdate tdate::get()
{
	return A_tdate;
}