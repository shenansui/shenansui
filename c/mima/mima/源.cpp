#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main()
{
	int i, j;
	char a[100];
	gets_s(a);
	printf("√‹¬Î£∫%s\n", a);
	for (i = 0; i <= strlen(a) - 1; i++)
	{
		if (a[i] >= 'a' && a[i] <= 'z')
		{
			a[i] = ('a' + 'z') - a[i];
		}
		else if (a[i] >= 'A' && a[i] <= 'Z')
		{
			a[i] = ('A' + 'Z') - a[i];
		}
		else if(a[i]!=' ')
		{
			printf(" ‰»Î¥ÌŒÛ");
		}
	}
	printf("‘≠Œƒ£∫%s",a);
	return 0;
}














//#include <conio.h>
//#include <stdio.h>
//void main()
//{
//    char str[80];
//    int i;
//    gets_s(str);
//    for (int i = 0; i < 80; i++)
//    {
//        if (str[i] >= 'A' && str[i] <= 'Z')
//        {
//            str[i] = 'A' + 'Z' - str[i];
//        }
//        if (str[i] >= 'a' && str[i] <= 'z')
//        {
//            str[i] = 'a' + 'z' - str[i];
//        }
//    }
//    puts(str);
//}
