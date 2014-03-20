#include <stdio.h>
#include <stdlib.h>
/* implete a stack */


int is_number_point(char *s){ 
	int res = 1;
	while(*s != '\0') {
		if (*s < '0' || *s > '9'){
			// printf("%c\n", *s);

			res = 0;
			break;
		}
		s++;
	}

	return res;
}


/* determine whether the string is a number string
	return 1 when it is , otherwise return 0
 */



int main(int argc, char const *argv[]){
	#define MAXVAL 100 
	int stack[MAXVAL];
	int i = 0; /* next free index of stack */
	void push(int  ss) {
		if (i < MAXVAL) {
			stack[i++] = ss;
		} else {
			printf("error: stack is full\n");
		}

	}

	int pop(void) {
		if (i > 0) {
			return stack[--i];
		} else {
			printf("error: stack is empty\n");
		}
		
	}

	int evalRPN(char *s[], int N) {
		int j = 0;
		char *type;
		int temp_op;

		while (j < N) {
			type = s[j];
			if(is_number_point(type) == 1) {
				// printf("%d\n", i);
				push(atoi(type));
				// printf("%d\n", atoi(type));
			} else{
				// printf("%c\n", *type);
				switch(*type) {
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
		printf("%d\n", pop());
	}



	char *s[] = {"2", "1", "+", "3", "*"};
	char *s1[] = {"4", "13", "5", "/", "+"};

	evalRPN(s, 5);
	evalRPN(s1, 5);

	// int result;
	// result = is_number_point(*(s+2));
	// printf("%s\n", "D");
	// printf("%d\n", result);
	// printf("%s\n", "D");

}