/*
Một con ếch có thể nhảy 1, 2, 3 bước để có thể lên đến một đỉnh cần đến. Hãy đếm số các cách con ếch có thể nhảy đến đỉnh.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là số n là số bước con ếch có thể lên được đỉnh.
T, n thỏa mãn ràng buộc: 1≤T≤100;  1≤n ≤50.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
1
5

Output
1
13
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll oo = 1e9 + 7;

ll countWays(int n, int m = 3) {
    ll res[n + 1];
    ll temp = 0;
    res[0] = 1;
    for (int i = 1; i <= n; i++) {
        int s = i - m - 1;
        int e = i - 1;
        if (s >= 0) {
            temp -= res[s];
        }
        temp = temp + res[e];
        res[i] = temp;
    }
    return res[n];
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << countWays(n) << endl;
    }
}