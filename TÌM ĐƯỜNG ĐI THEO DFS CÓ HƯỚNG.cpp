/*
Cho đồ thị có hướng G= được biểu diễn dưới dạng danh sách cạnh. Hãy tìm đường đi từ đỉnh sÎV đến đỉnh tÎV trên đồ thị bằng thuật toán DFS.

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào bốn số |V|, |E|, sÎV, tÎV tương ứng với số đỉnh, số cạnh,  đỉnh u, đỉnh v; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra đường đi từ đỉnh s đến đỉnh t của mỗi test theo thuật toán DFS của mỗi test theo khuôn dạng của ví dụ dưới đây. Nếu không có đáp án, in ra -1.
      Ví dụ:

Input:
1
6  9  1  6
1 2 2 5 3 1 3 2 3 5 4 3 5 4 5 6 6 4
Output:
1 2 5 6
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

void dfs(matrix& M, vt& mark, int s, int d) {
    vt prev(M.size(), 0);
    stack <int> st;
    st.push(s);
    mark[s] = 0;
    while (!st.empty()) {
        int x = st.top();
        if(x == d) break;
        st.pop();
        for (auto i : M[x]) {
            if (mark[i]) {
                mark[i] = 0;
                st.push(x), st.push(i);
                prev[i] = x;
                break;
            }
        }
    }
    if (!prev[d]) {
        cout << "-1";
    }
    else {
        stack <int> stt;
        int x = prev[d];
        stt.push(d);
        stt.push(x);
        while (x != s) {
            x = prev[x];
            stt.push(x);
        }
        while (!stt.empty()) {
            cout << stt.top() << " ";
            stt.pop();
        }
    }
}

void solution() {
    int n, e, s, d;
    cin >> n >> e >> s >> d;
    matrix M(n + 1);
    vt mark(n + 1, 1);
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
    }
    dfs(M, mark, s, d);
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