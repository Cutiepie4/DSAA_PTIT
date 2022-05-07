/*
Cho 5 số nguyên dương A, B, C, D, E. Bạn có thể hoán vị các phần tử cho nhau, hãy đặt các dấu biểu thức +, -, * sao cho biểu thức sau đúng:

[[[A o(1) B] o(2) C] o(3) D] o(4) E = 23

Trong đó: o(1) … o(4) là các phép toán +, -, *.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm 5 số nguyên dương A, B, C, D, E có giá trị không vượt quá 100.

Output: Với mỗi test, in ra đáp án tìm được, mỗi xâu in ra trên một dòng.

Ví dụ:

Input
3
1 1 1 1 1
1 2 3 4 5
2 3 5 7 11

Output
NO
YES
YES
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

vt v;
string op = "+-*";

int back(vt v, int iv, int s) {
    if (iv == v.size()) {
        if (s == 23) return 1;
        return 0;
    }
    for (auto i : op) {
        int sum = s;
        if (i == '+') sum += v[iv];
        else if (i == '-') sum -= v[iv];
        else if (i == '*') sum *= v[iv];
        if (back(v, iv + 1, sum)) return 1;
    }
    return 0;
}

int solution() {
    v = vt(5);
    for (auto& i : v) cin >> i;
    int x = 120;
    while (x--) {
        if (back(v, 1, v.front())) return 1;
        next_permutation(v.begin(), v.end());
    }
    return 0;
}

int main() {
    faster();
    int T;
    cin >> T;
    while (T--) {
        if (solution()) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}