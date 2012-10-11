#ifndef TTIME_H_
#define TTIME_H_

class ttime 
{
  public:
    ttime();
    ttime(int newHour, int newMin);
    void print();

  private:
    int sec;
    int min;
    int hour;
};

#endif /* TTIME_H_ */
