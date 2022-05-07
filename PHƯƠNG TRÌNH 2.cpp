/*
Cho , hãy đếm số nghiệm nguyên dương của phương trình:
1/x + 1/y = 1/n
Một dòng duy nhất chứa số nguyên dương n (n <= 10^9)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll res = 1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            int d = 0;
            while (n % i == 0)
            {
                n /= i;
                d++;
            }
            res *= d * 2 + 1; // xét căn n
        }
    }
    if (n > 1)
        res *= (1 * 2 + 1);
    cout << res;
    return 0;
}