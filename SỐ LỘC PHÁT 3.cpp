/*
Một số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8. Cho số tự nhiên N. Hãy liệt kê các số lộc phát có không quá N chữ số.

Input:

Dòng đầu tiên ghi lại số tự nhiên T là số lượng bộ test (T<10);
T dòng kế tiếp mỗi dòng ghi số N (1<N<15).
Output:

Dòng đầu tiên là số lượng số lộc phát tìm được. Dòng thứ hai in ra đáp án theo thứ tự giảm dần.
 Ví dụ:

Input
2
2
3
OUTPUT:
6
88 86 68 66 8 6
14
888 886 868 866 688 686 668 666 88 86 68 66 8 6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <int>>
#define vt vector <int>
#define matrixl vector <vector <ll>>
#define vtl vector <ll>
const ll MOD = 1e9 + 7;

vector <string> Data;
vt cnt(15, 0);

void out(int n) {
    // cout << cnt[n] << endl;
    for (int i = Data.size() - 1; i >= 0; i--) {
        if (Data[i].size() <= n) cout << Data[i] << " ";
    }
    cout << endl;
}

void init() {
    queue <string> q;
    cnt[1] = 2;
    q.push("6"), q.push("8");
    Data.push_back("6");
    Data.push_back("8");
    for (int i = 2; i < 15; i++) {
        queue <string> tmp;
        while (!q.empty()) {
            tmp.push(q.front() + "6");
            Data.push_back(q.front() + "6");
            tmp.push(q.front() + "8");
            Data.push_back(q.front() + "8");
            q.pop();
        }
        cnt[i] = tmp.size();
        q = tmp;
    }
    for (int i = 1; i < 15; i++) cnt[i] += cnt[i - 1];
}

void solution() {
    int n;
    cin >> n;
    out(n);
}

int main() {
    int t;
    cin >> t;
    init();
    while (t--) {
        solution();
    }
    return 0;
}