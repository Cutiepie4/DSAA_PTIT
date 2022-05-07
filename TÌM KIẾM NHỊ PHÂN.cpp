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

int bs(vt v, int k) {
    int l = 0, r = v.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (v[mid] < k) l = mid + 1;
        else r = mid;
    }
    if (v[l] == k) return l;
    return -1;
}

void solution() {
    int n, k;
    cin >> n >> k;
    vt v(n);
    for (auto& i : v) cin >> i;
    int ans = bs(v, k);
    if (ans != -1) cout << ans + 1;
    else cout << "NO";
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