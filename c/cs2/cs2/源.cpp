#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
    int n, i,o;
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
    {
        int a, b, c, ct = 1;
        scanf("%d%d%d", &a, &b, &c);
        if (0 == a && 0 == b && 0 == c) break;
        int integer = a / b;                        // �����������
        printf("%d.", integer);
        a %= b;         // �������
        o = 1;
            // ����c-1��ģ��ѧ��������С�����c-1λ,��ΪҪ��������,�������һλ��������
        while (o++ < c)
        {
            a *= 10;
            printf("%d", a / b);
            a %= b;
        }
        a *= 10;
        // �ж����һλ����һλ�Ƿ����5,������������
        printf("%d\n", ((a % b) * 10 / b >= 5) ? (a / b + 1) : (a / b));
        
    }
    return 0;
}
