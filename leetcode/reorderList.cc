// http://oj.leetcode.com/problems/reorder-list/
#include <stdio.h>
struct ListNode {
  int val;
  ListNode *next;
  // ListNode(int x) : val(x), next(NULL) {}
};

// 	#define N 10000


// ListNode *getLastNode(ListNode *head) {

// 	if (head == NULL || head->next == NULL) {
// 		return head;
// 	} else {
// 		return getLastNode(head->next);
// 	}

// }

// ListNode *getLastTwoNode(ListNode *head) { // assuming there is at least two node
// 	if (head->next->next == NULL ) {
// 		return head;
// 	} else {
// 		return getLastTwoNode(head->next);
// 	}
// }


void reorderListC_N(ListNode *p[], int N) {
	if (N >= 3) {
		ListNode *lastNode, *lastTwoNode, *newHead;
		newHead = p[0]->next;
		lastNode = p[N - 1];
		lastTwoNode = p[N - 2];
		p[0]->next = lastNode;
		lastTwoNode->next = NULL;
		lastNode->next = newHead;

		reorderListC_N(&newHead, N - 2);
	}

}

void reorderListC(ListNode *head) {
	if (head == NULL || head->next == NULL || head->next->next == NULL) {
		;
	} else {
		ListNode *tmpHead = head;
		int N = 0;
		int i = 0;
		while (tmpHead != NULL) {
			N += 1;
			tmpHead = tmpHead->next;
		}

		tmpHead = head;
		ListNode *p_all_nodes[N];
		for (i = 0; i < N; i++) {
			p_all_nodes[i] = tmpHead;
			tmpHead = tmpHead->next;
		}

		reorderListC_N(p_all_nodes, N);
	}
}


void c_solution(ListNode *head) {
	reorderListC(head);
}

class Solution {
 public:
  void reorderList(ListNode *head) {
    c_solution(head);
  }
};

int main(int argc, char const *argv[])
{
	ListNode node1, node2, node3, node4;
	node1.val = 1;
	node2.val = 2;
	node3.val = 3;
	node4.val = 4;
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = NULL;


	// printf("%d\n", getLastTwoNode(&node1)->val);
	// printf("%d\n", getLastNode(&node1)->val);
    c_solution(&node1);
    printf("%d\n", node1.next->next->val);
    // printf("n\n");
	return 0;
}