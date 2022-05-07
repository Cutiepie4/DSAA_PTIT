/*
Có n tờ tiền có giá trị t[1], t[2], …, t[n].

Hãy tìm cách trả ít tờ tiền nhất với số tiền đúng bằng S

Chú ý: Các tờ tiền có giá trị bất kỳ và có thể bằng nhau, mỗi tờ tiền chỉ được dùng một lần.

Input

Mỗi bộ test gồm 2 số nguyên n và S (n ≤ 30; S  ≤  109).

Dòng thứ hai chứa n số nguyên t[1], t[2], …, t[n] (t[i] ≤ 109)

Output: 

Ghi ra trên một dòng số tờ tiền ít nhất phải trả.

Nếu không thể tìm được kết quả, in ra -1.

Ví dụ

Input
3 5
1 4 5

Output
1
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

int n, k, ans;
vt v;

int back(int index, int sum, int cnt) {
    if (sum == k) {
        ans = min(cnt, ans);
        return 1;
    }
    for (int i = index; i < n; i++) {
        int sumtmp = sum + v[i];
        if (sumtmp <= k && back(i + 1, sumtmp, cnt + 1)) return 1;
        if (back(i + 1, sum, cnt)) return 1;
    }
    return 0;
}

void solution() {
    cin >> n >> k;
    ll tmp, kt = 0;
    v = vt(n);
    ans = n + 1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == k) kt = 1;
        tmp += v[i];
    }
    if (kt) {
        cout << 1;
        return;
    }
    if (tmp < k) {
        cout << -1;
        return;
    }
    sort(v.begin(), v.end(), greater <int>());
    if (back(0, 0, 0)) cout << ans;
    else cout << -1;
}

int main() {
    faster();
    solution();
    return 0;
}