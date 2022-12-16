#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define matrix vector <vector <int>>
#define matrixl vector <vector <ll>>
const ll MOD = 1e9 + 7;

struct f {
    pair <float, float> p;
    float ratio;
};

int cmp(f& a, f& b) {
    if (a.ratio > b.ratio) return 1;
    return 0;
}

int n;
float W;
vector <f> D;

void prs() {
    sort(D.begin(), D.end(), cmp);
    float ans = 0;
    for (int i = 0; i < n; i++) {
        if (W >= D[i].p.first) {
            W -= D[i].p.first;
            ans += D[i].p.second;
        }
        else {
            ans += W * D[i].p.second / D[i].p.first;
            cout << setprecision(2) << fixed << ans << endl;
            return;
        }
    }
    cout << setprecision(2) << fixed << ans << endl;
}

void solution() {
    cin >> n >> W;
    D = vector <f>(n);
    for (int i = 0; i < n; i++) {
        cin >> D[i].p.second >> D[i].p.first;
        D[i].ratio = D[i].p.second / D[i].p.first;
    }
    prs();
}

int main() {
    faster();
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}