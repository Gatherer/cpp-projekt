#ifndef TDATE_H_
#define TDATE_H_

/* Klasse tdate */
class tdate 
{
  public:
    /* Konstruktoren */
    tdate();
    tdate(int day, int month, int year);
    
	/* Dekonstruktor */

	/* set() und get() Methoden */
	void set(int day, int month, int year);
	
	int get_day() { return day; }
    int get_month() {return month; }
    int get_year() {return year; }

	/* print Methoden */
	void print();

  private:
    int day;
    int month;
    int year;
};

#endif /* TDATE_H_ */
