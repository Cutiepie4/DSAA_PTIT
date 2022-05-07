/*
Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một.

Hãy sắp xếp dãy theo thứ tự giảm dần, sau đó liệt kê tất cả các dãy con (đúng thứ tự trước sau) của A[] có tổng các phần tử là số lẻ.

Các dãy con được liệt kê theo thứ tự từ điển tăng dần.

Input

Dòng đầu ghi số bộ test, mỗi test có 2 dòng:

Dòng đầu ghi số N (2 < N <15)
Dòng thứ 2 ghi N số của dãy A[], các số đều nguyên dương, nhỏ hơn 100 và khác nhau từng đôi một.
Output

Với mỗi test, liệt kê tất cả các dãy con có tổng các phần tử là số lẻ theo thứ tự từ điển tng dần, mỗi dãy con trên một dòng.  

Ví dụ

Input
1
4
2 3 4 5

Output
3
3 2
4 3
4 3 2
5
5 2
5 4
5 4 2
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
matrix S;

void back(int index, int sum, vt path) {
    for (int i = index; i < n; i++) {
        int tmp = sum + v[i];
        vt vtmp = path;
        vtmp.push_back(v[i]);
        if (tmp % 2 == 1) {
            S.push_back(vtmp);
        }
        back(i + 1, sum + v[i], vtmp);
    }
}

void solution() {
    S.clear();
    cin >> n;
    v = vt(n);
    for (auto& i : v) cin >> i;
    sort(v.begin(), v.end(), greater<int>());
    vt tmp;
    back(0, 0, tmp);
    sort(S.begin(), S.end());
    for (auto i : S) {
        for (auto j : i) cout << j << " ";
        cout << endl;
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