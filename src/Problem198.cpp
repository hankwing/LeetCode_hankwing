/*
 * Problem198.cpp
 *
 *  Created on: 2016Äê11ÔÂ29ÈÕ
 *      Author: hankwing
 *
 *      You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 */



#include <stdlib.h>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

    	int presNo = 0, presYes = nums[0], size = nums.size(), i = 1;
    	while( i ++ < size) {
    		int temp = presNo;
    		presNo = max( presNo, presYes);
    		presYes = temp + nums[i];
    	}

    	return max(presNo, presYes);
    }

};
