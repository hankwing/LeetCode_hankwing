/*
 * Problem148.cpp
 *
 *  Created on: 2016Äê12ÔÂ1ÈÕ
 *      Author: hankwing
 *
 *      Sort a linked list in O(n log n) time using constant space complexity.
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

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		ListNode* prev, *mid = head, *end = head;
		while (end != NULL && end->next != NULL) {
			prev = mid;
			mid = prev->next;
			end = end->next->next;
		}

		prev->next = NULL;

		ListNode * l1 = sortList(head);
		ListNode * l2 = sortList(mid);

		return merge(l1, l2);

	}

	ListNode * merge(ListNode* first, ListNode* second) {

		ListNode * newList = new ListNode(0), *p = newList;
		while (first != NULL && second != NULL) {
			if (first->val <= second->val) {
				p->next = first;
				first = first->next;
			} else {
				p->next = second;
				second = second->next;
			}
			p = p->next;
		}

		if (first != NULL) {
			p->next = first;
		}
		if( second != NULL){
			p->next = second;
		}

		return newList->next;

	}
};

int main148() {

	int values[] = {2,1};
	ListNode* head = NULL, *lastNode;
	for( int i = 0; i < 2; i++) {

		ListNode* value = new ListNode(values[i]);
		if(head ==NULL) {
			head = value;
			lastNode = head;
		}
		else {
			lastNode ->next = value;
			lastNode = value;
		}
	}

	Solution a;
	ListNode * result = a.sortList(head);

	while( result != NULL) {
		cout << result->val << " ";
		result = result->next;
	}


}

