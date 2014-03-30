// http://oj.leetcode.com/problems/binary-tree-postorder-traversal/

#include <iostream>
#include <vector>
using std::vector;
// Note: definition of TreeNode should be removed when submitting the code.
#include <stdio.h>
#include <stdlib.h>
#define M 1000

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  // TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void Rightfind(TreeNode *root, int *tmpPpnodes, int *i) {
	// printf("%d\n", root->val);
	// 				printf("%s\n", "Dfds");

	if(root == NULL) {
				// printf("%s\n", "D12313");
	} else if(root->right == NULL) {
		tmpPpnodes[(*i)++] = root->val;
			// printf("%d\n", *i);

		Rightfind(root->left,tmpPpnodes, i);
	} else if(root->left == NULL) {
		// printf("%d\n", root->val);
		// printf("%d\n", *i);
		tmpPpnodes[(*i)++] = root->val;
		// printf("%d\n", root->right->val);
		Rightfind(root->right,tmpPpnodes, i);

	} else {
		// printf("%s\n", "11");
		tmpPpnodes[(*i)++] = root->val;
		Rightfind(root->right,tmpPpnodes, i);
		Rightfind(root->left,tmpPpnodes, i);
	}

}


// return the nodes value in ppnodes, nodes number in p_nodes_num
void c_solution(TreeNode *root, int **ppnodes, int *p_nodes_num) {
	int i = 0;
	int tmpPpnodes[M];
	*ppnodes = (int *) malloc(M * sizeof(int));
	Rightfind(root, tmpPpnodes, &i);
	*p_nodes_num = i;
	i = 0;
	// printf("%d\n", *(*ppnodes + 34));
	for(i = 0; i < *p_nodes_num; i++) {
		// printf("%s\n", "123");
		// printf("%d\n", *p_nodes_num - i - 1);
		(*ppnodes)[i] = tmpPpnodes[*p_nodes_num - i - 1]; // or *(*ppnodes+i), wrong to use *ppnodes[i]

	}
		// printf("%s\n", "houxianxu");

	// printf("%d\n", *ppnodes[0]);
}

// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode *root) {
//       int *pnodes;
//       int nodes_num;
//       c_solution(root, &pnodes, &nodes_num);
//       vector<int> ret(pnodes, pnodes+nodes_num);
//       free(pnodes);
//       return ret;
//     }
// };

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode node1, node2, node3, *res;
	node1.val = 3;
	node2.val = 1;
	node3.val = 2;
	node1.left = NULL;
	node2.left = NULL;
	node3.left = NULL;
	node1.right = &node2;
	node2.right = &node3;
	node3.right = NULL;
	// int i = 0;
	// int tmpPpnodes[M];
	// Rightfind(&node1, tmpPpnodes, &i);
	int nodes_num;
	int *pnodes;
	c_solution(&node1, &pnodes, &nodes_num);
	return 0;
}