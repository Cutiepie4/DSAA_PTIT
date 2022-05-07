#include <bits/stdc++.h>
using namespace std;

vector <string> S = { "+-", "*/%", "^" };

int cmp(char a) {
    for (int i = 0; i < S.size(); i++) {
        if (S[i].find(a) != -1) return i;
    }
    return -1;
}

void prs(string s) {
    stack <char> st;

    for (auto i : s) {
        if (isalpha(i)) cout << i;
        else if (i == '(') st.push(i);
        else if (i == ')') {
            while (!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && cmp(i) <= cmp(st.top())) {
                cout << st.top();
                st.pop();
            }
            st.push(i);
        }
    }
    while (!st.empty()) {
        if (st.top() != '(') cout << st.top();
        st.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        prs(s);
        cout << endl;
    }
}