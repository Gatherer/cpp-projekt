#ifndef TTIME_H_
#define TTIME_H_

class ttime 
{
  public:
    ttime();
    ttime(int newHour, int newMin=0, int newSec=0);
    void print();

  private:
    int sec;
    int min;
    int hour;
};

#endif /* TTIME_H_ */
