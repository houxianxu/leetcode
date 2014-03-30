// http://oj.leetcode.com/problems/linked-list-cycle-ii/

// Solve the problem without using extra space!
#include <stdio.h>

struct ListNode {
  int val;
  ListNode *next;
  // ListNode(int x) : val(x), next(NULL) {}
};


// determine whether the list has cycle and return the lenght of cycle, 0 for none.
int is_cycle_len(ListNode *head) {
	if (head == NULL) {
		return 0;
	} else {
		ListNode *slowP = head;
		ListNode *fastP = head;

		while(fastP != NULL && fastP->next != NULL) {
			slowP = slowP->next;
			fastP = fastP->next->next;
			if (slowP == fastP) {
				break;
			}
		}

		// no cycle
		if (fastP == NULL || fastP->next == NULL) {
			return 0;
		} else { // has cycle
			int cycle_len = 1;
			slowP = slowP->next;
			while(slowP != fastP) {
				cycle_len += 1;
				slowP = slowP->next;
			}

			return cycle_len;
		}
	}
}


ListNode *findP(ListNode *head , int cycle_len) { // assume has cycle
	if (head == NULL) {
		return NULL;
	} else {
		ListNode *slowP = head;
		ListNode *fastP = head;
		while(cycle_len > 0) {
			fastP = fastP->next;
			cycle_len -= 1;
		}
		while (slowP != fastP) {
			slowP = slowP->next;
			fastP = fastP->next;
		}

		return slowP;
	}
}
ListNode *detectCycleC(ListNode *head) {

	if (head == NULL) {
		return NULL;
	} else {
		int cycle_len = is_cycle_len(head);

		if (cycle_len > 0) {
			return findP(head, cycle_len);
		} else {
			return NULL;
		}
	}
}

ListNode *c_solution(ListNode *head) {
	return detectCycleC(head);
}

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    return c_solution(head);
  }
};

int main(int argc, char const *argv[])
{
	/* code */
	ListNode n1, n2;
	n1.val = 1; 
	n1.next = &n2;
	n2.val = 2;
	n2.next = &n1;
	printf("%d\n", c_solution(&n1));
	return 0;
}

