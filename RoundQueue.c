#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ERROR_VALUE -9999

typedef int ElemType;
typedef struct roundQueue
{
	ElemType* data;
	int front;
	int rear;
}RoundQueue;

/* 3 isEmpty*/
bool isEmpty(RoundQueue* queue)
{
	if(queue->front == queue->rear) {printf("empty\n"); return true;}
	else return false;
}

/* 4 isFull*/
bool isFull(RoundQueue* queue)
{
	if((queue->rear + 1) % MAXSIZE == queue->front) {printf("full\n"); return true;}
	else false;
}

/* 1 init*/
RoundQueue* Init()
{
	RoundQueue* queue = (RoundQueue*)malloc(sizeof(RoundQueue));
	queue->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	queue->front = 0;
	queue->rear  = 0;
	return queue;
}

/* 2 enQueue*/
void enQueue(RoundQueue* queue, ElemType element)
{
	if (isFull(queue)) return;
	*(queue->data + queue->rear) = element;
	queue->rear = (queue->rear + 1) % MAXSIZE;
}

/* 5 dequeue*/
ElemType deQueue(RoundQueue* queue)
{
	if(isEmpty(queue)) return ERROR_VALUE;
	ElemType element = *(queue->data + queue->front);
	queue->front = (queue->front + 1) % MAXSIZE;
	return element;
}

int main()
{
	/* Init */
	RoundQueue *queue = Init();

	/* enQueue*/
	enQueue(queue, 1);
	enQueue(queue, 2);
	enQueue(queue, 3);
	enQueue(queue, 4);
	enQueue(queue, 5);
	enQueue(queue, 6);

	/*deQueue*/
	printf("deQueue: %d.\n", deQueue(queue));
	printf("deQueue: %d.\n", deQueue(queue));
	printf("deQueue: %d.\n", deQueue(queue));
	printf("deQueue: %d.\n", deQueue(queue));

	printf("Empty: %d.\n", isEmpty(queue));

	return 0;
}