#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define matrix vector <vector <int>>
#define matrixl vector <vector <ll>>
const ll MOD = 1e9 + 7;

vector <string> Data;

void in(string s) {
    string tmp = s;
    reverse(s.begin(), s.end());
    tmp += s;
    Data.push_back(tmp);
}

void init() {
    queue <string> q;
    q.push("");
    for (int i = 1; i < 14; i++) {
        queue <string> tmp;
        while (!q.empty()) {
            tmp.push(q.front() + "6");
            in(q.front() + "6");
            tmp.push(q.front() + "8");
            in(q.front() + "8");
            q.pop();
        }
        q = tmp;
    }
}

void out(int n) {
    for (int i = 0; i < n; i++) cout << Data[i] << " ";
    cout << endl;
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