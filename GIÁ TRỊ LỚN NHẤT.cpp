#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define pi pair <int,int>
#define matrix vector <vt>
#define matrixl vector <vtl>
const int MOD = 1e9 + 7;

void solution() {
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        if (a > 0) ans += a;
    }
    cout << ans * 2;
}

int main() {
    faster();
    solution();
    return 0;
}