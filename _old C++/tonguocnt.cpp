/*
Cho N số nguyên.
Nhiệm vụ của bạn là phân tích các số nguyên đã cho dưới dạng tích của các thừa số nguyên tố, sau đó tính tổng các ước số nguyên tố này.

*/
#include <bits/stdc++.h>
#define limit 2000000
using namespace std;
typedef long long ll;


vector<int> p(limit + 1, 0); // p = prime, chua uoc nguyen to lon nhat cua index hien tai
void PhanTichSo()
{
    for (int i = 2; i * i <= limit; i++)
    {
        if (p[i] == 0)
        {
            for (int j = i; j <= limit; j += i)
            {
                if (p[j] == 0)
                    p[j] = i;
            }
        }
    }
    for (int i = 2; i <= limit; i++)
    {
        if (p[i] == 0)
            p[i] = i;
    }
}

int SUM(int a)
{
    int sum = 0;
    while (a != 1)
    {
        sum += p[a];
        a /= p[a];
    }
    return sum;
}

int main()
{
    PhanTichSo();
    int T;
    cin >> T;
    ll sum = 0;
    for (int t = 1; t <= T; t++)
    {
        int a;
        cin >> a;
        if (p[a] != 0)
            sum += SUM(a);
        else
            sum += a;
    }
    cout << sum;
    return 0;
}