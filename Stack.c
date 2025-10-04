#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100
#define ERROR_VALUE -9999

typedef int ElemType;
typedef struct {
	ElemType *data;
	int top;
}Stack;

/* 1 init*/
Stack* Init()
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	stack->top = -1;

	return stack;
}

void Push(Stack *stack, ElemType element)
{
	if(stack->top == MAXSIZE-1) {printf("full\n"); return;}
	else{
		stack->top ++;
		stack->data[stack->top] = element;
	}
}

ElemType Pop(Stack *stack)
{
	if(stack->top == -1) {printf("empty\n"); return ERROR_VALUE;}
	else{
		ElemType element = stack->data[stack->top];
		stack->top--;
		return element;
	}
}

ElemType getStackTop(Stack *stack)
{
	if(stack->top == -1) {printf("empty\n"); return ERROR_VALUE;}
	return stack->data[stack->top];
}

int main()
{
	/* 1 init */
	Stack* stack = Init();

	/* 2 push */
	Push(stack, 1);
	Push(stack, 2);
	Push(stack, 3);
	Push(stack, 4);
	Push(stack, 5);
	Push(stack, 6);

	/* 3 pop */
	printf("POP: %d.\n", Pop(stack));
	printf("POP: %d.\n", Pop(stack));
	printf("POP: %d.\n", Pop(stack));
	printf("POP: %d.\n", Pop(stack));
	printf("POP: %d.\n", Pop(stack));

	/*get stack top*/
	printf("stack top: %d.\n", getStackTop(stack));
	return 0;
}