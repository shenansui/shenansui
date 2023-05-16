#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>



#include <stdio.h>
unsigned long long jie(int);
int main()
{
	int m, n, k;
	scanf("%d %d %d", &m, &n, &k);
	if (k > n)
		printf("Input Error");
	else {
		unsigned long long sum = 0;
		int i;
		sum = jie(n) / jie(n - k);
		for (i = k + 1; i <= m; i++) {
			sum *= (n - k + 1);
		}
		printf("%llu", sum);
	}

	return 0;
}
unsigned long long jie(int a)
{
	int i;
	unsigned long long sum = 1;
	if (a == 0)
		return 1;
	for (i = 1; i <= a; i++) {
		sum *= i;
	}
	return sum;
}
