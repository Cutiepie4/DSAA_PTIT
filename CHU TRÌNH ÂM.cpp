/*
Cho đồ thị có trọng số G=<V, E> được biểu diễn dưới dạng danh sách cạnh trọng số âm hoặc dương. Hãy viết chương trình xác định xem đồ thị có chu trình âm hay không.

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E|+1 dòng: dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh và số cạnh của đồ thị; |E| dòng tiếp theo mỗi dòng đưa vào bộ ba uÎV, vÎV, w tương ứng với một cạnh cùng với trọng số canh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra 1 hoặc 0 theo từng dòng của mỗi test tương ứng với đồ thị có hoặc không có chu trình âm.
     Ví dụ:

Input:
2
3  3
1  2 -1
2  3  4
3  1 -2
3  3
1  2 -1
2  3  2
3  1 -2

 
Output
0
1
*/
#include <bits/stdc++.h>
using namespace std;
#define vt vector <int>
#define mtp vector <vector <pair <int,int>>>

int n, e;
mtp M;
vt mark;

int bfs_nontree(int st) {
    mark = vt(n + 1, 1);
    queue <pair <int, int>> Q;
    Q.push({ st, 0 });

    while (!Q.empty()) {
        int x = Q.front().first, sum = Q.front().second;
        Q.pop();
        mark[x] = 0;

        for (auto i : M[x]) {
            if (i.first == st && sum + i.second < 0) return 1;
            if (mark[i.first]) {
                Q.push({ i.first, sum + i.second });
            }
        }
    }
    return 0;
}

int solution() {
    cin >> n >> e;
    M = mtp(n + 1);
    for (int i = 0, a, b, c; i < e; i++) {
        cin >> a >> b >> c;
        M[a].push_back({ b, c });
    }
    for (int i = 1; i <= n; i++) {
        if (bfs_nontree(i)) return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cout << solution();
        cout << endl;
    }
}