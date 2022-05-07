/*
Một xâu nhị phân độ dài n được gọi là thuận nghịch hay đối xứng nếu đảo ngược xâu nhị phân đó ta vẫn nhận được chính nó. Cho số tự nhiên n (n nhập từ bàn phím). Hãy viết chương trình liệt kê tất cả các xâu nhị phân thuận nghịch có độ dài n.  Hai phần tử khác nhau của xâu thuận nghịch được ghi cách nhau một khoảng trống.

Ví dụ với n = 4 ta tìm được 4 xâu nhị phân thuận nghịch như dưới đây.

0 0 0 0
0 1 1 0
1 0 0 1
1 1 1 1
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

vector <vts> D(100);
int n;

void init() {
    D[1].push_back("0");
    D[1].push_back("1");
    for (int i = 2; i <= n / 2; i++) {
        for (auto j : D[i - 1]) {
            D[i].push_back(j + '0');
            D[i].push_back(j + '1');
        }
    }
}

void out() {
    for (auto i : D[n / 2]) {
        string tmp = i;
        reverse(tmp.begin(), tmp.end());
        for (auto j : i) cout << j << " ";
        for (auto j : tmp) cout << j << " ";
        cout << endl;
    }
}

void solution() {
    cin >> n;
    init();
    out();
}

int main() {
    faster();
    solution();
    return 0;
}