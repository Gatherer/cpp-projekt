//============================================================================
// Name        : cppProjekt.cpp
// Author      : Glatte, Thomas; Gruender Jessica
// Version     : 0.6
// Description : main file for our c++ projekt
//============================================================================

#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

#include "tbooking.h"
#include "tdate.h"
#include "ttime.h"
#include "tmoney.h"
#include "tcustomer.h"
#include "taccount.h"
#include "tbank.h"
#include "tcurrentaccount.h"
#include "tsavingsaccount.h"
#include "tfixeddepositaccount.h"
#include "ttransactionlist.h"
#include "ttransaction.h"
#include "tliste.h"

void enter()
{
  cout << "Press enter to continue...";
  cin.get();
//  fuer Linux
    system("clear");

// fuer Windows
//  system("cls");
}

tbank *get_bank(tbank *B1, tbank *B2, string BLZ)
{
   if ((B1->get_bankleitzahl()).compare(BLZ) == 0)       return B1;
   if ((B2->get_bankleitzahl()).compare(BLZ) == 0)       return B2;
   return NULL;
}

int main()
{
   //  fuer Windows
   // char *Dateiname = (char *) "C:/Users/Thomas/Documents/GitHub/cpp-projekt/cppProgramm/Aufgabe5/transaction.list";
   
   //  fuer Linux
   char *Dateiname = (char *) "transaction.list";

   tdate Datum1(7, 7, 1977);
   tdate Datum2(8, 8, 1988);
   tdate Datum3(6, 6, 1966);
   
   tcustomer  Bundesdruckerei("Geldquelle", tdate(), "", "", "", "");
   tcustomer  Kunde1("Egon Muster", Datum1, "Mustergasse", "3a", "99889", "Musterstadt");
   tcustomer  Kunde2("Rudolph Rednose", Datum2, "Berliner Str.", "17", "10999", "Berlin");
   tcustomer  Kunde3("Karin Kunze", Datum3, "Muenchner Str.", "39", "90123", "Muenchen");
   
   tbank *Bank = NULL;
   tbank *Bank1 = new tbank("Berliner Bank", "10020000");
   tbank *Bank2 = new tbank("Muenchner Bank", "10090099");
   
   taccount  *Geldquelle = new taccount(&Bundesdruckerei, Bank1, "0", "0000");
   taccount  *Konto1     = new tcurrentaccount(&Kunde1, Bank1, "1234567890", "9999", tmoney(100.0));
   taccount  *Konto2     = new tsavingsaccount(&Kunde2, Bank1, "9876543120", "0101", 1.5);
   taccount  *Konto3     = new tfixeddepositaccount(&Kunde1, Bank2, "111333555", "1357", tmoney(100.0), 1.5);
   taccount  *Konto4     = new tcurrentaccount(&Kunde3, Bank2, "999777555", "4444", tmoney(200.0));

   ttransactionlist TL(Dateiname);
   for (unsigned i = 0; i < TL.get_TransactionsCount(); i++)
   {
      taccount *Konto = NULL, *Gegenkonto = NULL;
      
      Konto           = NULL;
      Bank            = get_bank(Bank1, Bank2, TL[i].get_BLZ());
      if (Bank) 
      Konto           = Bank->get_Account2(TL[i].get_AccountNr());
      
      Gegenkonto      = NULL;
      Bank            = get_bank(Bank1, Bank2, TL[i].get_ContraBLZ());
      if (Bank)
         Gegenkonto   = Bank->get_Account2(TL[i].get_ContraAccountNr());

      if (Konto && Gegenkonto)
         tbooking *Buchung = new tbooking(TL[i].get_amount2(), Konto, Gegenkonto, TL.get_date(), TL.get_time(), TL[i].get_Text());
   }

   // Ausgaben:
   cout << "Transaktionsliste:" << endl << TL << endl;
   enter();
   cout << "Kunde 1:" << endl << Kunde1 << endl;
   enter();
   cout << "Kunde 2:" << endl << Kunde2 << endl;
   enter();
   cout << "Kunde 3:" << endl << Kunde3 << endl;
   enter();
   cout << "Bank 1: " << endl << *Bank1 << endl;
   enter();
   cout << "Bank 2: " << endl << *Bank2 << endl;
   enter();

   for (int i = 0; i < Bank1->get_amountBankaccounts(); i++)
   {
      (Bank1->get_Account(i))->printAccountStatement();
      cout << endl;
      enter();
   }
   for (int i = 0; i < Bank2->get_amountBankaccounts(); i++)
   {
      (Bank2->get_Account(i))->printAccountStatement();
      cout << endl;
      enter();
   }

   cout << "Jetzt werden die Banken vernichtet und damit auch die Konten der Banken:" << endl;
   delete Bank1;
   delete Bank2;
   enter();
   return 0;
}

