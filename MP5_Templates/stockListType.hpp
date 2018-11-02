//
//  stockListType.hpp
//  MP5_Templates
//
//  Created by Ayesha Mutiara on 11/1/18.
//  Copyright © 2018 Daniel Braunstein. All rights reserved.
//

#ifndef stockListType_hpp
#define stockListType_hpp

#include <stdio.h>
#include <vector>
#include "stockType.hpp"

template <class T>
class stockListType {
public:
    std::vector<T> stockList;
    
    void push(T const&);
    
};


#endif /* stockListType_hpp */
