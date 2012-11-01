#ifndef TBOOKING_H_
#define TBOOKING_H_

#include <string>

#include "tmoney.h"
#include "taccount.h"
#include "ttime.h"
#include "tdate.h"

/* Klassen fuer Vorwertsdeklaration bekannt machen */
class taccount;
class tmoney;
class ttime;
class tdate;

/* Klasse taccount */
class tbooking
{
  public:
    /* Konstruktoren */
    tbooking(tmoney amount, taccount *account, taccount *contraaccount, tdate date, ttime time, std::string text);
    
    /* Destruktor */
    virtual ~tbooking();

    /* set() und get() Methoden */
    void set(tmoney amount, taccount *account, taccount *contraaccount, tdate date, ttime time, std::string text);
    void set_printed() { printed = true; }
    bool get_printed() {return printed; }
    tdate get_date() { return date; }
    string get_text() { return text; }
    tmoney get_amount() { return amount; }
    taccount* get_contraAccount() { return contraaccount; }
  
  /* print Methoden */
  void print();

  private:
    taccount *account;
    taccount *contraaccount;
    tdate date;
    ttime time;
    std::string text;
    tmoney amount;
    bool printed;
};
#endif /* TBOOKING_H_ */