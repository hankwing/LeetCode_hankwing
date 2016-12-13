/*
 * Problem213.cpp
 *
 *  Created on: 2016Äê11ÔÂ30ÈÕ
 *      Author: hankwing
 *
 *  After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

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
        if(nums.size() == 0) {
            return 0;
        }
        int firstYes_prevYes = nums[0], firstYes_prevNo = nums[0], firstNo_prevYes = 0, firstNo_prevNo = 0, size = nums.size();
        for( int i = 1; i < size - 1; i++) {
            if( i == 1) {
                int temp = firstNo_prevNo;
                firstNo_prevNo = max( firstNo_prevNo, firstNo_prevYes);
                firstNo_prevYes = temp + nums[i];
            }
            else {
                int temp = firstNo_prevNo;
                firstNo_prevNo = max( firstNo_prevNo, firstNo_prevYes);
                firstNo_prevYes = temp + nums[i];

                temp = firstYes_prevNo;
                firstYes_prevNo = max( firstYes_prevNo, firstYes_prevYes);
                firstYes_prevYes = temp + nums[i];
            }
        }

        int case1 = max( firstYes_prevNo, firstYes_prevYes);
        int case2 = max(firstNo_prevNo, firstNo_prevYes);
        int case3 =  firstNo_prevNo + nums[size -1];

        case1 = max(case1, case2);
        case1 = max(case1, case3);
        return case1;
    }
};
