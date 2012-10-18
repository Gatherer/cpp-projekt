#ifndef TDATE_H_
#define TDATE_H_

class tdate 
{
  public:
    tdate();
    tdate(int day, int month, int year);              // allgemeiner Konstruktor
    
	void print();
	void set(int day, int month, int year);
	int get_day() { return day; }
  int get_month() {return month; }
  int get_year() {return year; }

  private:
    int day;
    int month;
    int year;
};

#endif /* TDATE_H_ */
