/*
Cho dãy số A[] gồm có N phần tử.

Nhiệm vụ của bạn là hãy đếm số bộ ba (i, j, k) mà A[i] + A[j] + A[k] < K cho trước.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm số nguyên N và K (1≤ N ≤5000, -109 ≤ K ≤ 109).

Dòng tiếp theo gồm N số nguyên A[i] (-109 ≤ A[i] ≤ 109).

Output: 

Với mỗi test, in ra trên một dòng là đáp án tìm được.

Ví dụ:

Input
2
4 2
-2 0 1 3
5 12
5 1 3 4 7

Output
2
4
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
// 1 3 4 5 7
void solution() {
    ll n, k, cnt = 0;
    cin >> n >> k;
    vtl v(n);
    for (auto& i : v) cin >> i;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll tmp = k - v[i] - v[j];
            cnt += (lower_bound(v.begin() + j + 1, v.end(), tmp) - v.begin()) - j - 1;
        }
    }
    cout << cnt;
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