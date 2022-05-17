#include <bits/stdc++.h>
using namespace std;
#define vt vector <int>
#define mt vector <vt>
#define mts vector <vector <string>>

const string Hex = "123456789ABCDEF";
int n;
mt M;
mts Path;

int Pow(string s) {
    reverse(s.begin(), s.end());
    int res = 0;
    for (int i = 0; i < 4; i++) {
        if (s[i] == '1') res += pow(2, i);
    }
    return res;
}

string bin_to_hex(string s) {
    string ans;
    while (s.size() % 4 != 0) s.insert(s.begin(), '0');
    for (int i = 0; i < s.size(); i += 4) {
        string tmp = s.substr(i, 4);
        ans += Hex[Pow(tmp) - 1];
    }
    while (ans.front()) ans.erase(ans.begin());
    return ans;
}

string bfs() {
    mt mark = mt(n, vt(n, 1));
    queue <pair <int, int>> Q;
    Q.push({ 0,0 });
    Path[0][0] = to_string(M[0][0]);

    while (Q.size()) {
        int x = Q.front().first, y = Q.front().second;
        Q.pop();

        if (x + 1 <= n - 1) {
            if (mark[x + 1][y]) {
                Q.push({ x + 1, y });
                mark[x + 1][y] = 0;
            }
            Path[x + 1][y] = max(Path[x][y] + to_string(M[x + 1][y]), Path[x + 1][y]);
        }
        if (y + 1 <= n - 1) {
            if (mark[x][y + 1]) {
                Q.push({ x, y + 1 });
                mark[x][y + 1] = 0;
            }
            Path[x][y + 1] = max(Path[x][y] + to_string(M[x][y + 1]), Path[x][y + 1]);
        }
    }
    return bin_to_hex(Path[n - 1][n - 1]);
}

int main() {
    cin >> n;
    M = mt(n, vt(n));
    Path = mts(n, vector <string>(n, "0"));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }
    cout << bfs();
}