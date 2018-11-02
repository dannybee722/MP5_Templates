//
//  main.cpp
//  MP5_Templates
//
//  Created by Daniel Braunstein on 10/29/18.
//  Copyright © 2018 Daniel Braunstein. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "stockListType.hpp"
#include "stockType.hpp"


//used to sort the vector
void bubSort(std::vector<stockType>& a, int n){
    for(int k = 0; k < n-1; k++) {
        
        for(int i = 0; i < n-k-1; i++) {
            if(a[ i ] > a[ i+1] ) {
                // here swapping of positions is being done.
                std::swap(a[i], a[i+1]);
            }
        }
    }
}

void printHeader(){
    //Title
    std::cout << std::setw(30) << " " << "Financial Report" << std::endl;
    //Categories
    std::cout << std::setw(15) << " " << "TODAY"
        << std::setw(25) << " " << "YESTERDAY"
        << std::setw(10) << "PERCENT" << std::endl;
    //subbcategories
    std::cout << std::setw(5) << std::left << "SYM"
        << std::setw(7) << std::left << "OPEN"
        << std::setw(7) << std::left << "CLOSE"
        << std::setw(7) << std::left << "HIGH"
        << std::setw(7) << std::left << "LOW"
        << std::setw(10) << " "
        << std::setw(7) << std::left << "CLOSE"
        << std::setw(7) << std::left << "SHARES"
        << std::setw(5) << "G/L" << std::endl;
}

int main(int argc, const char * argv[]) {
    
    //declare fstream object and open file
    std::fstream file;
    const std::string filePath = "/Users/ayesha/Documents/GitHub/MP5_Templates/MP5_Templates/stockData.txt";
    file.open(filePath);
    
    //create stocklist and populate
    stockListType<stockType> list;
    int i = 0;
    
    //while the next line isn't the end of the file, read in the text into the elements
    while(file.peek() != EOF){
        list.stockList.push_back(stockType());
        file >> list.stockList[i];
        i++;
    }
    //compensate for logic error in while loop that creates extra empty element
    list.stockList.erase(list.stockList.begin()+(i-1));
    
    //sort the vector based on elements in the symbol array
    bubSort(list.stockList, static_cast<int>(list.stockList.size()));
    
    printHeader();
    
    //print out data for stocks once sorted
    for (int j = 0; j < list.stockList.size(); j++){
        list.stockList[j].printStock(list.stockList[j]);
    }
    
    return 0;
}

