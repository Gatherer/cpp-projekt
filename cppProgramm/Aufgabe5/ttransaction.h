#ifndef TTRANSACTION_H_
#define TTRANSACTION_H_

#include <string>
#include "tmoney.h"

/* Klassen fuer Vorwertsdeklaration bekannt machen */
class tmoney;

/* Klasse taccount */
class ttransaction
{
  public:
    /* Konstruktoren */
    ttransaction();
    
    /* Destruktor */
    virtual ~ttransaction();

    /* set() und get() Methoden */
        
  private:
    std::string accountNumber;
    std::string contraAccountNumber;
    std::string bankleitzahl;
    std::string contraBankleitzahl;
    std::string buchungstext;
    tmoney bookingAmount;

//    friend ostream &operator<< (ostream &ostr, ttransaction &transa);
  //  friend ifstream 
    
    
//    friend class taccount;
};

#endif /* TTRANSACTION_H_ */