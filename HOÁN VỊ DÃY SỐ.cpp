/*
Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một. Hãy liệt kê tất cả các hoán vị của dãy số A[] theo thứ tự tăng dần, tức là hoán vị đầu tiên có giá trị tăng dần từ trái qua phải, hoán vị cuối cùng giảm dần từ trái qua phải.

Input

Dòng đầu ghi số N (1 < N < 9)

Dòng thứ 2 ghi N số của dãy A[] (0 < A[i] < 10000)

Output

Ghi mỗi hoán vị của dãy số trên một dòng

Ví dụ

Input
3

Output
88 77 99
77 88 99
77 99 88
88 77 99
88 99 77
99 77 88
99 88 77
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

int n;
vt v;

void solution() {
    cin >> n;
    v = vt(n);
    for (auto& i : v)cin >> i;
    sort(v.begin(), v.end());
    vt a = v;
    reverse(a.begin(), a.end());
    while (a != v) {
        for (auto i : v) cout << i << " ";
        cout << endl;
        next_permutation(v.begin(), v.end());
    }
    for (auto i : v) cout << i << " ";
    cout << endl;
}

int main() {
    faster();
    solution();
    return 0;
}