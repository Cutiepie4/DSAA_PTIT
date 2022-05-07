/*
Cho đồ thị có trọng số không âm G=<V, E> được biểu diễn dưới dạng danh sách cạnh trọng số. Hãy viết chương trình tìm đường đi ngắn nhất từ đỉnh uÎV đến tất cả các đỉnh còn lại trên đồ thị.

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E|+1 dòng: dòng đầu tiên đưa vào hai ba số |V|, |E| tương ứng với số đỉnh và uÎV là đỉnh bắt đầu; |E| dòng tiếp theo mỗi dòng đưa vào bộ ba uÎV, vÎV, w tương ứng với một cạnh cùng với trọng số canh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra kết quả của mỗi test theo từng dòng. Kết quả mỗi test là trọng số đường đi ngắn nhất từ đỉnh u đến các đỉnh còn lại của đồ thị theo thứ tự tăng dần các đỉnh.
     Ví dụ:

Input:
1
9  12 1
1  2   4
1  8   8
2  3   8
2  8   11
3  4   7
3  6   4
3  9   2
4  5   9
4  6  14
5  6  10
6  7  2
6  9  6

Output:
0 4 12 19 26 16 18 8 14 
*/
#include <bits/stdc++.h>
using namespace std;;
#define pi pair <int,int>
#define mtp vector <vector <pi>>

int n, e, st;
mtp M;

void Dijktra() {
    priority_queue <pi, vector <pi>, greater <pi>> Q;
    vector <int> D(n + 1, 1e9), prv(n + 1, 0);
    D[st] = 0;
    Q.push({ 0, st });

    while (!Q.empty()) {
        int u = Q.top().second;
        Q.pop();

        for (auto i : M[u]) {
            int D_u_v = i.first, v = i.second;
            if (D[v] > D[u] + D_u_v) {
                prv[v] = u;
                D[v] = D[u] + D_u_v;
                Q.push({ D[v], v });
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << D[i] << " ";
}

void solution() {
    cin >> n >> e >> st;
    M = mtp(n + 1);
    for (int i = 0, u, v, ts; i < e; i++) {
        cin >> u >> v >> ts;
        M[u].push_back({ ts, v });
        M[v].push_back({ ts, u });
    }
    Dijktra();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}