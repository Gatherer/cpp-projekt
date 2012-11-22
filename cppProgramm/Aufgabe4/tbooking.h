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
    tbooking(tbooking *booking);
    
    /* Destruktor */
    virtual ~tbooking();

    /* set() und get() Methoden */
    void set(tmoney amount, taccount *account, taccount *contraaccount, tdate date, ttime time, std::string text);
    //void set_printedcontra() { printed_contraaccount = true; }
    //void set_printed() { printed_account = true; }
    void set_printed(){printed=true;}
    void set_amount();
    bool get_printed(){return printed;}
    //bool get_printed() {return printed_account; }
    //bool get_printedcontra() {return printed_contraaccount; }
    tdate get_date() { return date; }
    string get_text() { return text; }
    tmoney get_amount() { return amount; }
    taccount* get_contraAccount() { return contraaccount; }
    taccount* get_account() { return account; }
  
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
    //bool printed_account;
    //bool printed_contraaccount;
};
#endif /* TBOOKING_H_ */