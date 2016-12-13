/*
 * Problem365.cpp
 *
 *  Created on: 2016Äê11ÔÂ27ÈÕ
 *      Author: hankwing
 */

#include<stdio.h>

using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
    	if( x + y < z) {
    		return false;
    	}
    	else if( x + y == z) {
    		return true;
    	}
    	else return z % GCD(x , y);
    }

    int GCD( int x, int y) {
    	int temp = 0;
    	while( y != 0) {
    		temp = y;
    		y = x % y;
    		x = temp;
    	}
    	return x;
    }
};

