//
//  Builder.h
//  FinancialReportBuilder
//
//  Created by Kyle Inch on 4/23/15.
//  Copyright (c) 2015 Kinch. All rights reserved.
//

#ifndef FinancialReportBuilder_Builder_h
#define FinancialReportBuilder_Builder_h

#include "Transaction.h"

#include <string>
using namespace std;


class Builder{
public:
    ~Builder(){};
    Builder(const Builder &) =default;
    Builder& operator=(const Builder &rhs)=default;
    virtual void FoodPurchase(Transaction)=0;
    virtual void ClothingPurchase(Transaction)=0;
    virtual void MiscPurchase(Transaction)=0;
    virtual void ElectronicsPurchase(Transaction)=0;

private:
protected:
    Builder(){}
};

#endif
