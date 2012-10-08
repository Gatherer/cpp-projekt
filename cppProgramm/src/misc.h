#ifndef MISC_H_
#define MISC_H_

// nicht 100%ig sicher ob es so klappt mit t_datetime .. sollte aber
typedef struct str_datetime {
	int str_sec;
	int str_min;
	int str_hour;
	int str_day;
	int str_month;
	int str_year;
} t_datetime;

class misc {
  public:
	t_datetime getDateTimeStruct() const;

  private:
	t_datetime timeStruct;
};

#endif /* MISC_H_ */
