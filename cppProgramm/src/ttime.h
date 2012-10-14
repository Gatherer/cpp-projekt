#ifndef TTIME_H_
#define TTIME_H_

typedef struct
{
  int sec;
  int min;
  int hour;
} s_ttime;


class ttime 
{
  public:
    ttime();
    ttime(int newHour, int newMin=0, int newSec=0);
    
	void print();
	void set(int newHour, int newMin=0, int newSec=0);
	s_ttime get();

  private:
    s_ttime A_ttime;
};

#endif /* TTIME_H_ */
