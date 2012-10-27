#ifndef TMONEY_H_
#define TMONEY_H_

#include <string>

/* Klasse tmoney */
class tmoney 
{
  public:
	/* Konstruktoren */
    tmoney();
    tmoney(double amount, std::string currency="Euro");
    
	/* Dekonstruktor */

	/* set() und get() Methoden */
    void set(double amount, std::string currency);
    
	double get_amount() { return amount; }
    string get_currency() { return currency; }

	/* print Methoden */
	void print();

  private:
    double amount;
    std::string currency;
};

#endif /* TMONEY_H_ */