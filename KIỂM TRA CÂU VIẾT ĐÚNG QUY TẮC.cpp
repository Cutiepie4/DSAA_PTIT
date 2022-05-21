#include <bits/stdc++.h>
using namespace std;

int check(string s) {
    stack <char> st;
    for (auto i : s) {
        if (i == '(' || i == '[') st.push(i);
        else if (i == ')') {
            if (!st.empty() && st.top() == '(') st.pop();
            else return 0;
        }
        else if (i == ']') {
            if (!st.empty() && st.top() == '[') st.pop();
            else return 0;
        }
    }
    if (st.size()) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        cout << (check(s) ? "YES" : "NO") << endl;
    }
}