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
    vtl v(n);
    for (auto& i : v) cin >> i;
    sort(v.begin(), v.end());
    ll Max = INT32_MIN;
    Max = max(Max, v[0] * v[1]);
    Max = max(Max, v[0] * v[1] * v[2]);
    Max = max(Max, max(v[n - 1] * v[n - 2] * v[n - 3], v[n - 1] * v[n - 2]));
    Max = max(Max, max(v[0] * v[n - 1] * v[n - 2], v[n - 1] * v[0] * v[1]));
    cout << Max;
}

int main() {
    faster();
    solution();
    return 0;
}