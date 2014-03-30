// http://oj.leetcode.com/problems/max-points-on-a-line/

#include <vector>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <float.h>

#define M 1000
// #define DBL_MAX 1E+37
using std::vector;

#define TRUE 1
#define FALSE 0
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};


int is_same_point(Point* point1, Point* point2) {
	if(point1->x == point2->x && point1->y == point2->y){
		return TRUE;
	} else {
		return FALSE;
	}
}

typedef struct BST_TreeNode {
	double key; // represent slop
	int val; // represent the number of slop
	struct BST_TreeNode* left;
	struct BST_TreeNode* right;
} BST_TreeNode;



typedef struct Arr_TreeNodes {
	BST_TreeNode arr[M];
	int size;
} Arr_TreeNodes;

void Arr_TreeNodes_init(Arr_TreeNodes* arr_tree_nodes){
	arr_tree_nodes->size = 0;
}

// void print_arr_tree_nodes(Arr_TreeNodes* arr_tree_nodes) {
// 	int size = arr_tree_nodes->size;

// 	BST_TreeNode *arr = arr_tree_nodes->arr;
// 	int i = 0;
// 	for(i = 0; i < size; i++) {
// 		printf("%d ", (arr + i)->val);
// 	}
// 	printf("\n");
// }

BST_TreeNode *BST_search(BST_TreeNode *bst, double key) {
	if (bst == NULL) {
		return NULL;
	} else {
		// BST_TreeNode *tmp_bst = bst;
		if (key == bst->key) {
			return bst;
		} else if (key < bst->key) {
			if(bst->left == NULL) {
				return bst;
			} else {
				return(BST_search(bst->left, key));
			}
		} else {
			if (bst->right == NULL) {
				return bst;
			} else {
				return(BST_search(bst->right, key));
			}
		}
	}
}


void BST_push(Arr_TreeNodes *arr_tree_nodes, double key){ // note: an Arr_TreeNodes is a BST
	int *size = &arr_tree_nodes->size;
	// printf("%s %d\n", "*size", *size);
	if (*size == 0) {
		BST_TreeNode new_treeNode;
		new_treeNode.key = key;
		new_treeNode.val = 1; 
		new_treeNode.left = NULL;
		new_treeNode.right = NULL;
		(arr_tree_nodes->arr)[*size] = new_treeNode;
		*size += 1;
	} else {
		// printf("%s\n", "dfas");
		BST_TreeNode *get_insert_node;
				// printf("%s %f\n", "key", key);
		get_insert_node = BST_search(arr_tree_nodes->arr, key);

			// printf("%s %d\n", "*size", *size);
		// printf("%s %f\n", "get_insert_node->key", get_insert_node->key);

		if (get_insert_node->key == key) {
			// printf("%s\n", "Dfd");
			get_insert_node->val += 1;
			// printf("%s %d\n", "get_insert_node->val", get_insert_node->val);
		} else if (key < get_insert_node->key) {
			// printf("%s\n", "111");
			BST_TreeNode new_treeNode;
			new_treeNode.key = key;
			new_treeNode.val = 1;
			new_treeNode.left = NULL;
			new_treeNode.right = NULL;
			(arr_tree_nodes->arr)[*size] = new_treeNode;
			get_insert_node->left = &(arr_tree_nodes->arr)[*size];
			*size += 1;

		} else {
			// printf("%s\n", "222");
			BST_TreeNode new_treeNode;
			new_treeNode.key = key;
			new_treeNode.val = 1;
			new_treeNode.left = NULL;
			new_treeNode.right = NULL;
			(arr_tree_nodes->arr)[*size] = new_treeNode;
			get_insert_node->right = &(arr_tree_nodes->arr)[*size];
			*size += 1;
							// printf("%s %d\n", "*size", *size);
		} 
	}
}

double slop_of_points(Point* point1, Point* point2) {
	if (point1->x == point2->x) {
		return DBL_MAX;
	} else {
		return ((double)(point1->y - point2->y)) / (point1->x - point2->x);
	}

}

int get_max_val_in_BST(BST_TreeNode *bst) { // here val is the number of slop
	if (bst == NULL) {
		// printf("%s\n", "Error: the bst is empty");
		// return 0;
	}
	int max = 0; // the val in bst
	int left_max = 0;  
	int right_max = 0; 

	if (bst->left == NULL && bst->right == NULL) {
		max = bst->val;
	} else {
		max = bst->val;

		if (bst->left != NULL) {
			left_max = get_max_val_in_BST(bst->left);
			if (left_max > max) {
				max = left_max;
			}
		} 

		if (bst->right != NULL) {
			right_max = get_max_val_in_BST(bst->right);
			// printf("%d\n", right_max);
			if (right_max > max) {
				max = right_max;
			}
		}
	}

	return max;
}

int tmp_max_points_by_first_point(Point* c_points[], int N) {
	if (N == 0 || N == 1 || N == 2) {
		return N;
	}
	int i = 0;
	int n_same_point = 0;
	double slop = 0;
	Arr_TreeNodes arr_tree_nodes;
	Arr_TreeNodes_init(&arr_tree_nodes);

	for(i = 1; i < N; i++) {
		if (is_same_point(*c_points, *(c_points + i))) {
			n_same_point += 1;
		}  else {
			slop = slop_of_points(*c_points, *(c_points + i));
			// printf("%s%f\n", "slop",slop);

			BST_push(&arr_tree_nodes, slop);
						// printf("%s\n", "adf");
		}
	}	
	// printf("%s %d\n", "n_same_point", n_same_point);
	// print_arr_tree_nodes(&arr_tree_nodes);
	// printf("   %d\n", get_max_val_in_BST(arr_tree_nodes.arr));
	return n_same_point +  (arr_tree_nodes.arr) + 1; // two points have one slop 
}

int max_points_on_a_line(Point* c_points[], int N) {
	if (N == 0 || N == 1 || N == 2) {
		return N;
	}

	int i = 0;
	int j = 0;
	int max = 0;
	int tmp_max = 0;
	int n_same_point = 0;

	for(i = 0; i < N; i++) {	
		// printf("%s %d\n", "S", i);

		tmp_max = tmp_max_points_by_first_point(c_points + i, N - i);
		// printf("%s %d\n", "tmp_max", tmp_max);
		if (tmp_max > max) {
			max = tmp_max;
		}	
	}

	return max;
}


int c_solution(Point* c_points[], int N) {
	// printf("%d\n", max_points_on_a_line(c_points, N));
	return max_points_on_a_line(c_points, N);
}

class Solution {
public:
    int maxPoints(vector<Point> &points) {
      Point *c_points[points.size()];
      for(int i = 0; i < points.size(); i++) {
        c_points[i] = &points[i];
      }
      return c_solution(c_points, points.size());
    }
};




Point make_point(int i, int j) {
	Point new_point;
	new_point.x = i;
	new_point.y = j;
	return new_point;
}
int main(int argc, char const *argv[])
{
	/* code */
	int N = 3;
	Point* c_points[N];
	Point p1;
	p1.x = 1;
	p1.y = 1;

	Point p2;
	p2.x = 1;
	p2.y = 1;

	Point p3;
	p3.x = 1; 
	p3.y = 1;

	// Point p4;
	// p4.x = -1; 
	// p4.y = 2;
// [(-230,324),(-291,141),(34,-2),(80,22),(-28,-134),(40,-23),(-72,-149),(0,-17),
// 	(32,-32),(-207,288),(7,32),(-5,0),(-161,216),(-48,-122),(-3,39),(-40,-113),(115,-216),
// 	(-112,-464),(-72,-149),(-32,-104),(12,42),(-22,19),(-6,-21),(-48,-122),(161,-288),
// 	(16,11),(39,23),(39,30),(873,-111)]
	// printf("%f\n",slop_of_points(&p1, &p2));
	// printf("%f\n",slop_of_points(&p1, &p4));

	c_points[0] = &p1;
	c_points[1] = &p2;
	c_points[2] = &p3;

	// c_points[3] = &p4;
	// int input[] = {0,-12,5,2,2,5,0,-5,1,5,2,-2,5,-4,3,4,-2,4,-1,4,0,-5,0,-8,-2,-1,0,-11,0,-9};
	// int input[] = {1, 1, 1, 1, 1, 1};
	// int N = 6;
	// Point *c_points[N / 2];

	// Point arr_points[N / 2];

	// int i = 0;
	// Point new_point;	
	// for(i = 0; i < N - 1; i += 2) {
	// 	new_point = make_point(input[i], input[i+1]);
	// 	arr_points[i / 2] = new_point;
	// 	c_points[i / 2] = &arr_points[i / 2];
	// }
	// printf("%d\n", c_points[0]->y);
	// printf("%s  %s\n", "x", "y");
	// for (i = 0; i < N / 2; i++) {
	// 	printf("%d  %d\n", c_points[i]->x, c_points[i]->y);
	// }

	// printf("%f\n",slop_of_points(c_points[0], c_points[1]));
	// printf("%f\n",slop_of_points(c_points[0], c_points[2]));
	// printf("%f\n",slop_of_points(c_points[0], c_points[3]));
	// printf("\n\n\n");


	printf("%d\n", c_solution(c_points, N));
	return 0;
}