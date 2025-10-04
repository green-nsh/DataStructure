#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct node {
	ElemType data;
	struct node *next;
} Node;

/* 1 create Head Node*/
Node* LinkedListInit()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 1;
	head->next = NULL;

	return head;
}

/* 2 insert head*/
void insertHead(Node *head, ElemType element)
{
	Node* node_new = (Node*)malloc(sizeof(Node));
	node_new->data = element;
	node_new->next = head->next;
	head->next = node_new;
}

/* 3 insert tail*/
void insertTail(Node *head, ElemType element)
{
	Node* node_new = (Node*)malloc(sizeof(Node));
	node_new->data = element;
	node_new->next = NULL;
	
	Node*p = head;
	while(p->next != NULL)
	{
		p = p->next;
	}
	p->next = node_new;
}

/* 4 insert anywhere*/
void insertAnywhere(Node *head, int pos, ElemType element)
{
	Node *node_new = (Node*)malloc(sizeof(Node));
	node_new-> data = element;

	Node *p = head;
	for (size_t i=0; i<pos-1; i++)
	{
		p = p->next;
	}
	node_new->next = p->next;
	p->next = node_new;
}

/* 5 delete element*/
void deleteElement(Node *head, int pos)
{
	Node *p = head;
	Node *q = NULL;
	for(size_t i = 0; i < pos-1; i++)
	{
		p = p->next;
	}
	q = p->next;  /* current */
	q = q->next;  /* next */

	p->next = q;
	free(p->next);
}

/* 6 list node*/
void List(Node *head)
{
	Node *p = head;

	printf("Element: ");
	while(p->next != NULL)
	{
		p = p->next;
		printf("%d, ", p->data);
	}
	printf("\n");
}

/* 7 get length*/
int getLength(Node *head)
{
	Node *p = head;
	int ind = 0;

	while(p->next != NULL)
	{
		p = p->next;
		ind ++;
	}
	return ind;
}

/* 8 deleteList*/
void deleteList(Node *head){
	Node* p = head->next;
	Node* q = NULL;

	while(p->next != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(p);
}

/* 9 find end k element*/
ElemType findEndkElement(Node *head, int k)
{
	Node *p = head;
	Node *q = head;

	for (size_t i = 0; i < k; i++)
	{
		p = p->next;
	}

	while (p->next != NULL)
	{
		p = p->next;
		q = q->next;
	}
	q = q->next;
	return q->data;
}

int main()
{
	/*create*/
	Node* head = LinkedListInit();

	/*insert head*/
	insertHead(head, 1);
	insertHead(head, 2);
	insertHead(head, 3);
	insertHead(head, 4);
	List(head);

	/*insert tail*/
	insertTail(head, 5);
	insertTail(head, 6);
	List(head);

	/*insert anywhere*/
	insertAnywhere(head,5,1);
	List(head);

	/*delete element*/
	deleteElement(head,5);
	List(head);

	/*get length*/
	printf("length: %d\n", getLength(head));

	/*delete List*/

	/*find end kth element*/
	printf("the element of end k is %d\n", findEndkElement(head,4));

	return 0;
}