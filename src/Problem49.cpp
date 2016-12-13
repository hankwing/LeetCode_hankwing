/*
 * Problem49.cpp
 *
 *  Created on: 2016Äê12ÔÂ6ÈÕ
 *      Author: hankwing
 *
 * Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
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
    vector<vector<string> > groupAnagrams(vector<string>& strs) {

        vector<int> sizes;
        vector<vector<int> > hashs;
        vector<vector<string> > results;

        int find = -1;

        for( int i = 0; i< strs.size(); i++) {
            // for every strings

            find = -1;
            for( int j = 0; j < hashs.size() && find < 0; j++) {
                // for every hashs
                if( sizes[j] == strs[i].length() ) {
                    // if length equal
                    find = j;
                	vector<int> temp(hashs[j]);
                    for( int k = 0; k < strs[i].length(); k++) {
                        if( temp[strs[i][k]] > 0) {
                        	temp[strs[i][k]] --;
                        }
                        else {
                            // not this
                            find = -1;
                            break;
                        }
                    }
                }
                else {
                    find = -1;
                }
            }

            if( find < 0) {
                // cannot find, add a new one
                vector<int> hash(256, 0);
                sizes.push_back(strs[i].length());
                for( int m = 0; m < strs[i].length(); m++) {

                    hash[strs[i][m]] ++;
                }
                hashs.push_back(hash);
                vector<string> addStrings;
                addStrings.push_back(strs[i]);
                results.push_back(addStrings);
            }
            else {
                // find ,add to vector
                results[find].push_back(strs[i]);
            }
        }

        return results;


    }
};


int main49() {
	vector<string> input;
	input.push_back("ate");
	input.push_back("eat");
	input.push_back("tea");
	input.push_back("nat");
	input.push_back("tan");
	input.push_back("bat");

	Solution a;
	vector<vector<string> > results = a.groupAnagrams(input);

	for( int i = 0; i < results.size(); i++) {
		for( int j = 0; j < results[i].size(); j++) {
			cout << results[i][j] << " ";
		}
		cout << endl;
	}
}

