//
//  main.cpp
//  FinancialReportBuilder
//
//  Created by Kyle Inch on 4/23/15.
//  Copyright (c) 2015 Kinch. All rights reserved.
//

#include "parser.h"
#include "ReportBuilder.h"
#include "Transaction.h"

#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(int argc, const char * argv[]) {
    vector<string> files = {"BOA.txt","Chase.txt","FifthThird.txt"};
    
    Parser p(files);
    ReportBuilder r;
    
    p.Parse(&r);
    
    r.PrintResults();
    
    return 0;
};
