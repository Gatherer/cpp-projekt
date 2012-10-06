#include "misc.h"

t_time misc::getTimeStruct() {
  time_t Zeitstempel;
  Zeitstempel = time(0);
  t = localtime(&Zeitstempel);

  return t;
}
