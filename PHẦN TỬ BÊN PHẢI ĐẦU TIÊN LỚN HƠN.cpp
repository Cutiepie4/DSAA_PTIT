#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n;
    cin >> n;
    vector <int> v(n);
    for (auto& i : v) cin >> i;

    stack <int> ans, st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= v[i]) {
            st.pop();
        }
        if (st.empty()) ans.push(-1);
        else ans.push(st.top());
        st.push(v[i]);
    }
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}