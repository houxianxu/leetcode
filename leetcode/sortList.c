// http://oj.leetcode.com/problems/sort-list/

// struct定义需要在提交的时候注释掉

#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode {
  int val;
  struct ListNode *next;
  // ListNode(int x) : val(x), next(NULL) {}
} ListNode;




void printNodeList(ListNode *listHead) {
	while(listHead != NULL) {
		printf("%d", listHead->val);
		listHead = listHead->next;
	}
	printf("\n");
}


ListNode *mergeSortedList(ListNode *left, ListNode *right) {
	ListNode *resHead;
	// printf("%s\n", "left");
	// printNodeList(left);
	// printf("%s\n", "right");
	// printNodeList(right);
	if (left == NULL) {
		resHead = right;
	} else if(right == NULL) {
		resHead = left;
	} else {
		if(left->val <= right->val) {
			resHead = left;
			left = left->next;
		} else{
			resHead = right;
			right = right->next;
		}

		ListNode *pNext = resHead;
		while (left != NULL && right != NULL) {
			if(left->val <= right->val) {
				pNext->next = left;
				left = left->next;
			} else{
				pNext->next = right;
				right = right->next;
			}
			pNext = pNext->next;
		}

		if(left == NULL) {
			pNext->next = right;
		}

		if(right == NULL) {
			pNext->next = left;
		}
	}
	return resHead;
}

ListNode *ListMergeSort(ListNode *head) {
	ListNode *resHead;
 	if(head == NULL || head->next == NULL) {
 		resHead = head;
 	} else {
 		// use fast and slow pointer to find the middle pointer
 		// fast -> step 2   slow -> step 1
 		// the idea is from web.
 		ListNode *fast, *slow;
 		fast = head;
 		slow = head;
 		while (fast->next != NULL && fast->next->next != NULL) {
 			fast = fast->next->next;
 			slow = slow->next;
 		}
 		// *(slow->next) is the right half
 		ListNode *right = slow->next;
 		slow->next = NULL;
 		ListNode *left = head;


 		resHead = mergeSortedList(ListMergeSort(left), ListMergeSort(right));
 		
 	}
 	return resHead;
}

ListNode *c_solution(ListNode *head) {
 	// c code here
 	return ListMergeSort(head);
}

class Solution {
 public:
  ListNode *sortList(ListNode *head) {
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
	printNodeList(&node1);
	res = c_solution(&node1);
	printf("%d\n", res->next->val);
	printNodeList(res);

	// ListNode node1, node2, node3, *res;
	// node1.val = 2;
	// node2.val = 5;
	// node1.next = &node2;
	// node2.next = NULL;

	// node3.val = 6;
	// node3.next = NULL;

	// printNodeList(mergeSortedList(&node1, &node3));
		return 0;
}