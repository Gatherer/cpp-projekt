#include "ttime.h"
#include "misc.h"

void ttime::zeitSetzen(int newSec, int newMin, int newHour) {
  sec = newSec;
  min = newMin;
  hour = newHour;
}

void ttime::zeitHolen() {
	t_datetime time;

	time = misc.getDateTimeStruct();

	sec = time.str_sec;
	min = time.str_min;
	hour = time.str_hour;
}
