#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[110], id[110], rank[110];
int cmp(int p1, int p2)
{
    return a[p1] > a[p2];
}
int main()
{
    int n = 1000;
    int r, j, i;
    for (i = 1; i <= n; i++)
    {
        r = 0;
        for (j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                r = r + j;
            }
        }
        if (r == i)
        {
            printf("the result is:%d\n", r);
        }
    }
}