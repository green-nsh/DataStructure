#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 5
#define ERROE_VALUE -9999

typedef int ElemType;
typedef struct
{
	ElemType *data;
	int rear;
	int front;
}Queue;

/* 1 Init*/
Queue* Init(void)
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	queue->rear = 0;
	queue->front= 0;

	return queue;
}

/* 2 IsEmpty*/
bool isEmpty(Queue *queue)
{
	if(queue->front == queue->rear) return true;
	else return false;
}

/* 3 IsFull*/
bool isFull(Queue *queue)
{
	if(queue->rear == MAXSIZE)
	{
		if(queue->front == 0) return true;
		else{
			size_t step = queue->front;
			for(size_t i = queue->front; i <= queue->rear; i++)
			{
				queue->data[i-step] = queue->data[i];
			}
			queue->front = 0;
			queue->rear -= step;
		}
	}
	return false;
}

/* 4 EnQueue*/
void enQueue(Queue *queue, ElemType element)
{
	if(isFull(queue)) return ;
	queue->data[queue->rear++] = element;
}

/* 5 DeQueue*/
ElemType deQueue(Queue *queue)
{
	if(isEmpty(queue)) return ERROE_VALUE;
	return queue->data[queue->front++];
}

/* 6 get front element*/
ElemType getFrontElement(Queue *queue)
{
	if(isEmpty(queue)) return ERROE_VALUE;
	return queue->data[queue->front];
}

int main(void)
{
	/*init*/
	Queue* queue = Init();

	/*enqueue*/
	enQueue(queue, 1);
	enQueue(queue, 2);
	enQueue(queue, 3);
	enQueue(queue, 4);
	enQueue(queue, 5);
	enQueue(queue, 6);

	/*dequeue*/
	printf("dequeue: %d.\n", deQueue(queue));
	printf("dequeue: %d.\n", deQueue(queue));
	printf("dequeue: %d.\n", deQueue(queue));
	printf("dequeue: %d.\n", deQueue(queue));

	/*get front element*/
	printf("front element: %d.\n", getFrontElement(queue));
	return 0;
}