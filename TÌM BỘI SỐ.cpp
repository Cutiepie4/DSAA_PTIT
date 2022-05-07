/*
Cho số nguyên N. Nhiệm vụ của bạn cần tìm số nguyên X nhỏ nhất là bội của N, và X chỉ chứa hai chữ số 0 và 9.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 10000). Mỗi bộ test chứa số nguyên N trên một dòng (1 ≤ N ≤ 500).

Output:  Với mỗi test in ra đáp án tìm được trên một dòng.

Ví dụ:
Input
3
2
5
11

Output
90
90
99
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

vector <string> Data(501, "@");

void solution() {
    int n;
    cin >> n;
    if(Data[n] != "@") {
        cout << Data[n];
        return;
    }
    queue <pair <string, int>> Q;
    Q.push({ "9", 9 % n });
    while(1) {
        if(Q.front().second % n == 0) {
            cout << Q.front().first;
            Data[n] = Q.front().first;
            return;
        }
        Q.front().second %= n;
        Q.push({Q.front().first + "0", Q.front().second * 10});
        Q.push({Q.front().first + "9", Q.front().second * 10 + 9});
        Q.pop();
    }
}

int main() {
    faster();
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
    return 0;
}