/*
 * Problem307.cpp
 *
 *  Created on: 2016Äê12ÔÂ8ÈÕ
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
#include <limits.h>

using namespace std;

class NumArray {
public:

    vector<int> *thisnums;
    vector<int> *BITs;
    int number = 0;

    NumArray(vector<int> &nums) {
    	thisnums = &nums;
        number = nums.size();
        BITs = new vector<int>(nums.size() + 1, 0);
        for( int i = 0; i < nums.size(); i++) {
            init(i, nums[i]);
        }

    }

    void init( int i, int nums) {
        i++;
        while( i<= number) {

            (*BITs)[i] += nums;
            i += (i & -i);
        }
    }

    void update(int i, int val) {
        int diff = val - (*thisnums)[i];
        (*thisnums)[i] = diff;
        init(i, diff);
    }

    int getSum(int i) {
		int sum = 0;
		i++;
		while (i > 0) {
			sum += (*BITs)[i];
			i -= (i & -i);
		}
		return sum;
	}

	int sumRange(int i, int j) {
		return getSum(j) - getSum(i - 1);
	}
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
