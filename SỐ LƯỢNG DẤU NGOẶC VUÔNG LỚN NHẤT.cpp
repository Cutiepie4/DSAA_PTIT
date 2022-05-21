#include <bits/stdc++.h>
using namespace std;
#define vt vector <int>
#define mt vector <vt>

void solution() {
    string s;
    cin >> s;
    s = "@" + s;
    vector <int> count(1001, 0);
    int cnt = 0, ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ']') cnt++;
        count[i] = cnt;
    }
    stack <int> st;
    st.push(0);

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[') st.push(i);
        else {
            if (!st.empty() && ((s[st.top()] == '(' && s[i] == ')') || (s[st.top()] == '[' && s[i] == ']'))) {
                st.pop();
                if (!st.empty()) ans = max(ans, count[i] - count[st.top()]);
                else st.push(i);
            }
            else st.push(i);
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solution();
}