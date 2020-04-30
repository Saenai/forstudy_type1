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
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        id[i] = i;
    }
    sort(id, id + n, cmp);
    rank[id[0]] = 0;
    for (int i = 1; i < n; ++i)
    {
        if (a[id[i]] == a[id[i - 1]])
            rank[id[i]] = rank[id[i - 1]];
        else
            rank[id[i]] = i;
    }
    for (int i = 0; i < n; ++i)
        printf("%d:%d\n", a[i], rank[i] + 1);
    return 0;
}