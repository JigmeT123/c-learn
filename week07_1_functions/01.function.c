#include <stdio.h>

int max1(int a, int b)
{
	int m = (a > b) ? a : b;

	return m;
}

int max2(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;

	//	return (a > b) ? a : b;
}

int main()
{
	int c = max1(3, 4); // 4

	printf("%d\n", c);

	printf("%d\n", max1(2, 5));
	printf("%d\n", max2(9, 6));

	return 0;
}

