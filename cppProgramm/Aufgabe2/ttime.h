#ifndef TTIME_H_
#define TTIME_H_

/* Klasse ttime */
class ttime 
{
  public:
	/* Konstruktoren */
    ttime();
    ttime(int hour, int min=0, int sec=0);
    
	/* Dekonstruktor */

	/* set() und get() Methoden */
	void set(int hour, int min=0, int sec=0);
	
	int get_hour() { return hour; }
	int get_min() { return min; }
	int get_sec() { return sec; }

	/* print Methoden */
	void print();

  private:
    int sec;
    int min;
    int hour;
};

#endif /* TTIME_H_ */
