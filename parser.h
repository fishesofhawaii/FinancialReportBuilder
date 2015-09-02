//
//  parser.h
//  FinancialReportBuilder
//
//  Created by Kyle Inch on 4/23/15.
//  Copyright (c) 2015 Kinch. All rights reserved.
//

#ifndef FinancialReportBuilder_parser_h
#define FinancialReportBuilder_parser_h

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "Builder.h"
#include "Transaction.h"
using namespace std;

class Parser{
public:
    Parser() = default;
    Parser(vector<string> vs):fileNames(vs){};
    ~Parser() = default;
    
    vector<string> splitLine(string s){
        string temp = "";
        vector<string> v;
        for (int i = 0; i < s.length()-1; i++){
            if (s[i] == ' '){
                v.push_back(temp);
                temp = "";
            }
            else temp += s[i];
            
        }
        if (temp != "") v.push_back(temp);
        
        return v;
    }
    void Parse(Builder* builder){
        ifstream file;
        string line;
        vector<string> lineData;
        
        for (int i = 0; i < fileNames.size(); i++){
            string singleFile = fileNames[i];
            file.open(singleFile);
            getline(file,cardName); //Gives the first line of the Statement to "CardName"
            
            while (getline(file,line)){
                lineData = this->splitLine(line);
                Transaction t(lineData[2],lineData[0],cardName);
                if (lineData[1] == "Electronics"){
                    builder->ElectronicsPurchase(t);
                }
                else if (lineData[1] == "Food"){
                    builder->FoodPurchase(t);
                }
                else if (lineData[1] == "Clothing"){
                    builder->ClothingPurchase(t);
                }
                else if (lineData[1] == "Misc"){
                    builder->MiscPurchase(t);
                }
                else {
                    cout << "Invalid Data" << endl;
                }
            }
            file.close();
        }
    };
private:
    vector<string> fileNames;
    string cardName;
};

#endif
