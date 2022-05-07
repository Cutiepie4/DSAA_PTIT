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

ll sqr(ll x) {
    return x * x;
}

ll pow(ll a, ll b) {
    if (b == 0) return 1 % MOD;
    else
        if (b % 2 == 0)
            return sqr(pow(a, b / 2)) % MOD;
        else
            return a * (sqr(pow(a, b / 2)) % MOD) % MOD;
}

void solution() {
    string s;
    cin >> s;
    ll n = stoll(s);
    reverse(s.begin(), s.end());
    ll r = stoll(s);
    cout << pow(n, r);
}

int main() {
    faster();
    int T;
    cin >> T;
    while (T--) {
        solution();
        cout << endl;
    }
    return 0;
}