#include <stdio.h>

int fun(int n)
{
	if(n==0){
		return 1;
	}
	else
		return 7 + fun(n-2);
}
int main()
{
	printf("%d\n", fun(6));
	return 0;
}
