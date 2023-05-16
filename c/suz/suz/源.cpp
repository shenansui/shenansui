#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


int func(long long n);
int min(long long, long long);


int main()
{
	int n, i;
	scanf("%d", &n);
	long long x;
	for (i = 0; i < n; i++) {
		scanf("%lld", &x);
		printf("%d\n", func(x));
	}
}
int func(long long n)
{
	if (n == 1)
		return 0;

	if (n % 2 == 0)
		return 1 + func(n / 2);
	else
		return 1 + min(func(n - 1), func(n + 1));

}
int min(long long a, long long b) {
	int t = a;
	if (a >= b)
		t = b;
	return t;
}
