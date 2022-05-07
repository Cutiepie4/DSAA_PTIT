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
    cin.ignore();
    matrix M = matrix(n + 1, vt(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);
        string tmp;
        stringstream ss(s);
        while (ss >> tmp) {
            int x = stoi(tmp);
            M[i][x] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    faster();
    solution();
    return 0;
}