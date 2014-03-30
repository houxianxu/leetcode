// http://oj.leetcode.com/problems/binary-tree-preorder-traversal/

#include <iostream>
#include <vector>
using std::vector;
#include <stdio.h>
#include <stdlib.h>
#define M 1000

// Note: definition of TreeNode should be removed when submitting the code.
// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };



void LeftFind(TreeNode *root, int *tmpPpnodes, int *i) {
  // printf("%d\n", root->val);
  //        printf("%s\n", "Dfds");

  if(root == NULL) {
        // printf("%s\n", "D12313");
  } else if(root->right == NULL) {
    tmpPpnodes[(*i)++] = root->val;
      // printf("%d\n", *i);

    LeftFind(root->left,tmpPpnodes, i);
  } else if(root->left == NULL) {
    // printf("%d\n", root->val);
    // printf("%d\n", *i);
    tmpPpnodes[(*i)++] = root->val;
    // printf("%d\n", root->right->val);
    LeftFind(root->right,tmpPpnodes, i);

  } else {
    // printf("%s\n", "11");
    tmpPpnodes[(*i)++] = root->val;
    
    LeftFind(root->left,tmpPpnodes, i);
    LeftFind(root->right,tmpPpnodes, i);
  }

}


// return the nodes value in ppnodes, nodes number in p_nodes_num
void c_solution(TreeNode *root, int **ppnodes, int *p_nodes_num) {
  int i = 0;
  int tmpPpnodes[M];                           // there is no need to use tmpPpnodes here,
  *ppnodes = (int *) malloc(M * sizeof(int)); // I just change a little from postorder code
  LeftFind(root, tmpPpnodes, &i);
  *p_nodes_num = i;
  i = 0;
  // printf("%d\n", *(*ppnodes + 34));
  for(i = 0; i < *p_nodes_num; i++) {
    // printf("%s\n", "123");
    // printf("%d\n", *p_nodes_num - i - 1);
    (*ppnodes)[i] = tmpPpnodes[i]; // or *(*ppnodes+i), wrong to use *ppnodes[i]

  }
}

class Solution {
 public:
  vector<int> preorderTraversal(TreeNode *root) {
    int *pnodes;
    int nodes_num;
    c_solution(root, &pnodes, &nodes_num);
    vector<int> ret(pnodes, pnodes+nodes_num);
    free(pnodes);       
    return ret;
  }
};

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}