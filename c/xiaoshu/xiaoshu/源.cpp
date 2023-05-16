#define _CRT_SECURE_NO_WARNINGS 1



#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

	int nn, i = 0, sl = 0, zs = 0, zsl = 0, jgl = 0;
	int a = 0, b = 0, c = 0;
	int  e, f;
	double d;
	scanf("%d", &nn);
	int* sj = 0;
	char** jg = 0;
	sj = (int*)malloc(sizeof(int) * nn * 3);
	jg = (char**)malloc(sizeof(char*) * nn);
	while (i < 3 * nn)
	{
		scanf("%d", &sj[i]);
		if ((i + 1) % 3 == 0)
		{
			zs = sj[i - 2] / sj[i - 1];
			if (zs == 0)
			{
				zsl = 1;
			}
			while (zs % 10 != 0)
			{
				zsl++;
				zs /= 10;
			}
			sl = sj[i] + 2 + zsl;
			jg[(i + 1) / 3 - 1] = (char*)malloc(sizeof(char) * sl+1);
			jg[(i + 1) / 3 - 1][0] = sl + 1;
			zsl = 0;
		}
		i++;
	}
	for (i = 0; i < nn; i++)
	{
		e = sj[i * 3];
		f = sj[i * 3 + 1];
		zs = e / f;
		while (zs % 10 != 0)
		{
			zsl++;
			zs /= 10;
		}
		c = zsl;
		for (a = 1; a < jg[i][0]; a++)
		{
			if (zsl > 0)
			{
				if (a <= zsl)
				{
					if (a == 1)
					{
						if (zsl > 1)
						{
							d = e / (pow(10,zsl-1));
							b = d / f;
						}
						else
						{
							b = e / f;
						}
					}
					else
					{
						e = e % f;
						e = e * 10;
						b = e / f;
					}
				}
				if(a > zsl+1)
				{
					e = e % f;
					e = e * 10;
					b = e / f;
				}
			}
			else
			{
				if (a == 1)
				{
					b = 0;
				}
				if(a >= 3)
				{
					d = e % f;
					e = e * 10;
					b = d / f;
				}
			}
			if (a == zsl+1)
			{
				jg[i][a] = (char)46;
			}
			if(a <= zsl)
			{
				jg[i][a] = (char)(b + 48);
			}
			if(a>zsl+1&& a < jg[i][0])
			{
				jg[i][a] = (char)(b + 48);
			}
			if (a == jg[i][0])
			{
				jg[i][a] = (char)10;
				if (i == nn - 1)
				{
					jg[i][a] = 0;
				}
			}
		}
	}
	for (i = 0; i < nn; i++)
	{
		for (a = 1; a < jg[i][0]; a++)
		{
			printf("%c", jg[i][a]);
		}
	}
	free(sj);
	for (i = 0; i < nn; i++)
	{
		free(jg[i]);
	}
	free(jg);
}