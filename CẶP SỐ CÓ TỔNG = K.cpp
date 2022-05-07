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
// n = 1e6, k = 1e9
void solution() {
    ll n, k;
    ll cnt = 0;
    cin >> n >> k;
    map <ll, ll> pos, neg;

    for (ll i = 0, tmp; i < n; i++) {
        cin >> tmp;
        if (tmp >= 0) pos[tmp]++;
        else neg[tmp]++;
    }

    for (auto it = pos.begin(); it != pos.end(); it++) {
        if (it->first * 2 == k) {
            cnt += it->second * (it->second - 1) / 2;
        }
        else {
            ll sub = k - it->first;
            if (sub < 0) {
                cnt += neg[sub] * it->second;
                neg[sub] = 0;
                it->second = 0;
            }
            else {
                cnt += it->second * pos[sub];
                it->second = 0;
                pos[sub] = 0;
            }
        }
    }

    for (auto it = neg.begin(); it != neg.end(); it++) {
        if (it->first * 2 == k) {
            cnt += it->second * (it->second - 1) / 2;
        }
        else {
            ll sub = k - it->first;
            if (sub <= 0) {
                if (sub == 0) cnt += it->second * pos[0];
                else {
                    cnt += it->second * neg[sub];
                    it->second = 0;
                    neg[sub] = 0;
                }
            }
        }
    }
    cout << cnt;
}

int main() {
    faster();
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
    return 0;
}