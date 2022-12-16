#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    if (m < 2 || n < 1 || k == m + n)
    {
        cout << "0";
        return 0;
    }
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > k)
            break;
        int xx = m - (k - i);
        int xy = n - i;
        if (xx <= 0 || xy <= 0)
            continue;
        int x = min(xx / 2, xy);
        total = max(total, x);
    }
    cout << total;
}