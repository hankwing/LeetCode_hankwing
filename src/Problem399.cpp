/*
 * Problem399.cpp
 *
 *  Created on: 2016年12月18日
 *      Author: hankwing
 * Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0.
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.
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
#include <unordered_map>

using namespace std;

class Solution {
public:

    vector<double> calcEquation(vector<pair<string, string> > equations, vector<double>& values, vector<pair<string, string> > queries) {
        unordered_map< string, unordered_map<string, double> > map;
        unordered_map<string, string> groups;
        vector<double> results;

        // construct graph and groups
        for( int i = 0; i < equations.size(); i++) {
            string from = equations[i].first;
            string to = equations[i].second;
            double value = values[i];

            map[from][to] = value;
            map[from][from] = 1;
            map[to][to] = 1;
            if( value != 0) map[to][from] = 1/ value;
            Union( map, groups, from, to, value);

        }

        for( auto query : queries) {
            string from = query.first;
            string to = query.second;

            if( groups.count(from) == 0 || groups.count(to) == 0) results.push_back(-1.0);
            if( from.compare(to) == 0) results.push_back(1.0);
            else results.push_back(findValue( map, groups, from, to));
        }

        return results;
    }

    void Union( unordered_map< string, unordered_map<string, double> >& map, unordered_map<string, string>& groups, string from, string to, double value) {
        string fromP = findParent( map, groups, from);
        string toP = findParent( map, groups, to);
        double valueP = value * map[fromP][from] * map[to][toP];
        map[fromP][toP] = valueP;
        if(valueP != 0) map[toP][fromP] = 1 / valueP;
        if( fromP.compare(toP) != 0) groups[fromP] = toP;
    }

    double findValue(unordered_map< string, unordered_map<string, double> >& map, unordered_map<string, string>& groups, string from, string to) {
        string fromP = findParent( map, groups, from);
        string toP = findParent( map, groups, to);
        if( fromP.compare(toP) == 0) return map[from][fromP] * map[fromP][to];
        else return -1.0;
    }


    string findParent( unordered_map< string, unordered_map<string, double> >& map, unordered_map<string, string>& groups, string from) {
          // inital parent
        if(groups.count(from) == 0) {
            groups[from] = from;
            return from;
        }
        string parent = groups[from];

        while( groups[parent].compare(parent) != 0) {

            groups[from] = groups[parent];
            double tempValue = map[from][parent] * map[parent][groups[parent]];
            map[from][groups[parent]] = tempValue;// 更新值
            if( tempValue != 0) map[groups[parent]][from] = 1 / tempValue;
            from = parent;
            parent = groups[parent];
        }
        return parent;
    }


};


int main399() {
	Solution a;
	vector<pair<string, string> > equations;
	vector<double> values;
	vector<pair<string, string> > queries;

	equations.push_back(make_pair("a","b"));
	equations.push_back(make_pair("b","c"));

	values.push_back(2.0);
	values.push_back(3.0);
	queries.push_back(make_pair("a","c"));
	//a.searchRange(input , 4);
	a.calcEquation(equations, values, queries);
	return 0;
}
