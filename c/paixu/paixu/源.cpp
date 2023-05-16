#define _CRT_SECURE_NO_WARNINGS 1



#include <algorithm>
using namespace std;

int main() 
{
    int a, i, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        int myints[] = { a,a + 1,a + 2,a + 3,a + 4 };
        sort(myints, myints + 5);
        do
        {
            printf("%d%d%d%d%d\n", myints[0], myints[1], myints[2], myints[3], myints[4]);
        } while (next_permutation(myints, myints + 5));
    }
    return 0;
}