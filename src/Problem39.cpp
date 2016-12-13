/*Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7*/

#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    	quickSort(candidates, 0, candidates.size());
    	vector< vector<int> > results;
    	vector<int> singleResult;
    	getResult( candidates, results, singleResult, target, 0);
    	return results;
    }

    void getResult( vector<int>& candidates, vector<vector<int> >& results
    		, vector<int>& singleResult, int target, int start) {

    	for( int i = start; i < candidates.size() && (target - candidates[i]) >= 0; i++) {
    		int temp = target - candidates[i];
    		singleResult.push_back(candidates[i]);
    		temp == 0? results.push_back(singleResult) :
    				getResult(candidates, results, singleResult, temp, i);
    		singleResult.pop_back();
    	}
    }


    int partition( vector<int>& candidates, int start, int end) {
    	int mid = candidates[start];
    	while( start < end) {
    		while(start < end && candidates[end] >= mid) {
    			end --;
    		}

    		candidates[start] = candidates[end];

    		while( start < end && candidates[start] <= mid) {
    			start ++;
    		}

    		candidates[end] = candidates[start];
    	}
    	candidates[start] = mid;
    	return start;
    }

    void quickSort( vector<int>& candidates, int start, int end) {

    	if( start > end - 2) {
    		return ;
    	}
    	int mid = partition(candidates, start, end - 1);
    	quickSort(candidates, start, mid);
    	quickSort(candidates, mid+1, end);

    }


};



int main39() {
	Solution a;
	static const int arr[] = {2, 3, 6, 7};
	vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
	vector<vector<int> > results = a.combinationSum(vec, 7);
	for( vector<vector<int> >::iterator it = results.begin() ; it != results.end(); it++) {
		for( vector<int>::iterator itit = (*it).begin() ; itit != (*it).end(); itit++) {
			cout << " " << *itit;
		}
		cout << endl;
	}
	return 0;
}

