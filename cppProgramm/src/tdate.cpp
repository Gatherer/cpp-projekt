#include "tdate.h"
#include "misc.h"


void tdate::tdate(int newDay, int newMonth, int newYear) {
  day = newDay;
  month = newMonth;
  year = newYear;
}

void tdate::tdate() {
	t_datetime date;

	date = misc.getDateTimeStruct();

	day = date.str_day;
	month = date.str_month;
	year = date.str_year;
}
