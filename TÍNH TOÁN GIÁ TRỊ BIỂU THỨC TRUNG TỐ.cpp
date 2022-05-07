#include <bits/stdc++.h>
using namespace std;
#define ll long long

int oprt(char c) {
    if (c == '+' || c == '-') return 1;
    else if (c == '*' || c == '/') return 2;
    return 0;
}

vector <string> cvt(string s) {
    string num = "";
    vector <string> ans;
    stack <char> st;

    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            num.push_back(s[i]);
            if (i == s.size() - 1) ans.push_back(num);
        }
        else {
            if (!num.empty()) ans.push_back(num);
            num.clear();

            if (s[i] == '(') st.push(s[i]);
            else if (s[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    string tmp;
                    ans.push_back(tmp + st.top());
                    st.pop();
                }
                st.pop();
            }
            else {
                while (!st.empty() && oprt(st.top()) >= oprt(s[i])) {
                    string tmp;
                    ans.push_back(tmp + st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }

    while (!st.empty()) {
        if (st.top() != '(') {
            string tmp;
            ans.push_back(tmp + st.top());
        }
        st.pop();
    }
    
    return ans;
}

ll calop(ll x, ll y, string c) {
    if (c == "+") return x + y;
    else if (c == "-") return x - y;
    else if (c == "*") return x * y;
    else if (c == "/") return x / y;
    return 0;
}

ll cal(vector <string> v) {
    stack <ll> st;
    for (auto i : v) {
        if (i == "+" || i == "-" || i == "*" || i == "/") {
            ll y = st.top();
            st.pop();
            ll x = st.top();
            st.pop();
            st.push(calop(x, y, i));
        }
        else st.push(stoll(i));
    }
    return st.top();
}

void solution() {
    string s;
    cin >> s;
    auto v = cvt(s);
    cout << cal(v);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}