#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAXSIZE 1000

typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];
	size_t length;
	ElemType maxValue;
	ElemType minValue;
}SequList;

void listInit(SequList *s)
{
	s->length = 0;
	s->maxValue = 0;
	s->minValue = 0;
}

void showInfo(SequList *s)
{
	printf("The length of Sequence list is %d.\n",s->length);
	// printf("The max value of Sequence list is %d.\n",s->maxValue);
	// printf("The min value of Sequence list is %d.\n",s->minValue);
}

bool appendElem(SequList *s, ElemType element)
{
	if (s->length == MAXSIZE) return false;
	s->data[s->length] = element;
	s->length ++;
	return true;
} 

bool insertElem(SequList *s, int pos, ElemType element)
{
	if(pos < 1 || pos > s->length) return false;
	for (int i = s->length - 1 ; i >= pos - 1 ; i--)
	{
		s->data[i+1] = s->data[i];
	}
	s->data[pos-1] = element;
	s->length ++;

	return true;
}

bool deleteElem(SequList *s, int pos)
{
	if (pos < 1 || pos > s->length) return false;
	for (size_t i = pos; i < s->length ; i++)
	{
		s->data[i-1] = s->data[i];
	}
	s->length --;
	return true;
}

void listElem(SequList *s)
{
	if (s->length == 0) return ;
	printf("Element: ");
	for (size_t i = 0; i < s->length ; i++)
	{
		printf("%d, ", s->data[i]);
	}
	printf("\n");
}

int findElem(SequList *s, ElemType element)
{
	for(size_t i = 0; i< s->length; i++)
	{
		if(s->data[i] == element) return i+1;
	}
	printf("No Element: %d\n", element);
}

void deleteList(SequList *s)
{
	s->length = 0;
	s->maxValue = 0;
	s->minValue = 0;
}

int main(void)
{
	SequList myList;
	listInit(&myList);
	showInfo(&myList);

	/*append element*/
	appendElem(&myList, 1);
	appendElem(&myList, 2);
	appendElem(&myList, 3);
	appendElem(&myList, 4);
	appendElem(&myList, 5);
	appendElem(&myList, 6);
	listElem(&myList);

	/*insert element*/
	insertElem(&myList, 2, 1);
	listElem(&myList);
	
	/*delete element*/
	deleteElem(&myList, 2);
	listElem(&myList);

	/*find element*/
	printf("the position of element is %d. \n", findElem(&myList,4));

	/*delete list*/
	deleteList(&myList);
	listElem(&myList);

	return 0;
}