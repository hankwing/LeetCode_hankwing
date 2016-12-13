/*
 * Problem388.cpp
 *
 *  Created on: 2016Äê12ÔÂ4ÈÕ
 *      Author: hankwing
 *
 * Suppose we abstract our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.

Note:
The name of a file contains at least a . and an extension.
The name of a directory or sub-directory will not contain a ..
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
/*class Solution {
public:
    int lengthLongestPath(string input) {
    	int maxLength = 0;
    	stack<int> lengthStack;
    	lengthStack.push(0);	// dummy value
    	vector<string> splitString = split( input, '\n');

    	for(auto itor = splitString.begin(); itor < splitString.end(); itor++) {
    		int lev = (*itor).find_last_of('\t') + 1;
    		while( lev < lengthStack.size() - 1) lengthStack.pop();
    		int length = lengthStack.top() + (*itor).length() - lev + 1;
    		lengthStack.push(length);
    		if( (*itor).find('.') != -1) maxLength = max(maxLength, length - 1);

    	}

    	return maxLength;
    }

    vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, elems);
        return elems;
    }

    void split(const std::string &s, char delim, std::vector<std::string> &elems) {
        stringstream ss;
        ss.str(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
    }
};*/


