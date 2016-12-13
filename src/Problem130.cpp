/*Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.*/

#include <stdlib.h>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char> >& board) {

    	if( board.size() == 0) {
    		return;
    	}
    	int i,j;
    	int row = board.size(), col = board[0].size();

    	for( i = 0; i < row; i++) {
    		if( i == 0 || i == row -1) {
    			for( j = 0; j < col; j++) {
    				check(board, i, j, row, col);
    			}
    		}
    		else {
    			check(board, i, 0, row, col);
    			check(board, i, col - 1, row, col);
    		}
    	}

    	for( i = 0; i < row; i++) {
    		for( j = 0; j < col; j++) {
    			if( board[i][j] == 'O') {
    				board[i][j] = 'X';
    			}
    			else if(board[i][j] == '1') {
    				board[i][j] = 'O';
    			}
    		}
    	}
    }

    void check(vector<vector<char> >&vec,int i,int j,int row,int col){
		if(vec[i][j]=='O'){
			vec[i][j]='1';
			if(i>1)
				check(vec,i-1,j,row,col);
			if(j>1)
				check(vec,i,j-1,row,col);
			if(i+1<row)
				check(vec,i+1,j,row,col);
			if(j+1<col)
				check(vec,i,j+1,row,col);
		}
	}


};
