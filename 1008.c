#include <stdio.h>

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);

	printf("%.15f\n", (double)a / b);

	return 0;
}
