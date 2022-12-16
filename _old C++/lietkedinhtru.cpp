/*
Một thành phố có N điểm nút giao thông. Các tuyến 
đường hai chiều được thiết kế giúp cho 
người dân có thể đi từ một nút bất kỳ đến tất cả 
các nút còn lại.

Những nút giao thông trọng yếu được định nghĩa 
là nút giao thông mà nếu các con đường đến nó đều 
bị chặn thì thành phố sẽ bị chia cắt, tức là khi đó sẽ có những cặp điểm nút không thể đi đến nhau được nữa.

Giả sử các điểm nút giao thông được đánh số từ 1 
đến N. Hãy liệt kê các nút giao thông trọng yếu 
theo thứ tự tăng dần.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define fi first
#define se second
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define matrix vector <vector <int>>
#define matrixl vector <vector <ll>>
const ll MOD = 1e9 + 7;

matrix M;
vt D;
int n, e;

int dfs(int s, int k) {
    vt mark(n + 1, 1);
    mark[0] = 0;
    mark[k] = 0;
    mark[s] = 0;
    stack <int> st;
    st.push(s);
    while (!st.empty()) {
        int x = st.top();
        st.pop();
        for (auto i : M[x]) {
            if (mark[i]) {
                mark[i] = 0;
                st.push(x), st.push(i);
                break;
            }
        }
    }
    for (auto i : mark) {
        if (i) {
            D.push_back(k);
            return 1;
        }
    }
    return 0;
}

void solution() {
    D.clear();
    cin >> n >> e;
    M = matrix(n + 1);
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
        M[b].push_back(a);
    }
    dfs(2, 1);
    for (int i = 2; i <= n; i++) {
        dfs(1, i);
    }
    // cout << D.size() << endl;
    for (auto i : D) cout << i << " ";
    cout << endl;
}

int main() {
    faster();
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}
