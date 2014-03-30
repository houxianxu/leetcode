#include <stdio.h>
// http://oj.leetcode.com/problems/insertion-sort-list/


// Definition for singly-linked list.
// Struct定义需要在提交的时候注释掉
struct ListNode {
  int val;
  ListNode *next;
  // ListNode(int x) : val(x), next(NULL) {}
};

void printNodeList(ListNode *listHead) {
	while(listHead != NULL) {
		printf("%d", listHead->val);
		listHead = listHead->next;
	}
	printf("\n");
}

ListNode *insertToSortedList(ListNode *sortedListHead, ListNode *node){ // assume sortedListHead is sorted and node->next = NULL
	ListNode *resHead;
	// printf("%s\n", "sortedListHead");
	// printNodeList(sortedListHead);
	// printf("%s\n", "node");
	// printNodeList(node);
	if (node == NULL) {
		resHead = sortedListHead;
	} else {
		// printf("%s\n", "d");
		if (node->val <= sortedListHead->val){
			// printf("%s\n", "d");
			node->next = sortedListHead;
			resHead = node;
		} else{
			ListNode *pre = sortedListHead;
			ListNode *pnext = sortedListHead->next;
			while(pnext != NULL && node->val > pnext->val){
				pre = pre->next;
				pnext = pnext->next;
			}
			// printf("%s\n", "d");

			// insert between pre and pnext
			pre->next = node;
			node->next = pnext;
			resHead = sortedListHead;
		}
	}
	return resHead;
}
ListNode *c_solution(ListNode *head) {
	// c code here
	ListNode *resHead;
	if(head == NULL || head->next == NULL){
		resHead = head;
	} else {
		resHead = head;
		head = head->next; // be careful about the order!
		resHead->next = NULL;
		while(head != NULL) {
			// printf("%s\n", "dd");
			ListNode *tempInsertNode = head;
			head = head->next;
			tempInsertNode->next = NULL;
			resHead = insertToSortedList(resHead, tempInsertNode);
			// printNodeList(resHead);
		}
	}
	return resHead;

}




class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
      return c_solution(head);
    }
};



int main(int argc, char const *argv[])
{
	/* code */
	ListNode node1, node2, node3, *res;
	node1.val = 3;
	node2.val = 2;
	node3.val = 4;
	node1.next = &node2;
	node2.next = &node3;
	node3.next = NULL;
	// printNodeList(&node1);
	res = c_solution(&node1);
	// printf("%d\n", res->next->val);
	printNodeList(res);
	return 0;
}