//
//  stockType.cpp
//  MP5_Templates
//
//  Created by Daniel Braunstein on 10/29/18.
//  Copyright © 2018 Daniel Braunstein. All rights reserved.
//

#include "stockType.hpp"
void setStock(){
    
};

void printStock(){
    
};

void showPrice(){
    
};

//(TodayClose - YesaterdayClose) / YesterdayClose * 100;
void stockType::printGL(){
    double GL = ((closePrice - prevClose) / prevClose * 100);
    
    std::cout << std::setprecision(2) << std::fixed << std::showpoint
    << std::setw(6) << std::right << GL << '%';
    
};




//this will read in one line, broken by the delimiting character (\n)
std::istream & operator>> (std::istream &in, stockType &_stock){
     in >> _stock.symbol >> _stock.openPrice >> _stock.closePrice >>
     _stock.todayHigh >> _stock.todayLow >> _stock.prevClose
     >> _stock.numOfShares;
    
    return in;
 }

//this will print all data for the OBJECT
std::ostream& operator << (std::ostream &out, const stockType &_stock){
 
    out << std::setw(5) << std::left << _stock.symbol;
    out << std::setprecision(2) << std::fixed << std::showpoint << std::setw(7) << std::left << _stock.openPrice;
    out << std::setw(7) << std::left <<  _stock.closePrice;
    out << std::setw(7) << std::left <<  _stock.todayHigh;
    out << std::setw(7) << std::left <<  _stock.todayLow;
    out << std::setw(15) << std::right <<  _stock.prevClose;
    out << std::setw(8) << std::right <<  _stock.numOfShares;
    
    return out;
 }

/*
 stockType operator >(){
 
 }
 
 stockType operator < (){
 }
 
 */
