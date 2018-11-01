//
//  stockType.hpp
//  MP5_Templates
//
//  Created by Daniel Braunstein on 10/29/18.
//  Copyright © 2018 Daniel Braunstein. All rights reserved.
//

#ifndef stockType_hpp
#define stockType_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>

class stockType{
public:
    std::string symbol;
    double openPrice;
    double closePrice;
    double todayHigh;
    double todayLow;
    double prevClose;
    double percentGainOrLoss;
    int numOfShares;
    
    //SETTERS FOR STOCKTYPE
    void setSymbol(std::string _sym);
    void setOpenPrice(double _open);
    void setClosePrice(double _close);
    void setTodayHigh(double _toHi);
    void setTodayLow(double _toLo);
    void setPrevClose(double _prev);
    void setPercentGainOrLoss(double _gl);
    void setNumOfShares(int _shares);
    
    void printStock();
    
    void showPrice();
    
    void printGL(); //(TodayClose - YesaterdayClose) / YesterdayClose * 100;
    
    friend std::istream& operator >> (std::istream & in, stockType &stock);
    friend std::ostream& operator << (std::ostream & out, const stockType &stock);
};

#endif /* stockType_hpp */
