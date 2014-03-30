// http://oj.leetcode.com/problems/copy-list-with-random-pointer/
// the idea is to copy every node and add them just after the origin,
// then 


#include <stdio.h>
#include <stdlib.h>

  // Definition for singly-linked list with a random pointer.
typedef struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  // RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
} RandomListNode;


void copy_add(RandomListNode *head) {
	if (head != NULL) {
		RandomListNode *newNode = (RandomListNode *) malloc(sizeof(RandomListNode));
		*newNode = *head;
		head->next = newNode;
		copy_add(head->next->next);
	}
}

void change_newNode_random(RandomListNode *head) {
	if (head != NULL && head->next != NULL) {
		if (head->next->random != NULL) {
			head->next->random = head->next->random->next;
		}
		change_newNode_random(head->next->next);
	}
}

RandomListNode *restore_origin_get_copy(RandomListNode *head){
	if (head != NULL && head->next != NULL){
		RandomListNode *newHead;
		newHead = head->next;
		head->next = head->next->next;
		newHead->next = restore_origin_get_copy(head->next);

		return newHead;
	}
}


RandomListNode *copyRandomListC(RandomListNode *head) {
	if (head == NULL) {
		return NULL;
	} else {
		// copy every node and add after origin, just change the head no return 
		copy_add(head);
		// printf("%s\n", "11");
		// change new added node's random pointer to the right place, no return 
		change_newNode_random(head);
		// printf("%s\n", "22");
		// restore the origin, and return the new one
		return restore_origin_get_copy(head);
	}
}


RandomListNode *c_solution(RandomListNode *head) {
	return copyRandomListC(head);
}

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
      return c_solution(head);
    }
};

int main(int argc, char const *argv[])
{
	RandomListNode n1, n2, n3, n4;
	n1.label = 1;
	n1.next = &n2;
	n1.random = NULL;

	n2.label = 2;
	n2.next = &n3;
	n2.random = &n1;

	n3.label = 3;
	n3.next = &n4;
	n3.random = &n2;

	n4.label = 4;
	n4.next = NULL;
	n4.random = &n3;



	printf("%d\n", c_solution(&n1)->next->next->random->label);
	return 0;
}