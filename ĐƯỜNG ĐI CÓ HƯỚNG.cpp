/*
Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh.

Hãy tìm đường đi từ đỉnh u đến đỉnh v trên đồ thị bằng thuật toán BFS.

Input:
Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E|+1 dòng: dòng đầu tiên đưa vào bốn số |V|, |E|, u, v tương ứng với số đỉnh, số cạnh,  đỉnh xuất phát u, đỉnh kết thúc v;
|E| dòng tiếp theo mỗi dòng đưa vào bộ đôi x, y tương ứng với một cạnh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:
Đưa ra đường đi từ đỉnh s đến đỉnh t của mỗi test theo thuật toán BFS của mỗi test theo khuôn dạng của ví dụ dưới đây. Nếu không có đáp án, in ra -1.
Ví dụ:
Input
1
6 9 1 6
1 2
2 5
3 1
3 2
3 5
4 3
5 4
5 6
6 4

OUTPUT:
1 -> 2 -> 5 -> 6
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

int n, e, s, d;
matrix M;
vt prv;

void trace() {
    if (prv[d] == -1) {
        cout << "-1";
    }
    else {
        stack <int> st;
        st.push(d), st.push(prv[d]);
        int x = prv[d];
        while (x != s) {
            x = prv[x];
            st.push(x);
        }
        cout << s;
        st.pop();
        while (!st.empty()) {
            cout << " -> " << st.top();
            st.pop();
        }
    }
    cout << endl;
}

void bfs() {
    vt mark(n + 1, 1);
    queue <int> q;
    q.push(s);
    mark[s] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto i : M[x]) {
            if (mark[i]) {
                mark[i] = 0;
                q.push(i);
                prv[i] = x;
            }
        }
    }
    trace();
}

void solution() {
    cin >> n >> e >> s >> d;
    M = matrix(n + 1);
    prv = vt(n + 1, -1);
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
    }
    bfs();
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