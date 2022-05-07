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
    vt v(n);
    for (auto& i : v) cin >> i;
    int k;
    cin >> k;
    for (auto i : v) if (i != k) cout << i << " ";
}

int main() {
    faster();
    solution();
    return 0;
}