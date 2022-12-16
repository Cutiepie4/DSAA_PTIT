#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <int>>
#define vt vector <int>
#define matrixl vector <vector <ll>>
#define vtl vector <ll>
const ll MOD = 1e9 + 7;

void process(string s) {
    stack <char> st;
    vt mark; 
    int cnt = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(cnt);
            mark.push_back(cnt);
            cnt++;
        }
        else if (s[i] == ')') {
            if (st.empty()) {
                cout << "-1" << endl;
                return;
            }
            mark.push_back(st.top());
            st.pop();
        }
    }
    for (auto i : mark) cout << i << " ";
}

void solution() {
    string s;
    getline(cin, s);
    process(s);
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        solution();
        cout << endl;
    }
    return 0;
}