/*
 * Problem34.cpp
 *
 *  Created on: 2016Äê12ÔÂ15ÈÕ
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
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> result;
        int start = 0;
        int lo = 0, hi = nums.size();
        while( lo < hi) {
            start = lo;
            int mid = (lo + hi) >> 1;
            if( target < nums[mid]) hi = mid;
            else {

                lo = mid + 1;
            }
        }

        int end = lo - 1 < 0? 0: lo -1;

        if( nums[end] != target) {
            // not found
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        else {
            while( start < result.size() && nums[start] < target) {
            	start ++;
            }
            result.push_back(start);
            result.push_back(end);
        }

        return result;

    }
};

int main34() {
	Solution a;
	vector<int> input;
	input.push_back(1);
	input.push_back(4);
	a.searchRange(input , 4);
	return 0;
}
