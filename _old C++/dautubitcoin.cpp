#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <int>>
#define vt vector <int>
#define matrixl vector <vector <ll>>
#define vtl vector <ll>

void solution() {
    int n;
    cin >> n;
    vt v(n);
    for (auto& i : v) cin >> i;
    int minn = v.front(), maxx = minn, index = 1, ans = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] > maxx) {
            maxx = v[i];
            minn = v[i];
        }
        else if (v[i] < minn) {
            minn = v[i];
            ans = max(ans, maxx - minn);
        }
    }
    cout << ans;
}

int main() {
    solution();
}