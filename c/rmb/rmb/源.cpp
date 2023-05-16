#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>

int main() 
{
    int n, m100 = 0, m50 = 0, m10 = 0, m5 = 0, m2 = 0, m1 = 0, m_10 = 0, m_5 = 0, m_1 = 0;
    int i;
    scanf("%d", &n);  // 有n组数据
    double* aa =(double*) malloc(sizeof(double) * n);
    i = 0;
    while (i<n)
    {
        scanf("%f", &aa[i]);  // 读入一个整数
        i++;
    }
    for (i = 0; i < n; i++) 
    {
     //计算
        int g;
        m100 = 0, m50 = 0, m10 = 0, m5 = 0, m2 = 0, m1 = 0, m_10 = 0, m_5 = 0, m_1 = 0;
        g = aa[i] * 100;
        m_1 = g % 10;
        m_10 = g / 10 % 10;
        m1 = g / 100 % 10;
        m10 = g / 1000 % 10;
        m100 = g / 10000;
        while (m_1 >= 5)
        {
            m_5++;
            m_1 = m_1 - 5;
        }
        while (m1 >= 2) 
        {
            m2++;
            m1 = m1 - 2;
        }
        while (m10 >= 5) 
        {
            m50++;
            m10 = m10 - 5;
        }
        printf("%d,%d,%d,%d,%d,%d,%d,%d,%d\n", m100, m50, m10, m5, m2, m1, m_10, m_5, m_1);  // 输出计算结果
    }
    free(aa);
    return 0;
}
