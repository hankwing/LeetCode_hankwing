#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;

/**
 * ÊµÏÖ³ý·¨
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
    	if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
			return INT_MAX;

		int result = 0, tempDividend, tempDivisor;
		if( dividend > 0) {
			tempDividend = dividend;
		}
		else {
			tempDividend = -dividend;
		}


		while( tempDividend >= tempDivisor) {
			tempDividend -= tempDivisor;
			result ++;

		}
		return dividend * divisor ? result: -result;

    }

};

int main29() {
	Solution a;
	printf("%d", a.divide(-2147483648,-1));
	return 0;
}
