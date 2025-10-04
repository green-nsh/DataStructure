#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int ElemType;
typedef struct node{
	ElemType *data;
	struct node *next;
}Node;
typedef struct{
	Node *front;
	Node *rear;
}LinkedQueue;

/* 1 init*/
LinkedQueue* Init()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = (ElemType*)malloc(sizeof(ElemType));
	*(head->data) = 1;
	head->next = NULL;

	LinkedQueue* queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	queue->front = head;
	queue->rear = head;

	return queue;
}

/* 2 isEmpty*/
bool isEmpty(LinkedQueue *queue)
{
	if(queue->front == queue->rear) return true;
	else return false;
}

/* 3 enQueue*/
void enQueue(LinkedQueue *queue, ElemType element)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = (ElemType*)malloc(sizeof(ElemType));
	*(node->data) = element;
	node->next = NULL;

	queue->rear->next = node;
	queue->rear = node;
}

/* 4 deQueue*/
ElemType deQueue(LinkedQueue *queue)
{
	Node *p = queue->front->next;

	ElemType element = *(p->data);
	queue->front->next = p->next;
	free(p->data);
	free(p);

	return element;
}

/* 5 get front element*/
ElemType getFrontElement(LinkedQueue *queue)
{
	return *(queue->front->next->data);
}

int main()
{
	/* init */
	LinkedQueue* queue = Init();
	printf("isEmpty: %d\n", isEmpty(queue));

	/* enqueue */
	enQueue(queue, 1);
	enQueue(queue, 2);
	enQueue(queue, 3);
	enQueue(queue, 4);
	enQueue(queue, 5);
	enQueue(queue, 6);

	/* dequeue */
	printf("deQueue: %d.\n", deQueue(queue));
	printf("deQueue: %d.\n", deQueue(queue));
	printf("deQueue: %d.\n", deQueue(queue));
	printf("deQueue: %d.\n", deQueue(queue));
	printf("deQueue: %d.\n", deQueue(queue));

	/* get front element*/
	printf("FrontElement: %d.\n", getFrontElement(queue));

	return 0;
}