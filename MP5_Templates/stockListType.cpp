//
//  stockListType.cpp
//  MP5_Templates
//
//  Created by Ayesha Mutiara on 11/1/18.
//  Copyright © 2018 Daniel Braunstein. All rights reserved.
//

#include "stockListType.hpp"

//add another element to end of vector
template <class T>
void stockListType<T>::push (T const& _stock) {
    stockList.push_back(_stock);
}
