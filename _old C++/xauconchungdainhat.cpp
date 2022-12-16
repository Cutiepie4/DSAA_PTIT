#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <int>>
#define vt vector <int>

void solution() {
    string a, b, res;
    cin >> a >> b;
    matrix mt(a.size() + 1, vector <int>(b.size() + 1, 0));
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1]) {
                mt[i][j] = mt[i - 1][j - 1] + 1;
            }
            else {
                if (mt[i - 1][j] >= mt[i][j - 1]) mt[i][j] = mt[i - 1][j];
                else mt[i][j] = mt[i][j - 1];
            }
        }
    }
    cout << mt[a.size()][b.size()] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}