#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <int>>
#define vt vector <int>
#define matrixl vector <vector <ll>>
#define vtl vector <ll>
const ll MOD = 1e9 + 7;

int prs(string s) {
    stack <char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[') st.push(s[i]);
        else {
            if (s[i] == ')') {
                if (st.empty() || st.top() != '(') return 0;
                st.pop();
            }
            else if (s[i] == ']') {
                if (st.empty() || st.top() != '[') return 0;
                st.pop();
            }
        }
    }
    if(st.empty()) return 1;
    return 0;
}

void solution() {
    string s;
    getline(cin, s);
    if (prs(s)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        solution();
    }
    return 0;
}