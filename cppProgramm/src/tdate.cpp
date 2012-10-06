#include "tdate.h"

int TDATE::getDay() const {return day;}
int TDATE::getDay() const {return month;}
int TDATE::getDay() const {return year;}

void TDATE::datumSetzen(int newDay, int newMonth, int newYear) {
  day = newDay;
  month = newMonth;
  year = newYear;
}
