#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vt vector <int>
#define vtl vector <ll>
#define matrix vector <vector <int>>
#define matrixl vector <vector <ll>>
const ll MOD = 1e9 + 7;

vector <set <string>> Data(31);

void out(int n) {
    for (int i = 2; i <= n; i += 2) {
        for (auto j : Data[i]) {
            cout << j << " ";
        }
    }
    cout << endl;
}

void in(string s) {
    string tmp = s;
    reverse(s.begin(), s.end());
    Data[2 * s.size()].insert(tmp + s);
}

void init() {
    queue <string> q;
    q.push(""), q.push("");
    for (int i = 1; i <= 15; i++) {
        queue <string> tmp;
        while (!q.empty()) {
            tmp.push(q.front() + "0");
            in(q.front() + "0");
            tmp.push(q.front() + "1");
            in(q.front() + "1");
            q.pop();
        }
        q = tmp;
    }
}

void solution() {
    int n;
    cin >> n;
    out(n);
}

int main() {
    int t;
    cin >> t;
    init();
    while (t--) {
        solution();
    }
}