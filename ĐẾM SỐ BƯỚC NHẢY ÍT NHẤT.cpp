/*
#include<bits/stdc++.h>
#include<string>
#include<vector>
#define f(i,a,b) for(int i=a;i<=b;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define f0(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int n, k, a[1005][1005], dem;
void quay(int i, int j, int s) {
    if (i == n && j == n) {
        if (s == k) dem++;
        return;
    }
    if (s > k) return;
    if (i + 1 <= n) quay(i + 1, j, s + a[i + 1][j]);
    if (j + 1 <= n) quay(i, j + 1, s + a[i][j + 1]);
}

void xuly()
{
    dem = 0;
    cin >> n >> k;
    f1(i, n)
    {
        f1(j, n) cin >> a[i][j];
    }
    quay(1, 1, a[1][1]);
    cout << dem << endl;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) xuly();
}
*/
#include <bits/stdc++.h>
using namespace std;

int ans, n;

int process(vector <vector<int>> v, int k, int i, int j) {
    if (k <= 0) {
        if (k == 0) {
            if (i == n && j == n) return 1;
        }
        else return 0;
    }
    if (i < n && j < n) {
        ans += process(v, k - v[i][j + 1], i, j + 1);
        ans += process(v, k - v[i + 1][j], i + 1, j);
    }
    else {
        if (i < n && j == n) ans += process(v, k - v[i + 1][j], i + 1, j);
        if (i == n && j < n) ans += process(v, k - v[i][j + 1], i, j + 1);
    }
    return 0;
}

int main() {
    int t, k;
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n >> k;
        vector <vector<int>> v(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> v[i][j];
        process(v, k - v[1][1], 1, 1);
        cout << ans << endl;
    }
}