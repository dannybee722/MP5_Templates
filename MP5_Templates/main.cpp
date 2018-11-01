//
//  main.cpp
//  MP5_Templates
//
//  Created by Daniel Braunstein on 10/29/18.
//  Copyright © 2018 Daniel Braunstein. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "stockType.hpp"


int main(int argc, const char * argv[]) {
    
    std::fstream file;
    const std::string filePath = "/Users/ayesha/Documents/GitHub/MP5_Templates/MP5_Templates/stockData.txt";
    
    file.open(filePath);
    
    stockType stock;
    stockType stock2;
    
    file >> stock;
    
    stock2.setSymbol("MTET");
    stock.printStock(stock);
    
    return 0;
}
