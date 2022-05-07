#include <bits/stdc++.h>
using namespace std;

int check(string s) {
    stack <char> st;
    for (auto i : s) {
        if (i != ')') st.push(i);
        else {
            int cnt = 0;
            while (!st.empty() && st.top() != '(') {
                st.pop();
                cnt++;
            }
            if (cnt < 2) return 0;
            st.pop();
            st.push('a');
        }
    }
    return 1;
}

void solution() {
    string s;
    cin >> s;
    cout << (check(s) ? "No" : "Yes");
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}