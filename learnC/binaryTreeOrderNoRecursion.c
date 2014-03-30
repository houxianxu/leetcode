#include <stdio.h>

#define STACK_MAX 1000

// definition of TreeNode
typedef struct TreeNode {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

// definition of Stack
// http://groups.csail.mit.edu/graphics/classes/6.837/F04/cpp_notes/stack1.html
typedef struct Stack {
	TreeNode *arrNode[STACK_MAX];
	int size;
} Stack;

void Stack_init(Stack *s) {
	s->size = 0;
}

TreeNode *Stack_top(Stack *s) {
	if (s->size == 0) {
		fprintf(stderr, "Error: stack empty\n");
		return;
	} else {
		return s->arrNode[s->size - 1];
	}
}

void Stack_push(Stack *s, TreeNode *node) {
	if (s->size < STACK_MAX) {
		s->arrNode[s->size++] = node;
	} else {
		fprintf(stderr, "Error: stack is full\n");
	}
}

TreeNode *Stack_pop(Stack *s) { // return nothing, use Stack_top to get the data
	if (s->size == 0) {
		fprintf(stderr, "Error: Stack is empty\n");
	} else {
		return s->arrNode[s->size - 1];
	}
}

int stack_is_empty(Stack *s) {
	return s->size;
}

void printStack(Stack *s) {
	while (s->size >= 0) {
		TreeNode *tmp_node = Stack_pop(s);
		printf("%d", tmp_node->data);
	}
	printf("\n");
}
// end of definition of Stack

// inorder traversal
void in_order_no_recursion(TreeNode *root) {
	if (root == NULL) {
		return;
	}

	Stack stack;
	Stack_init(&stack);
	TreeNode *current = root; 

	while(!stack_is_empty(&stack) || current != NULL) {
		if(current != NULL) {
			Stack_push(&stack, current);
			current = current->left;
		} else {
			current = Stack_pop(&stack);
			printf("%d\n", current->data);
			current = current->right;
		}
	}
}


// pre-order Traversal
void pre_order_no_recursion(TreeNode *root) {
	if (root == NULL) {
		return;
	}

	Stack stack;
	Stack_init(&stack);
	TreeNode *current = root;

	while(!stack_is_empty(&stack) || current != NULL) {
		if(current != NULL) {
			printf("%d\n", current->data);
			Stack_push(&stack, current->right);
			current = current->left;
		} else {
			current = Stack_pop(&stack);
		}
	}

}

// post-order Traversal
// is very similar to pre-order traversal
// the result is reversely
void post_order_no_recursion(TreeNode *root) {
	if (root == NULL) {
		return;
	}

	Stack stack;
	Stack stack_output; // use to store the result
	Stack_init(&stack);
	Stack_init(&stack_output);

	TreeNode *current = root;

	while(!stack_is_empty(&stack) || current != NULL) {
		if(current != NULL) {
			Stack_push(&stack, current->left);
			Stack_push(&stack_output, current);
			current = current->right;
		} else {
			current = Stack_pop(&stack);
		}
	}
	printStack(&stack_output);
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}