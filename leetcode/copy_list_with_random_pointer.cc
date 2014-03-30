/****** there is a bug I can't figure out ****** */
// I use another algorithm to solove this problem


// http://oj.leetcode.com/problems/copy-list-with-random-pointer/

#include <stdio.h>
#include <stdlib.h>

  // Definition for singly-linked list with a random pointer.
typedef struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  // RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
} RandomListNode;

typedef struct treeNode {
	RandomListNode *key;   // the pointer to the RandomListNode in head
	RandomListNode *value; // the pointer to the RandomListNode in newHead
	struct treeNode *left;
	struct treeNode *right;
} treeNode;

typedef struct BST {
	treeNode *root;
} BST;

void init_bst(BST *bst) {
	bst->root = NULL;
}

treeNode *search_bst(treeNode *root, RandomListNode *p1) {
	if (root == NULL || (root->left == NULL && root->right == NULL)) {
		return root;
	} else {
		if (root->key == p1) {
			return root;
		} else if (p1 > root->key) {
			return search_bst(root->right, p1);
		} else {
			return search_bst(root->left, p1);
		}
	}
}

void insert_bst(BST *bst, RandomListNode *p1, RandomListNode *p2){
	if (bst->root == NULL) {
		treeNode *newRoot = (treeNode *) malloc(sizeof(treeNode));
		newRoot->key = p1;
		newRoot->value = p2;
		newRoot->left = NULL;
		newRoot->right = NULL;
		bst->root = newRoot;
	} else {
		treeNode *newTreeNode = (treeNode *) malloc(sizeof(treeNode));
		newTreeNode->key = p1;
		newTreeNode->value = p2;
		newTreeNode->left = NULL;
		newTreeNode->right = NULL;

		treeNode *treeNodeWhereToInsert;
		treeNodeWhereToInsert = search_bst(bst->root, p1);

		if (p1 < treeNodeWhereToInsert->key) {
			treeNodeWhereToInsert->left = newTreeNode;
		} else {
			treeNodeWhereToInsert->right = newTreeNode;
		}
	}
}

RandomListNode *copyWithOutRandom(RandomListNode *head) {
	if (head == NULL) {
		return NULL;
	} else {
		RandomListNode *newHead = (RandomListNode *) malloc(sizeof(RandomListNode));
		newHead->label = head->label;

		newHead->next = copyWithOutRandom(head->next);
		return newHead;
	}
}

RandomListNode *getCopyHeadRandomPointer(RandomListNode *head, BST *bst){
	treeNode *pHeadTreeNode = search_bst(bst->root, head);
	return pHeadTreeNode->value;
}

void copyWithRandom(RandomListNode *head, RandomListNode *copyHead, BST *bst){ // change the *copyHead
	if (copyHead != NULL) {
		if (head->random == NULL) {
			copyHead->random = NULL;
			copyWithRandom(head->next, copyHead->next, bst);
		} else {
			copyHead->random = getCopyHeadRandomPointer(head->random, bst);

			copyWithRandom(head->next, copyHead->next, bst);
		}
	}
}




RandomListNode *copyRandomListC(RandomListNode *head) {
	if (head == NULL) {
		return head;
	} else {
		RandomListNode *copyHead;

		copyHead = copyWithOutRandom(head);
						
		BST bst; 

		init_bst(&bst);

		RandomListNode *tmpHead = head;
		RandomListNode *tmpCopyHead = copyHead;
		
		while(tmpHead != NULL && tmpCopyHead !=NULL) {
			// printf("%s\n", "1");
			insert_bst(&bst, tmpHead, tmpCopyHead);
			// printf("%s\n", "22");
						// printf("%s\n", "33");

			tmpHead = tmpHead->next;
			// printf("%s\n", "44");

			tmpCopyHead = tmpCopyHead->next;
		}

		copyWithRandom(head, copyHead, &bst);
				// printf("%s\n", "dfd");

		return copyHead;
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


	printf("%d\n", c_solution(&n1)->next->next->next->random->label);
	return 0;
}