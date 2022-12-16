/*
Bạn có thể biểu diễn 1 số thành tổng của một số số nguyên tố liên tiếp.
Ví dụ, số 15 có thể biều diễn thành 3+5+7=15.  
Cho số nguyên dương n (1≤n≤100 000) và bạn phải tìm số cách khác nhau biểu diễn n 
thành tổng các số nguyên tố liên tiếp.
*/
#include <iostream>
#include <math.h>
using namespace std;

int ktnt(int a)
{
    if (a < 2)
        return 0;
    else
        for (int i = 2; i <= sqrt(a); i++)
            if (a % i == 0)
                return 0;
    return 1;
}

int main()
{
    int t;
    cin >> t;
    int n;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        int d = 0;
        if (ktnt(n) == 1)
            d++;
        int tg = 0;
        for (int i = 2; i <= n / 2; i++)
        {
            tg = 0;
            if (ktnt(i) == 1)
            {
                for (int j = i; j <= n; j++)
                {
                    if (ktnt(j) == 1)
                    {
                        tg += j;
                        if (tg == n)
                            d++;
                        if (tg > n)
                            break;
                    }
                }
            }
        }
        cout << d << endl;
    }
    return 0;
}