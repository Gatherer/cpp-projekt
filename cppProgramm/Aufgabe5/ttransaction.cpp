#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include "ttransaction.h"
#include "tmoney.h"

/* Allgemeiner Konstruktor */
ttransaction::ttransaction()
{
  this -> accountNumber = "";
  this -> contraAccountNumber = "";
  this -> bankleitzahl = "";
  this -> contraBankleitzahl = "";
  this -> buchungstext = "";
  this -> bookingAmount = tmoney();
}

ttransaction::~ttransaction()
{
 
}

