#include <bits/stdc++.h>
using namespace std;

int check(string s) {
    stack <char> st;
    for (auto i : s) {
        if (i == '(' || i == '[' || i == '{') st.push(i);
        else {
            if (i == ')') {
                if (st.empty() || st.top() != '(') return 0;
                else st.pop();
            }
            if (i == ']') {
                if (st.empty() || st.top() != '[') return 0;
                else st.pop();
            }
            if (i == '}') {
                if (st.empty() || st.top() != '{') return 0;
                else st.pop();
            }
        }
    }
    return 1;
}

void solution() {
    string s;
    cin >> s;
    cout << (check(s) ? "YES" : "NO");
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}