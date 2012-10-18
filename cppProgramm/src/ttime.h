#ifndef TTIME_H_
#define TTIME_H_

class ttime 
{
  public:
    ttime();
    ttime(int hour, int min=0, int sec=0);
    
	void print();
	void set(int hour, int min=0, int sec=0);
	int get_hour() { return hour; }
	int get_min() { return min; }
	int get_sec() { return sec; }

  private:
    int sec;
    int min;
    int hour;
};

#endif /* TTIME_H_ */
