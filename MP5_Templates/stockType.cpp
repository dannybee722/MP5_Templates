//
//  stockType.cpp
//  MP5_Templates
//
//  Created by Daniel Braunstein on 10/29/18.
//  Copyright © 2018 Daniel Braunstein. All rights reserved.
//

#include "stockType.hpp"

//default constructor/destructor
stockType::stockType(){
    
}
stockType::~stockType(){
    
}

//SETTERS FOR STOCKTYPE
void stockType::setSymbol(std::string _sym){
    this->symbol = _sym;
}
void stockType::setOpenPrice(double _open){
    this->openPrice = _open;
}
void stockType::setClosePrice(double _close){
    this->closePrice = _close;
}
void stockType::setTodayHigh(double _toHi){
    this->todayHigh = _toHi;
}
void stockType::setTodayLow(double _toLo){
    this->todayLow = _toLo;
}
void stockType::setPrevClose(double _prev){
    this->todayHigh = _prev;
}
void stockType::setPercentGainOrLoss(double _gl){
    this->percentGainOrLoss = _gl;
}
void stockType::setNumOfShares(int _shares){
    this->numOfShares = _shares;
}


//OutputFormatting Doubles - 7 spaces right adj ( xxx.xx)
std::string stockType::outputDoubleFormat(double _dbl) const {
    std::stringstream str;
    str << std::setw(7) << std::right << std::fixed << std::setprecision(2) << std::noshowpoint << _dbl;
    std::string s = str.str();
    return s;
}

//OutputFormatting Symbol - 4 spaces, left adj. (xxxx or xxx )
std::string stockType::outputSymbolFormat(std::string _sym) const {
    std::stringstream str;
    str << std::setw(4) << std::left << _sym;
    std::string s = str.str();
    return s;
}


//print out the full stock information using the extraction operator, GL balance, and begin a new line
void stockType::printStock(stockType  _stock){
    std::cout << _stock;
    _stock.printGL();
    std::cout << std::endl;
    
}

//(TodayClose - YesaterdayClose) / YesterdayClose * 100;
void stockType::printGL(){
    double GL = ((closePrice - prevClose) / prevClose * 100);
    
    std::cout << std::setprecision(2) << std::fixed << std::showpoint
    << std::setw(7) << std::right << GL << '%';
    
}

//this will read in one line from the text and fill in all data in stockType
std::istream & operator>> (std::istream &in, stockType &_stock){
     in >> _stock.symbol >> _stock.openPrice >> _stock.closePrice >>
     _stock.todayHigh >> _stock.todayLow >> _stock.prevClose
     >> _stock.numOfShares;
    
    return in;
 }

//this will print all data for the OBJECT
std::ostream& operator << (std::ostream &out, const stockType &_stock){
 
    out << _stock.outputSymbolFormat(_stock.symbol)
        << _stock.outputDoubleFormat(_stock.openPrice)
        << _stock.outputDoubleFormat(_stock.closePrice)
        << _stock.outputDoubleFormat(_stock.todayHigh)
        << _stock.outputDoubleFormat(_stock.todayLow)
        << std::setw(10) << " "
        << _stock.outputDoubleFormat(_stock.prevClose);
    
    out << std::setw(6) << std::right <<  _stock.numOfShares;
    
    return out;
 }


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//OVERLOAD RELATIONAL OPERATORS

//using 'less than' to signify being earlier in the alphabet (b < c) returns true;
bool stockType::operator <(const stockType &s){
    for (int i = 0; i < 4; i++){
        if (symbol.at(i) < s.symbol.at(i)){
            return true;
        }
        else{}
    }
    return false;
 }

//using 'greatern than' to signify being later in the alphabet (b > c) returns false;
 bool stockType::operator >(const stockType &s){
    for (int i = 0; i < 2; i++){
        if (symbol.at(i) > s.symbol.at(i)){
            return true;
        }
        else{}
    }
    return false;
 }

//check if symbols are idential
 bool stockType::operator ==(const stockType &s){
     for (int i = 0; i < 4; i++){
         if (symbol.at(i) != s.symbol.at(i)){
             return false;
         }
         else{}
     }
     return true;
 }

//check if symbols are not identical
bool stockType::operator !=(const stockType &s){
    for (int i = 0; i < 4; i++){
        if (symbol.at(i) == s.symbol.at(i)){
            return false;
        }
        else{}
    }
    return true;
}
