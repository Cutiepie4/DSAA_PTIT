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

int check(int a, int b, int c, int d) {
    if ((a == c && b == d) || (a == d && b == c)) return 1;
    return 0;
}

void solution() {
    int n;
    cin >> n;
    vt v(n);
    for (auto& i : v) cin >> i;
    vt v1 = v;
    sort(v1.begin(), v1.end());
    int l = 0, r = n - 1;
    while (l < r) {
        if (!check(v[l], v[r], v1[l], v1[r])) {
            cout << "No";
            return;
        }
        l++, r--;
    }
    cout << "Yes";
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