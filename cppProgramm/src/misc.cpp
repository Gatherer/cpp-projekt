#include "misc.h"

t_datetime misc::getDateTimeStruct() {

  time_t Zeitstempel;				// Zeitstructur anlegen
  t_datetime t_back;

  Zeitstempel = time(0);			// aktuelle Zeil holen
  t = localtime(&Zeitstempel);		// Zeitformat umwandeln

  t_back.str_sec = t.tm_sec;		/* Sekunden - [0,61] */
  t_back.str_min = t.tm_min;		/* Minuten - [0,59] */
  t_back.str_hour = t.tm_hour;		/* Stunden - [0,23] */
  t_back.str_day = t.tm_mday;		/* Tag des Monats - [1,31] */
  t_back.str_month = t.tm_mon+1;    /* Monat im Jahr - [0,11] */
  t_back.str_year = t.tm_year+1970; /* Jahr seit 1900 */

  return t_back;
}
