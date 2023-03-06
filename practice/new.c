#include <stdio.h>

int main(void)
{
	int x = 4;
	int *ptr = &x;
	int **ptrl = &ptr;

	printf("ptrl = %p\n", ptrl);
	printf("*ptrl = %p\n", *ptrl);
	printf("**ptrl = %d\n", **ptrl);

	return (0);
}
