/*
 * Problem416.cpp
 *
 *  Created on: 2016年12月13日
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
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for( int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        // 如果sum为奇数 则一定false
        if( sum & 1 == 1) return false;

        return helper(nums, 0, sum >> 1);

    }

    // subsum的问题
    bool helper( vector<int>& nums, int start, int target) {
        if(target == 0) return true;
        for( int i = start; i < nums.size(); i++) {

            if( nums[i] <= target && (helper( nums, i ,target - nums[i]) == true)) return true;
        }

        return false;
    }
};

int main( void) {
	Solution a;
	static const int arr[] = {1,2,5};
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]) );
	a.canPartition(vec);
	return 0;

}
