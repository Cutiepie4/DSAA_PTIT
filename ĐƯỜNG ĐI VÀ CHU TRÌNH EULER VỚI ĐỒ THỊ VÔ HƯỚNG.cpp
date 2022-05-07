/*
Cho đồ thị vô hướng liên thông G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy kiểm tra xem đồ thị có đường đi Euler hay chu trình Euler hay không?


Đường đi Euler bắt đầu tại một đỉnh, và kết thúc tại một đỉnh khác.

Chu trình Euler bắt đầu tại một đỉnh, và kết thúc chu trình tại chính đỉnh đó.

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh,  số cạnh của đồ thị; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra 1, 2, 0 kết quả mỗi test theo từng dòng tương ứng với đồ thị có đường đi Euler, chu trình Euler và trường hợp không tồn tại.
      Ví dụ:







Input:

Output:

2

6  10

1 2 1 3 2 3 2 4 2 5 3 4 3 5 4 5 4 6 5 6

6 9

1  2 1  3 2  3 2  4 2  5 3  4 3  5 4  5 4  6

2

1
*/
#include <bits/stdc++.h>
using namespace std;
#define vt vector <int>
#define mt vector <vt>

int n, e;
mt M;

int solution() {
    cin >> n >> e;
    M = mt(n + 1);
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
        M[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (M[i].size() % 2 == 1) {
            cnt++;
            if (cnt > 2) return 0;
        }
    }
    if (cnt == 0) return 2;
    return 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solution();
        cout << endl;
    }
}