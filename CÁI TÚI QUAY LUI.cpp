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

int n, W, Fopt = INT32_MIN;
vt Xopt;
vector <pi> obj;

void back(int i, int w, int vl, vt optmp) {
    if (i == n) {
        if (vl > Fopt) {
            Xopt = optmp;
            Fopt = vl;
        }
        return;
    }
    vt v = optmp;
    v.push_back(0);
    back(i + 1, w, vl, v);
    int wtmp = w - obj[i].second;
    if (wtmp < 0) return;
    v = optmp;
    v.push_back(1);
    back(i + 1, wtmp, vl + obj[i].first, v);
}

void solution() {
    // fstream in("data.in", ios::in);
    cin >> n >> W;
    obj = vector <pi>(n); // f = vl, s = w
    for (int i = 0; i < n; i++) cin >> obj[i].first;
    for (int i = 0; i < n; i++) cin >> obj[i].second;
    vt tmp;
    back(0, W, 0, tmp);
    cout << Fopt << endl;
    for (auto i : Xopt) cout << i << " ";
    // in.close();
}

int main() {
    faster();
    solution();
    return 0;
}