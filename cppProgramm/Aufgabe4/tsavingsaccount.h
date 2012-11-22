#ifndef TSAVINGSACCOUNT_H_
#define TSAVINGSACCOUNT_H_

#include "tmoney.h"
#include "taccount.h"

/* Klassen fuer Vorwertsdeklaration bekannt machen */
class tmoney;
class taccount;

/* Klasse taccount */
class tsavingsaccount: public taccount
{
  public:
    /* Konstruktoren */
    tsavingsaccount(tcustomer *customer, tbank *bank, std::string accountNumber, std::string pin, 
      double zinsen);
    
  /* Destruktor */
  virtual ~tsavingsaccount();

  /* set() und get() Methoden */
  void set_zinsen(double zinsen);
  double get_zinsen() { return zinsen; }

  /* print Methoden */
  void printAccountStatement();
  
  private:
    double zinsen;
};
#endif /* TSAVINGSACCOUNT_H_ */