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
#include <bitset>

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
        bitset<5001> bits(1);
		for (int i = 0; i < nums.size(); i++) bits |= bits << nums[i];
		return !(sum & 1) && bits[sum >> 1];

    }
};

int main( void) {
	Solution a;
	static const int arr[] = {1,1};
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]) );
	a.canPartition(vec);
	return 0;

}
