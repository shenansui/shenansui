#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <math.h>



int main()
{
	double a, b, c;
	double d, x = 0, y = 0;
	scanf("%lf %lf %lf", &a, &b, &c);
	if (a == 0)
	{
		if (b == 0)
		{
			printf("´íÎó");
		}
		else
		{
			x = -c / b;
		}
	}
	else
	{
		d = b * b - 4 * a * c;
		if (d >= 0)
		{
			if (d == 0)
			{
				x = (-b) / 2 * a * c;
				y = x;
			}
			else
			{
				x = (-b + sqrt(d)) / 2 * a * c;
				y = (-b - sqrt(d)) / 2 * a * c;
			}
		}
		else
		{
			printf("´íÎó");
		}
	}
	printf("%lf %lf", x, y);
	return 0;
}