//
//  Transaction.h
//  FinancialReportBuilder
//
//  Created by Kyle Inch on 4/23/15.
//  Copyright (c) 2015 Kinch. All rights reserved.
//

#ifndef FinancialReportBuilder_Transaction_h
#define FinancialReportBuilder_Transaction_h

#include <string>

using namespace std;

class Transaction{
public:
    ~Transaction(){}
    Transaction(){};
    Transaction(string amount, string date, string card):amount(amount),date(date),card(card){}
    double Amount(){return stod(amount);}
    string Date(){return date;}
    string Card(){return card;}
    int DateWeight(){
        // xx/xx/xxxx     (year)             (Month)            (Date)
         return stoi(date.substr(6,10) + date.substr(0,2) + date.substr(3,5));
    }
    
private:
    string amount;
    string date;
    string card;
    
    
};

#endif
