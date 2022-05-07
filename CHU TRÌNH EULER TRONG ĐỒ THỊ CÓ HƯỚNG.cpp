/*
Cho đồ thị có hướng liên thông yếu G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy kiểm tra xem đồ thị có chu trình Euler hay không?

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh,  số cạnh của đồ thị; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra 1, 0 kết quả mỗi test theo từng dòng tương ứng với đồ thị có chu trình Euler và trường hợp không tồn tại đáp án.
      Ví dụ:

Input:

Output:

2

6  10

1 2 2 4 2 5 3 1 3 2 4 3 4 5 5 3 5 6 6 4

3 3

1 2 2 3 1 3

1

0


*/
#include <bits/stdc++.h>
using namespace std;
#define vt vector <int>
#define mt vector <vt>

int n, e;

int solution() {
    cin >> n >> e;
    vector <pair <int, int>> deg(n + 1);
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        deg[a].first++;
        deg[b].second++;
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i].first != deg[i].second) return 0;
    }
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