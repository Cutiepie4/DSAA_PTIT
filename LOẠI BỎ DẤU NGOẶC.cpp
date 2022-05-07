#include <bits/stdc++.h>
using namespace std;

set <string> Data;
int Max;

int check(string s) {
    if (s.size() < 2) return 0;
    stack <char> st;
    for (auto i : s) {
        if (i == '(') st.push(i);
        else if (i == ')') {
            if (st.empty()) return 0;
            else st.pop();
        }
    }
    if (st.empty()) return 1;
    return 0;
}

void back(string s, int inx) {
    if(s.size() < Max) return;
    if (check(s)) {
        if (s.size() > Max) {
            Data.clear();
            Max = s.size();
        }
        if (s.size() == Max) Data.insert(s);
        return;
    }
    for (int i = inx; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == ')') {
            string tmp = s;
            tmp.erase(tmp.begin() + i);
            back(tmp, i);
        }
    }
}

void solution() {
    Data.clear();
    Max = 0;
    string s;
    cin >> s;
    back(s, 0);
    if (Data.empty()) cout << -1;
    else for (auto i : Data) cout << i << " ";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}