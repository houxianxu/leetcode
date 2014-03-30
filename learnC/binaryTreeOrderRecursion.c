// Pre-order In-order Post-order Traversal using recursion
#include <stdio.h>

/* Definition for binary tree */

typedef struct TreeNode {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

// pre_order traversal
void pre_order(TreeNode *root) {
	if(root != NULL) {
		printf("%d\n", root->data);
		pre_order(root->left);
		pre_order(root->right);
	}
}

// post_order
void post_order(TreeNode *root) {
	if(root != NULL) {
		post_order(root->left);
		post_order(root->right);
		printf("%d\n", root->data);
	}
}

// in_order
void in_order(TreeNode *root) {
	if(root != NULL) {
		in_order(root->left);
		printf("%d\n", root->data);
		in_order(root->right);
	}
}