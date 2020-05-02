#define ALL(x) (x).begin(), (x).end()
#define _s(x) sort(ALL(x))
#define _so(x, f) sort(ALL(x), f)
#define _ms(x, b) memset(x, b, sizeof(x))
#define _mc(x, b) memcpy(x, b, sizeof(x))
#define _c(n, v) cout << n << "[" << v << "]" << endl
#define _f(i, a, b) for (i = a; i <= b; ++i)
typedef long long ll;
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cctype>
#include <string>
#include <iomanip>
using namespace std;

template <typename x>
x jc(x a[], int size)
{
    int i;
    x max = a[1];
    _f(i, 0, size - 1)
    {
        if (max < a[i])
            max = a[i];
    }
    x min = a[1];
    _f(i, 0, size - 1)
    {
        if (min > a[i])
            min = a[i];
    }
    return max - min;
}
float fc(float *arr, int size)
{
    int i;
    float avg = 0, sum = 0;
    _f(i, 0, size - 1)
    {
        avg += arr[i];
    }
    avg=avg/size;
    _f(i, 0, size - 1)
    {
        sum += (arr[i] - avg) * (arr[i] - avg);
    }
    return sum/size;
}

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int i = 0, j = 0;
    int T, n[100];
    float np[100][1000];

    cin >> T;
    _f(i, 0, T - 1)
    {
        cin >> n[i];
        _f(j, 0, n[i] - 1)
        {
            cin >> np[i][j];
        }
    }

    _f(i, 0, T - 1)
    {
        int temp = jc(np[i], n[i]);
        printf("%d ", temp);
        printf("%.3lf\n", fc(np[i], n[i]));
    }

    return 0;
}