/*
 * Problem147.cpp
 *
 *  Created on: 2016Äê12ÔÂ20ÈÕ
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
#include <bitset>
#include <unordered_map>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if( !head) return head;
        ListNode* dummy = new ListNode(0);
        ListNode* insert, *temp;
        dummy->next = head;
        head = head->next;
        while( head ) {
            insert = dummy;
            temp = head;
            head = head->next;
            while( insert->next && insert->next->val <= temp->val) {
                insert = insert->next;
            }

            temp->next = insert->next;
            insert->next = temp;
        }

        return dummy->next;
    }
};

int main() {
	Solution a;
	ListNode * head = new ListNode(1);
	ListNode * second = new ListNode(1);
	head->next = second;
	//a.searchRange(input , 4);
	a.insertionSortList(head);
	return 0;
}
