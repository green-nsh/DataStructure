#include <stdio.h>

typedef struct
{
	char a;
	int b;
}S1;

typedef struct
{
	int a;
	char b;
	char c;
}S2;

int main()
{
	printf("S1: %zu",sizeof(S1));
	printf("S2: %zu",sizeof(S2));

	return 0;
}