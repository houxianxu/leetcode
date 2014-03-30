// http://oj.leetcode.com/problems/evaluate-reverse-polish-notation/

#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
using std::string;
using std::vector;

// define sim_stack 
#define MAXVAL 100 
int sim_stack[MAXVAL];
int i = 0; /* next free index of sim_stack */
void push(int ss) {
		if (i < MAXVAL) {
			sim_stack[i++] = ss;
		} else {
			printf("error: sim_stack is full\n");
		}
	}
	int pop(void) {
		if (i > 0) {
			return sim_stack[--i];
		} else {
			printf("error: sim_stack is empty\n");
		}
	}

int is_number_point(const char *s){ 
	int res = 0;
	while(*s != '\0') {
		if (isdigit(*s)){
			// printf("%c\n", *s);
			res = 1;
			break;
		}
		s++;
	}
	return res;
}
// const means you can't modify the content in char*
int c_solution(const char *tokens[], int N) {
	int j = 0;
	char *type;
	int temp_op;

	while (j < N) {

		if(is_number_point(tokens[j]) == 1) {
			// printf("%d\n", i);
			push(atoi(tokens[j]));
			// printf("%d\n", atoi(tokens[j]));
		} else{
			// printf("%c\n", *tokens[j]);
			switch(*tokens[j]) {
				case '+':
					push(pop() + pop());
					break;
				case '*':
					push(pop() * pop());
					break;
				case '-':
					temp_op = pop();
					push(pop()- temp_op);
					break;
				case '/':
					temp_op = pop();
					push(pop() / temp_op);
					break;
				default:
					printf("error: unknown character\n");
			}
		}
		j++;
	}
	return pop();
}

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
      const char* c_tokens[tokens.size()];
      for(int i = 0; i < tokens.size(); i++) {
        c_tokens[i] = tokens[i].c_str();
      }
      return c_solution(c_tokens, tokens.size());
    }
};

int main(int argc, char const *argv[])
{	
	const char *s[] = {"3","-4","+"};
	const char *s1[] = {"2", "1", "+", "3", "*"};
	
	printf("%d\n", c_solution(s, 3));

	
}