#ifndef TDATE_H_
#define TDATE_H_

class tdate 
{
  public:
    tdate();
    tdate(int day, int month, int year); 							// allgemeiner Konstruktor
    void print();

  private:
    int day;
    int month;
    int year;
};

#endif /* TDATE_H_ */
