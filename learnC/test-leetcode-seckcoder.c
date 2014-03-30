











#include <stdio.h>

int foo() {
  int c = 1;
  {
    int c = c;
    printf("%d\n",c);
  }
  return c;
}

#define M 1000

void reverse(char *s) {
  char ret[M];
  int num;
  split(s, ret, &num);
  reverse(ret, num);
  concat(ret, num);
}


int eval_rec(char input[], int len, int *p_rest_len) {
  if (len == 0) {
    ...
  } else {
    char *top = input[len-1];
    if (is_op(top)) {
      int v1_rest_len;
      int v1 = eval_rec(input, len-1, &v1_rest_len);
      int v2_rest_len;
      int v2 = eval_rec(input, v1_rest_len, &v2_rest_len);
      *p_rest_len = v2_rest_len;
      return eval_op(top, v1, v2);
    } else {
      *p_rest_len = len-1;
      return to_int(top);
    }
  }
}

int eval(char input[], int len) {
  int rest_len;
  return eval_rec(input, len, &rest_len);
}


ListNode *sort_list(ListNode* head) {
  if (head == NULL) {
    // ...
  } else {
    ListNode *middle = get_middle(head);
    ListNode *tmp = middle->next;
    middle->next = NULL;
    ListNode *head1 = sort_list(head);
    ListNode *head2 = sort_list(tmp);
    return merge(head1, head2);
  }
}

ListNode *merge(ListNode *h1, ListNode *h2) {
  if (h1 == NULL) {
    return h2;
  } else if (h2 == NULL) {
    return h1;
  } else if (h1->val < h2->val) {
    ListNode *h1_next = merge(h1->next, h2);
    h1->next = h1_next;
    return h1;
  } else {
    ListNode *h2_next = merge(h1, h2->next);
    h2->next = h2_next;
    return h2;
  }
}

ListNode *get_middle(ListNode *h1) {
  if (h1 == NULL) {
    return NULL;
  } else {
    int len = get_length(h1);
    for(int i = 0; i < len/2; i++) {
      h1 = h1->next;
    }
    return h1;
  }
}

struct Result {
  int *arr;
  int start;
  int *pnum;
};

Result post_trav_rec(TreeNode *root, Result input) {
  if (root == NULL) {
    // ...
  } else {
    int left_num=0;
    Result left_res = post_trav_rec(root->left, input)h;
    int right_num=0;
    // update left_res
    post_trav_rec(root->right, ...)
    arr[start+left_num+right_num] = root->val;
    *pnum = left_num + right_num;
  }
}

void post_trav(TreeNode *root, int **parr, int *pnum) {
  *parr = (int*)malloc(M*sizeof(int));
  *pnum = 0;
  post_trav_rec(root, *parr, 0, pnum);
  free(*parr);
}


int main(int argc, const char *argv[]) {
  foo();
  return 0;
}
