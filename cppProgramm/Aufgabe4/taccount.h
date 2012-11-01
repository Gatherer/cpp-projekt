#ifndef TACCOUNT_H_
#define TACCOUNT_H_

#define MAXBOOKINGS 100

#include <string>

#include "tmoney.h"
#include "tcustomer.h"
#include "tbooking.h"
#include "tdate.h"
#include "ttime.h"

/* Klassen fuer Vorwertsdeklaration bekannt machen */
class tcustomer;
class tmoney;
class tbank;
class tbooking;

/* Klasse taccount */
class taccount
{
  public:
    /* Konstruktoren */
    taccount(tcustomer *customer, tbank *bank, std::string accountNumber, std::string pin);
    
	/* Destruktor */
	virtual ~taccount();

	/* set() und get() Methoden */
	void set(tcustomer *customer, tbank *bank, std::string accountNumber, std::string pin);
  tcustomer* get_customer() { return customer; }
  tmoney get_money() { return amount; }
	string get_accountNumber() { return accountNumber; }
	string get_pin() { return pin; }
	int get_amountBookings() { return amountBookings; }

	/* print Methoden */
	void print();
  void printAccountStatement();

  private:
    tcustomer *customer;
    tbank *bank;
    std::string accountNumber;
    std::string pin;
    int amountBookings;
    tbooking *bookings[MAXBOOKINGS];
    tmoney amount;
    
    friend class tbooking;
    void setAccountBooking(tbooking *booking);
    void setContraBooking(tbooking *booking);
};
#endif /* TACCOUNT_H_ */