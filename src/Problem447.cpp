/*
 * Problem447.cpp
 *
 *  Created on: 2016Äê11ÔÂ24ÈÕ
 *      Author: hankwing
 */

#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
    /*int numberOfBoomerangs(vector<pair<int, int>>& points) {
    	 <int, int> hmap;
    	int i, j = 0;
    	int number = 0;
    	for( i = 0; i < points.size() ; i++) {

    		for( j = 0; j < points.size(); j++) {
    			if( i == j) {
    				continue;
    			}

    			int distance = getDistance(points[i], points[j]);
    			hmap[distance] ++;

    		}

    	}
    }*/

    int getDistance( pair<int,int> x, pair<int, int> y) {
    	return (x.first - y.first) * (x.first - y.first)
    			+ (x.second - y.second) * (x.second - y.second);
    }
};


