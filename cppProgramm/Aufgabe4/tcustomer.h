#ifndef TCUSTOMER_H_
#define TCUSTOMER_H_
#define MAXACCOUNTS 10

#include <string>

#include "tdate.h"
#include "taccount.h"

/* Klassen fuer Vorwertsdeklaration bekannt machen */
class taccount;
class tdate;

/* Klasse tcustomer */
class tcustomer
{
  public:
	/* Konstruktoren */
    tcustomer(std::string name, tdate birthday, std::string street, std::string housenumber, std::string zipcode, 
              std::string city);

    /* Dekonstruktor */

	/* set() und get() Methoden */
    void set(std::string name, tdate birthday, std::string street, std::string housenumber, std::string zipcode, 
             std::string city);
    string get_name() { return name; }
    tdate get_birthday() { return birthday; }
    string get_street() { return street; }
    string get_housenumber() { return housenumber; }
    string get_zipcode() { return zipcode; }
    string get_city() { return city; }
//  get Methode fuer taccount fehlt noch    
    int get_amountAccounts() { return amountAccounts; } 

	/* print Methoden */
	void print();

	/* sonstige Methoden */
	void addAmountAccounts();
	void deleteAmountAccounts();
    
  private:
    std::string name;
    std::string street;
    std::string housenumber;
    std::string zipcode;
    std::string city;
    tdate birthday;
    taccount *accounts[MAXACCOUNTS];
    int amountAccounts;

    friend class taccount;
    friend class tcurrentaccount;
    friend class tsavingsaccount;
    void setAccount(taccount *account);
};
#endif /* TCUSTOMER_H_ */