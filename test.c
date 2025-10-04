#include <stdio.h>
#include <string.h>

int main()
{
	char str[20];
	snprintf(str, sizeof(str), "I am %s", "pucheng");

	printf("%s",str);

	printf("hello");
	return 0;
}