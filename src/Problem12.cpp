/*
 * Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
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

    string intToRoman(int num) {
        int digits[] = {0, 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string romans[] = {"", "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int i;
        stringstream ss;
        while( num != 0) {
            i = 0;
            while( num >= digits[i]) {
                i++;
            }
            i--;
            ss << romans[i];
            num -= digits[i];
        }

        return ss.str();
    }
};


int main12() {
	Solution a;
	a.intToRoman(1000);
	return 0;
}
