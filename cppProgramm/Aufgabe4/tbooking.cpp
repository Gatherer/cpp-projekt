#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

#include "tbooking.h"
#include "taccount.h"
#include "tdate.h"
#include "ttime.h"
#include "tmoney.h"

/* Allgemeiner Konstruktor */
tbooking::tbooking(tmoney amount, taccount *account, taccount *contraaccount, tdate date, ttime time, string text)
{
  this -> amount = amount;
  this -> account = account;
  this -> contraaccount = contraaccount;
  this -> date = date;
  this -> time = time;
  this -> text = text;
  this -> printed = false;

  if(account->get_accountType() > 1)
  {
    if(amount.get_amount() < account->get_possibleMoney().get_amount())
	{
      account->setAccountBooking(this);
      contraaccount->setContraBooking(this);
	}
	else
	{
       print();
	}
  }
  else
  {
    account->setAccountBooking(this);
    contraaccount->setContraBooking(this);
  }
}

tbooking::tbooking(tbooking *booking)
{
  this -> amount = booking->amount;
  this -> account = booking->account;

  this -> contraaccount= booking->contraaccount;
  this -> date = booking -> date;
  this -> time = booking -> time;
  this -> text = booking -> text;
}

tbooking::~tbooking()
{

}

void tbooking::set_amount()
{
  amount.set_amount(amount.get_amount()*(-1));
}

void tbooking::print()
{
   cout << "Buchung kann nicht durchgeführt werden da die Deckung nicht ausreicht." << endl;
   cout << setfill(' ');
   cout << " |"; amount.print(); cout << " | " << left << setw(30) << account->get_customer()->get_name() << "| " 
	    " | " << left << setw(30) << contraaccount->get_customer()->get_name()<< text << endl;
}