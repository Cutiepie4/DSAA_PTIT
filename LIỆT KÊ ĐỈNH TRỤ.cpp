/*
Cho đồ thị vô hướng liên thông G= được biểu diễn dưới dạng danh sách cạnh. 
Sử dụng thuật toán DFS hoặc BFS, hãy đưa ra tất cả các đỉnh trụ của đồ thị?

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: 
dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh và số cạnh; 
Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của 
đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra danh sách các đỉnh trụ của mỗi test  theo từng dòng.
Ví dụ:

Input:
1
5 5
1 2 1 3 2 3 2 5 3 4
Output:
2 3
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define matrix vector <vector <int>>
#define matrixl vector <vector <ll>>
const ll MOD = 1e9 + 7;

matrix M;
vt D;
int n, e;

void dfs(int s, int k) { // k là đỉnh đã bỏ đi
    vt mark(n + 1, 1);
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
            return;
        }
    }
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
