#ifndef TACCOUNT_H_
#define TACCOUNT_H_

#include <string>

#include "tmoney.h"
#include "tcustomer.h"

/* Klassen fuer Vorwertsdeklaration bekannt machen */
class tcustomer;
class tmoney;

/* Klasse taccount */
class taccount
{
  public:
    /* Konstruktoren */
    taccount(tcustomer *customer, std::string accountNumber, std::string pin);
    
	/* Destruktor */
	virtual ~taccount();

	/* set() und get() Methoden */
	void set(tcustomer *customer, std::string accountNumber, std::string pin);

	string get_accountNumber() { return accountNumber; }
	string get_pin() { return pin; }
	int get_amountBookings() { return amountBookings; }

	/* print Methoden */
	void print();

  private:
    tcustomer *customer;
    std::string accountNumber;
    std::string pin;
    int amountBookings;
    tmoney amount;
};
#endif /* TACCOUNT_H_ */