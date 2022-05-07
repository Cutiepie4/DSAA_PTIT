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
    unordered_map <int, int> ump;
    vt v;
    for (int i = 0, tmp; i < n; i++) {
        cin >> tmp;
        ump[tmp]++;
        v.push_back(tmp);
    }
    for (auto i : v) {
        if (ump[i] > 0) {
            ump[i] = 0;
            cout << i << " ";
        }
    }
}

int main() {
    faster();
    solution();
    return 0;
}