#ifndef TDATE_H_
#define TDATE_H_

typedef struct 
{
  int day;
  int month;
  int year;
} s_tdate;

class tdate 
{
  public:
    tdate();
    tdate(int day, int month, int year); 							// allgemeiner Konstruktor
    
	void print();
	void set(int day, int month, int year);
	s_tdate get();

  private:
    s_tdate A_tdate;
};

#endif /* TDATE_H_ */
