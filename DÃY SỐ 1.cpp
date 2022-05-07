/*
Cho dãy số A[] gồm n số nguyên dương. Tam giác đặc biệt của dãy số A[] là tam giác được tạo ra bởi n hàng, trong đó hàng thứ 1 là dãy số A[], hàng i là tổng hai phần tử liên tiếp của hàng i-1 (2≤i≤n). Ví dụ A[] = {1, 2, 3, 4, 5}, khi đó tam giác được tạo nên như dưới đây:

[1, 2, 3, 4, 5 ]

[3, 5, 7, 9 ]

[8, 12, 16]

[20, 28]

[48]

            Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào N là số lượng phần tử của dãy số A[]; dòng tiếp theo đưa vào N số của mảng A[].
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤N, A[i] ≤10;
Output:

Đưa ra tam giác tổng của mỗi test theo từng dòng. Mỗi dòng của tam giác tổng được bao bởi ký tự [, ].
Input
1
Output
5
1 2 3 4 5
[1 2 3 4 5]
[3 5 7 9]
[8 12 16]
[20 28]
[48]
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

void out(vt v) {
    cout << "[";
    for (auto i = 0; i < v.size() - 1; i++) cout << v[i] << " ";
    cout << v.back();
    cout << "]";
    cout << endl;
}

void solution() {
    int n;
    cin >> n;
    vt v(n);
    for (auto& i : v) cin >> i;
    out(v);
    while (v.size() > 1) {
        vt tmp;
        for (int i = 0; i < v.size() - 1; i++) {
            tmp.push_back(v[i] + v[i + 1]);
        }
        out(tmp);
        v = tmp;
    }
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