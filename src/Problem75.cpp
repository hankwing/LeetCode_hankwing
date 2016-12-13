/*
 * Problem75.cpp
 *
 *  Created on: 2016Äê11ÔÂ29ÈÕ
 *      Author: hankwing
 *
 *      Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
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
    void sortColors(vector<int>& nums) {

    	int lo = 0, hi = nums.size() -1, i = lo;

    	while( i < hi +1) {
    		switch( nums[i]) {
    		case 0:
    			swap(nums[lo ++], nums[i]);
    			i = i > lo? i: lo;
    			break;
    		case 1:
    			i++;
    			break;
    		case 2:
    			swap(nums[hi --], nums[i]);
    			break;
    		}
    	}

    }
};

int main75( void) {
	Solution a;
	static const int arr[] = {2};
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]) );
	a.sortColors(vec);
	for( vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout <<*it << endl;
	}
	return 0;

}

