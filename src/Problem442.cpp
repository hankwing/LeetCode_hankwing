/*
 * Problem442.cpp
 *
 *  Created on: 2016Äê12ÔÂ11ÈÕ
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
    vector<int> findDuplicates(vector<int>& nums) {
        set<int> results;
        int val = 0;
        for(int i = 1; i <= nums.size(); i++) {
            val = nums[i - 1];
            while( i != val && nums[val - 1] != val) {
                int temp = val;
                val = nums[val - 1];
                nums[temp - 1] = temp;

            }
            nums[i - 1] = val;

            if( i != val) results.insert(val);
        }

        vector<int> result( results.begin(), results.end());

        return result;
    }
};

int main422() {
	Solution a;
	int inputVal[] = {2,1};
	vector<int> input( inputVal, inputVal+2);
	a.findDuplicates(input);
}
