/*
 * Problem8.cpp
 *
 *  Created on: 2016Äê11ÔÂ30ÈÕ
 *      Author: hankwing
 */

#include <stdlib.h>
#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <limits.h>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int i = 0, stackSize = 0;
		bool isPositive = true;
		unsigned long long result = 0;
		while (i < str.length() && str[i] == ' ') {
			i++;
		}

		switch (str[i]) {
		case '-':
			i++;
			isPositive = false;
			break;
		case '+':
			i++;
			break;
		}

		for (; i < str.length(); i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				result = result * 10 + str[i] - 48;
			} else {
				break;
			}
		}

		//if (result < 0)
		//	return isPositive ? INT_MAX : INT_MIN;
		result = isPositive ? result : -result;

		if (result > INT_MAX)
			return INT_MAX;
		if (result < INT_MIN)
			return INT_MIN;

		return result;
	}
};

int main8() {
	Solution a;
	int result = a.myAtoi("18446744073709551617");
	cout << "result " << result << endl;
	return 0;
}
