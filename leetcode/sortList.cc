// http://oj.leetcode.com/problems/sort-list/

// struct定义需要在提交的时候注释掉

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


ListNode *c_solution(ListNode *head) {
  if (head == NULL) {
  	return head;
  } else if(head->next == NULL) {
  	return head;
  } else {
  	
  }
}

class Solution {
 public:
  ListNode *sortList(ListNode *head) {
    return c_solution(head);
  }
};