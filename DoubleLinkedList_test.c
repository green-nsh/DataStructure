#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct node{
	ElemType data;
	struct node *prev,*next;
}Node;

/* 1 Init*/
Node* Init(void)
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	head->prev = NULL;
	head->data = 1;

	return head;
}

/* 2 insertHead*/
void insertHead(Node *head, ElemType element)
{
	Node * node_new = (Node*)malloc(sizeof(Node));
	node_new ->data = element;
	node_new ->prev = head;

	node_new ->next = head->next;
	if(head->next != NULL)
	{
		head -> next ->prev = node_new;
	}
	head->next = node_new;
}

/* 3 insertTail*/
void insertTail(Node *head, ElemType element)
{
	Node *node_new = (Node*)malloc(sizeof(Node));
	node_new->data = element;
	node_new->next = NULL;

	Node *p = head;
	while(p->next != NULL)
	{
		p = p->next;
	}
	p->next = node_new;
	node_new ->prev = p;
}

/* 4 insertAnywhere*/
void insertAnywhere(Node *head, int pos, ElemType element)
{
	Node* node_new = (Node*)malloc(sizeof(Node));
	node_new ->data = element;

	Node* p = head;
	for(size_t i = 0; i<pos-1; i++)
	{
		p = p->next;
	}

	node_new->prev = p;
	node_new->next = p->next;
	p->next->prev = node_new;
	p->next = node_new;
}

/* 5 deleteElement*/
void deleteElement(Node *head, int pos)
{
	Node* p = head;
	Node* q = NULL;
	for (size_t i = 0; i<pos-1; i++)
	{
		p = p->next;
	}

	q = p->next;	/*delete element*/
	q->next->prev = p;
	p->next = q->next;
	free(q);
}

/* 6 list*/
void List(Node *head)
{
	Node *p = head->next;

	printf("Element: ");
	while(p != NULL)
	{
		printf("%d, ",p->data);
		p = p->next;
	}
	printf("\n");
}

/* 7 get length*/
size_t getLength(Node *head)
{
	size_t ind = 0;
	Node* p = head;
	while(p->next != NULL)
	{
		ind++;
		p = p->next;
	}
	return ind;
}

/* 8 delete list*/
void deleteList(Node* head)
{
	Node *p = head->next;
	Node *q = NULL;

	if(p == NULL) return;
	while(p->next != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(p);
	head->next = NULL;
}

int main(void)
{
	printf("%zu\n",sizeof(Node));

	/*create*/
	Node *head = Init();
	List(head);

	/*insert head*/
	insertHead(head,1);
	List(head);

	/*insert tail*/
	insertTail(head,2);
	insertTail(head,3);
	insertTail(head,4);
	insertTail(head,5);
	insertTail(head,6);
	List(head);

	/*insert anywhere*/
	insertAnywhere(head, 3, 9);
	List(head);

	/*delete element*/
	deleteElement(head, 3);
	List(head);

	/*get length*/
	printf("the length of list is %d.\n", getLength(head));

	/*delete element*/
	deleteList(head);
	List(head);

	return 0;
}