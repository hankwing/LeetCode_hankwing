/*Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".*/

#include <stdlib.h>
#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
    	trimBlank(s);
    	reverse(s.begin(), s.end());

    	int wStart = 0, wEnd = 0, count = 0;
    	while( count < s.length()) {

    		wStart = wEnd;
    		while( wStart < s.length() && s[wStart] == ' ') {
    			wStart ++;
    			count ++;
    		}

    		wEnd = wStart;
    		while( wEnd < s.length() && s[wEnd] != ' ') {
    			wEnd ++;
    			count ++;
    		}

    		reverse( s.begin() + wStart, s.begin() + wEnd);

    	}


    }

    void trimBlank( string &s) {
    	int start = 0, end = 0;
    	while( start < s.length() && s[start] == ' ') {
    		start ++;
    	}
    	s = s.substr(start);

    	end = s.length();
    	while( end > 0 && s[end - 1] == ' ') {
    		end --;
    	}

    	if( end > 0) {
    		s = s.substr(0, end);
    	}

    	for (int i = 0; i < s.size(); i ++)
		{
		  while (s[i] == ' ' && s[i + 1] == ' ')
		  {
			  s.erase(i, 1);
		  }
		}
    }
};

int main151() {
	Solution solution;
	string args = " 123 456  7 89 ";
	solution.reverseWords(args);
	cout << args << endl;
}
