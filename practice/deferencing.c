#include <stdio.h>

int main(void)
{
	int n = 10;
	int *p;
	    p = &n;

	printf("%d\n", *p);
	printf("%p\n", p);

	*p = 400;
	printf("%d\n", n);
	printf("%p\n", &n);
	return (0);
}
