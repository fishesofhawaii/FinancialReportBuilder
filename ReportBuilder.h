//
//  ReportBuilder.h
//  FinancialReportBuilder
//
//  Created by Kyle Inch on 4/23/15.
//  Copyright (c) 2015 Kinch. All rights reserved.
//

#ifndef FinancialReportBuilder_ReportBuilder_h
#define FinancialReportBuilder_ReportBuilder_h

#include "Builder.h"


class ReportBuilder: public Builder{
public:
    ~ReportBuilder(){}
    ReportBuilder(){}
    ReportBuilder(const ReportBuilder&) = default;
    ReportBuilder& operator=(const ReportBuilder &)=default;
    virtual void FoodPurchase(Transaction t){
        FoodPurchases.push_back(t);
        totalExpenses += t.Amount();
};
    virtual void ClothingPurchase(Transaction t){
        ClothingPurchases.push_back(t);
        totalExpenses += t.Amount();
};
    virtual void MiscPurchase(Transaction t){
        MiscPurchases.push_back(t);
        totalExpenses += t.Amount();
    };
    virtual void ElectronicsPurchase(Transaction t){
        ElectronicsPurchases.push_back(t);
        totalExpenses += t.Amount();
    };
    void PrintResults(){
        
        //Need to sort the data in each of the vectors before printing!
        SortResults(FoodPurchases);
        SortResults(ClothingPurchases);
        SortResults(MiscPurchases);
        SortResults(ElectronicsPurchases);
        //ABOVE ME
        
        
        
        cout.width(15);
        cout << endl << left;
        cout << "FOOD:" << endl;
        
        for(int i = 0; i < FoodPurchases.size(); i++){
            cout << setprecision(2) << fixed;
            cout << FoodPurchases[i].Date() << " ";
            cout.width(15); cout << FoodPurchases[i].Card() << left;
            cout << " $"<< FoodPurchases[i].Amount() << endl;
        }
        
        cout << endl << "CLOTHING:" << endl;
        for(int i = 0; i < ClothingPurchases.size(); i++){
            cout << ClothingPurchases[i].Date() << " ";
            cout.width(15); cout << ClothingPurchases[i].Card() << left;
            cout << " $"<< ClothingPurchases[i].Amount() << endl;
        }
        
        cout << endl << "MISC:" << endl;
        for(int i = 0; i < MiscPurchases.size(); i++){
            cout << MiscPurchases[i].Date() << " ";
            cout.width(15); cout << MiscPurchases[i].Card() << left;
            cout << " $"<< MiscPurchases[i].Amount() << endl;
        }
        
        cout << endl << "ELECTRONICS:" << endl;
        for(int i = 0; i < ElectronicsPurchases.size(); i++){
            cout << ElectronicsPurchases[i].Date() << " ";
            cout.width(15); cout << ElectronicsPurchases[i].Card() << left;
            cout << " $"<< ElectronicsPurchases[i].Amount() << endl;
        }
        cout << endl << "THE TOTAL COST OF ALL PURCHASES WAS: $" << totalExpenses;
    }
protected:
    void SortResults(vector<Transaction> &purchMemb){
        vector<Transaction> temp;
        for (int i = 0; i < purchMemb.size(); i++){
            if (temp.size() == 0){
                temp.push_back(purchMemb[i]);
                continue;
            }
            for (int j = 0; j < temp.size(); j++){
                if (purchMemb[i].DateWeight() < temp[j].DateWeight()){
                    //insert at index j
                    vector<Transaction>::iterator it = temp.begin();
                    temp.insert(it+j,purchMemb[i]);
                    break;
                }
                if (j+1 == temp.size()){
                    temp.push_back(purchMemb[i]);
                    break;
                }
            }
        }
        purchMemb = temp;
    }
private:
    double totalExpenses;
    vector<Transaction> FoodPurchases;
    vector<Transaction> ClothingPurchases;
    vector<Transaction> MiscPurchases;
    vector<Transaction> ElectronicsPurchases;
};

#endif
