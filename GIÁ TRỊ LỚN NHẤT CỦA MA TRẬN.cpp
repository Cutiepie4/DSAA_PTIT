/*
Giả sử giá trị của một ma trận là hiệu giữa tổng các số trên đường chéo chính và tổng các số trên đường chéo phụ.
Cho ma trận A kích thước N * N, hãy tìm ma trận con của A sao cho ma trận con đó có giá trị lớn nhất.

Input

Dòng đầu ghi số N (2 ≤ N ≤ 400)

N dòng tiếp theo ghi ma trận A. Các số trong đoạn [-1000, 1000].
*/

#include <bits/stdc++.h>
using namespace std;

void process(vector < vector <pair<int, int>>>& sum, vector <vector <int>> v, int n) {
    for (int z = 1; z <= n; z++) {
        int j = 1, i = z;
        while (j <= n && i <= n) {
            sum[i][j].first = sum[i - 1][j - 1].first + v[i][j];
            sum[j][i].first = sum[j - 1][i - 1].first + v[j][i];
            i++, j++;
        }
    }
    for (int i = 1; i <= n; i++) reverse(v[i].begin(), v[i].end());
    for (int z = 1; z <= n; z++) {
        int j = 1, i = z;
        while (j <= n && i <= n) {
            sum[i][j].second = sum[i - 1][j - 1].second + v[i][j];
            sum[j][i].second = sum[j - 1][i - 1].second + v[j][i];
            i++, j++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n / 2; j++) {
            swap(sum[i][j].second, sum[i][n - j + 1].second);
        }
    }
}

void init(vector <vector <int>>& v, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector <vector <int>> v(n + 2, vector <int>(n + 2, 0));
    vector <vector <pair<int, int>>> sum(n + 2, vector <pair<int, int>>(n + 2, { 0,0 }));
    init(v, n);
    process(sum, v, n);

    int ans = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            int q = min(i, j) - 1;
            while (q >= 1) {
                int x = sum[i][j].first - sum[i - q - 1][j - q - 1].first;
                int y = sum[i][j - q].second - sum[i - q - 1][j + 1].second;
                ans = max(ans, x - y);
                q--;
            }
        }
    }
    cout << ans;
}

/*
//Made By Phuong Nam PROPTIT <3//
#pragma GCC Optimize("O3")
#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define f0(i,n) for(int i=0;i<n;i++)
#define ff(i,b,a) for(int i=b;i>=a;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long ll;
const int N = 1e6 + 3;
const int MOD = 1e9 + 7;
int n, a[500][500];
ll ans = -1e18, b[500][500], c[500][500];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    f1(i, n)
    {
        f1(j, n)
        {
            cin >> a[i][j];
            b[i][j] = b[i - 1][j - 1] + a[i][j];//mang cong don cac dg cheo chinh
        }
    }
    f1(i, n)
    {
        ff(j, n, 1)
        {
            c[i][j] = c[i - 1][j + 1] + a[i][j];
            //mang cong don dg cheo phu
        }
    }
    f1(i, n)
    {
        f1(j, n)
        {
            f1(k, n - max(i, j) + 1)
            {
                ans = max(ans, b[i + k - 1][j + k - 1] - b[i - 1][j - 1] - (c[i + k - 1][j] - c[i - 1][j + k]));
            }
        }
    }
    cout << ans;
}
*/