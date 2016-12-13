/*
 * Problem81.cpp
 *
 *  Created on: 2016年12月11日
 *      Author: hankwing
 *
*  Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
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
#include <limits.h>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {

        int number = nums.size();
        int start = 0, end = number - 1;
        int realEnd = 0;

        while( end != start && nums[end] == nums[start]) end--;
        realEnd = end;

        // find the smallest value index
        while( start < end) {
            if( nums[start] < nums[end] ) break;
            int mid = (start + end) >> 1;
            if( nums[mid] > nums[end]) start = mid + 1;
            else end = mid;

        }

        // start代表了最小元素的位置
        int rot = start;
        start = 0;
        end = realEnd;
        number = realEnd + 1;

        while( start <= end) {
            int mid = ( start + end) >> 1;
            int readMid = (mid + rot) % number;

            if( nums[readMid] == target) return true;
            else if( nums[readMid] > target) end = mid - 1;
            else start = mid + 1;


        }

        return false;
    }
};


int main81() {
	Solution a;
	int inputVal[] = {1,2,3,0,1,1};
	vector<int> input( inputVal, inputVal+5);
	a.search(input, 3);
}
