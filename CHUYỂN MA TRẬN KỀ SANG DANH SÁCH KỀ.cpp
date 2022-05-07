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
    vector <vector <int>> M(n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            if (tmp) M[i + 1].push_back(j + 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto j : M[i]) cout << j << " ";
        cout << endl;
    }
}

int main() {
    faster();
    solution();
    return 0;
}