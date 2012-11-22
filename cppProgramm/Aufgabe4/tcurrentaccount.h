#ifndef TCURRENTACCOUNT_H_
#define TCURRENTACCOUNT_H_

#include "tmoney.h"
#include "taccount.h"

/* Klassen fuer Vorwertsdeklaration bekannt machen */
class tmoney;
class taccount;

/* Klasse taccount */
class tcurrentaccount: public taccount
{
  public:
    /* Konstruktoren */
    tcurrentaccount(tcustomer *customer, tbank *bank, std::string accountNumber, std::string pin, 
      tmoney dispo);
    
  /* Destruktor */
  virtual ~tcurrentaccount();

  /* set() und get() Methoden */
  void set_dispo(double amount);
  tmoney get_dispo() { return dispo; }

  /* print Methoden */
  void printAccountStatement();
  
  private:
    tmoney dispo;
};
#endif /* TCURRENTACCOUNT_H_ */