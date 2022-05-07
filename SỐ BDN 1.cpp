/*
Ta gọi số nguyên dương K là một số BDN nếu các chữ số trong K chỉ bao gồm các 0 hoặc 1 có nghĩa. Ví dụ số K = 1, 10, 101. Cho số tự nhiên N (N<263). Hãy cho biết có bao nhiêu số BDN nhỏ hơn N. Ví dụ N=100 ta có 4 số BDN bao gồm các số: 1, 10, 11, 100.

Input:

Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test;
T dòng kế tiếp mỗi dòng ghi lại một bộ Test. Mỗi test là một số tự nhiên N.
            Output:

Đưa ra kết quả mỗi test theo từng dòng.
            Ví dụ:

Input

Output

3

10

100

200

2

4

7
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

vtl D;

void init() {
    queue <string> Q;
    Q.push("1");
    while (Q.front().size() < 18) {
        D.push_back(stoll(Q.front()));
        Q.push(Q.front() + "0");
        Q.push(Q.front() + "1");
        Q.pop();
    }
}

void solution() {
    ll n;
    cin >> n;
    cout << upper_bound(D.begin(), D.end(), n) - D.begin();
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