#include <bits/stdc++.h>
using namespace std;

void Calculate(int price[], int n, int a[]) {
    stack <int> st;
    st.push(0);
    a[0] = 1;
    for (int i = 1; i < n; i++) {
        while (!st.empty() && price[st.top()] <= price[i])
            st.pop();
        a[i] = (st.empty()) ? (i + 1) : (i - st.top());
        st.push(i);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int price[n], res[n];
        for (int i = 0; i < n; i++) cin >> price[i];
        Calculate(price, n, res);
        for (int i = 0; i < n; i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}