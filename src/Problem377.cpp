/*
 * Problem377.cpp
 *
 *  Created on: 2016Äê12ÔÂ12ÈÕ
 *      Author: hankwing
 */

#include <stdlib.h>
#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
#include <set>
#include <limits.h>

using namespace std;


class Solution {
public:
    vector<int> a;
    int combinationSum4(vector<int>& nums, int target) {
        a.resize(target + 1, -1);
        a[0] = 0;
        return getResult( nums, target);
    }

    int getResult( vector<int> nums, int target) {

        if( a[target] != -1) return a[target];
        int res = 0;
        for( int i = 0; i < nums.size(); i++) {

            if( nums[i] <= target) {
                res += getResult( nums, target - nums[i]);
            }

        }

        a[target] = res;
        return res;
    }
};

int main377() {
	Solution a;
	int inputVal[] = {1,2,3};
	vector<int> input( inputVal, inputVal+3);
	a.combinationSum4(input, 4);
}
