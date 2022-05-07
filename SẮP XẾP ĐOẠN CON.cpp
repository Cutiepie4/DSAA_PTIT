/*
Cho dãy số nguyên A[] độ dài N. Xác định số lượng chỉ số M (M < N) thỏa mãn: nếu sắp xếp đoạn con (A1,…,AM) và (AM+1, …, AN) theo thứ tự tăng dần thì được dãy số A tăng dần.

Input

Dòng đầu tiên ghi số bộ test T
Mỗi bộ test bắt đầu bằng một dòng chứa số N (2 ≤ N ≤ 105)
Dòng tiếp theo ghi N số của dãy A (|Ai| ≤ 109)
Output

Với mỗi bộ test:

Dòng đầu tiên ghi số K là số lượng vị trí M tìm được
Dòng thứ 2 ghi ra K số theo thứ tự tăng dần lần lượt là các chỉ số thỏa mãn. Nếu K = 0 thì dòng này bỏ trống. 
Ví dụ

Input
2
2
2 1
5
2 1 3 5 4

Output
0

2
2 3
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define pi pair <int,int>
#define matrix vector <vt>
#define matrixl vector <vtl>
const int MOD = 1e9 + 7;

void solution() {
    // 2 1 3 5 4
    // 1 1 3 4 4 - tail
    // 2 2 3 5 5 - head
    int n;
    vt ans;
    cin >> n;
    vt v(n), tail(n), head(n);
    for (auto& i : v) cin >> i;
    tail.back() = v.back();
    for (int i = n - 2; i >= 0; i--) {
        tail[i] = min(v[i], tail[i + 1]);
    }
    head.front() = v.front();
    for (int i = 1; i < n; i++) {
        head[i] = max(head[i - 1], v[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        if (head[i] <= tail[i + 1]) {
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans) cout << i << " ";
}

int main() {
    faster();
    int T;
    cin >> T;
    while (T--) {
        solution();
        cout << endl;
    }
    return 0;
}