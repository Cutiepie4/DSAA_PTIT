/*
Một số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8. Cho số tự nhiên N. Hãy liệt kê các số lộc phát có không quá N chữ số.

Input:

Dòng đầu tiên ghi lại số tự nhiên T là số lượng bộ test (T<10);
T dòng kế tiếp mỗi dòng ghi số N (1<N<15).
  Output:

Dòng đầu tiên là số lượng số lộc phát tìm được. Dòng thứ hai in đáp án theo thứ tự tăng dần.
  Ví dụ:

Input

Output

2

2

3

6

6 8 66 68 86 88

14

6 8 66 68 86 88 666 668 686 688 866 868 886 888

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

vector <vts> Data(15);

void init() {
    Data[1].push_back("6");
    Data[1].push_back("8");
    for (int i = 2; i < 15; i++) {
        for (auto j : Data[i - 1]) {
            Data[i].push_back(j + "6");
            Data[i].push_back(j + "8");
        }
    }
}

void solution() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) cnt += Data[i].size();
    cout << cnt << endl;
    for (int i = 1; i <= n; i++)
        for (auto j : Data[i]) cout << j << " ";
}

int main() {
    faster();
    init();
    int T;
    cin >> T;
    while (T--) {
        solution();
        cout << endl;
    }

    return 0;
}