/*
Cho số tự nhiên N và thực hiện trừ N lần lượt N đi chữ số đầu tiên của N để N trở về 0. Ví dụ với N=13 ta thực hiện các phép dịch chuyển N về 0 như sau:

Bước 1: N=N-1 = 13-1=12
Bước 2: N=N-1 = 12-1=11
Bước 3: N=N-1 = 11-1=10
Bước 4: N=N-1 = 10-1=9
Bước 5: N=N-1 = 9-9=0
Cho K là số các phép dịch chuyển N về 0 theo nguyên tắc kể trên. Nhiệm vụ của bạn là tìm số N lớn nhất từ xuất phát điểm ban đầu.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là số tự nhiên K được viết trên một dòng.
T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤106.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
1
2

OUTPUT
9
10
*/

#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define PI 3.141592653589793238
#define endl '\n'

bool isprime(int x)
{
    if (x < 2) return 0;
    if (x == 2) return 1;
    if (x % 2 == 0) return 0;
    if (x == 3) return 1;
    if (x % 3 == 0) return 0;
    int t = 1;
    double sqr = sqrt(x);
    for (int i = 5; i <= sqr; i += (1 + t) << 1)
    {
        if (x % i == 0) return 0;
        t = 1 - t;
    }
    return 1;
}

int a[1000005] = {};
int b[1000005] = {};

int main()
{
    faster();
    FOR(i, 1, 1e6)
    {
        int x = i;
        while (x > 9) x /= 10;
        a[i] = a[i - x] + 1;
        b[a[i]] = max(b[a[i]], i);
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << b[n] << endl;
    }
    return 0;
}