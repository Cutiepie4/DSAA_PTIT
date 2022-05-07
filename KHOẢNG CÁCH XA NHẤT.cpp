/*
Cho dãy số A[] gồm có N phần tử. Bạn cần tìm 2 vị trí i, j sao cho j-i lớn nhất và A[j] > A[i].

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

Mỗi test gồm số nguyên N (1≤ N ≤ 100 000).

Dòng tiếp theo gồm N số nguyên A[i] (-10^6 ≤ A[i] ≤ 10^6).

Output: 

Với mỗi test, in ra trên một dòng là giá trị của hiệu j-i tìm được.

Ví dụ:

Input:
3
9
34 8 10 3 2 80 30 33 1
6
1 2 3 4 5 6
6
6 5 4 3 2 1

Output
6
5
-1
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
    int n;
    cin >> n;
    vt v(n), a(n, INT32_MIN);
    for (auto& i : v) cin >> i;

    a.back() = v.back();
    for (int i = n - 2; i >= 0; i--) {
        a[i] = max(v[i], a[i + 1]);
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (a[m] > v[i]) {
                l = m + 1;
                ans = max(ans, m - i);
            }
            else r = m;
        }
    }
    cout << ans;
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