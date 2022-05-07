#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        stack <string> st;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (isalpha(s[i])) {
                string tmp;
                tmp += s[i];
                st.push(tmp);
            }
            else {
                string x = st.top();
                st.pop();
                string y = st.top();
                st.pop();
                string z = "(" + x + s[i] + y + ")";
                st.push(z);
            }
        }
        cout << st.top() << endl;
    }
}