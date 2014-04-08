#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

typedef struct QNode {
	ElementType data;
	struct QNode *next;
} QNode;

typedef struct Queue {
	QNode *front;
	QNode *rear;
} Queue;

// init Queue
void initQueue(Queue *queueP) {
	queueP->front = NULL;
	queueP->rear = NULL;
}

void enQueue(Queue *queueP, ElementType x) {
	QNode *newP;
	newP = malloc(sizeof(QNode));

	newP->data = x;
	newP->next = NULL;

	if (queueP->rear == NULL) { /* the queueP is empty*/
		queueP->front = newP;
		queueP->rear = newP;
	} else {
		queueP->rear->next = newP;
		queueP->rear = newP;
	}
}

ElementType outQueue(Queue *queueP) {
	if (queueP->front == NULL) {
		printf("%s\n", "the queue is empty");
		return;
	} else {
		QNode *p;
		ElementType res; /* the result to return */
		res = queueP->front->data;
		p = queueP->front; /* used to free the front node */
		queueP->front = p->next;
		if (queueP->front == NULL) { /* thers are no nodes*/
			queueP->rear = NULL; 
		}

		free(p); /* free the front node */
		return res;
	}
}

int isEmptyQueue(Queue *queueP) {
	if (queueP->front == NULL) {
		return 1;
	} else {
		return 0;
	}
}

void clearQueue(Queue *queueP) {
	QNode *p;
	p = queueP->front;

	while (p != NULL) {                          /* can't write this :  */
		queueP->front = p->next;                 /*free(p);*/
		free (p);								/* p = p->next */ // because p is freed 
		p = queueP->front;
	}

}



int main(int argc, char const *argv[])
{
	Queue q;
	int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	int i;
	initQueue(&q);
	for (i = 0; i < 8; i++) {
		enQueue(&q, a[i]);
		// printf("%d\n", q.front->data);
		printf("%d\n", q.rear->data);
	}
	
	while(!isEmptyQueue(&q)) {
		printf("%d\n", outQueue(&q));
	}
	return 0;
}




