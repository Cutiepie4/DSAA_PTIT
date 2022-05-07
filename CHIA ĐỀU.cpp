
/*
Cho dãy số A có N phần tử và số K. Hãy đếm số cách chia dãy A thành K nhóm các phần tử liên tiếp sao cho tổng giá trị của mỗi nhóm đều bằng nhau.

Input

Dòng đầu ghi hai số N và K (0 < N ≤ 12; 0 < K < N ).

Dòng thứ 2 ghi N số của dãy A (-10000 ≤ A[i] ≤ 10000)

Output

In ra số cách thỏa mãn

Ví dụ

Input
3 2
-2 0 -2

Output
2

Input
3 2
1 2 3

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

int n, k, sum, ans;
vt v;

void back(int i, int s, int cnt) {
    if (cnt == k && i == n) ans++;
    if (i >= n || cnt >= k) return;
    if (sum == s + v[i]) back(i + 1, 0, cnt + 1);
    back(i + 1, s + v[i], cnt);
}

void solution() {
    sum = 0, ans = 0;
    cin >> n >> k;
    v = vt(n);
    for (auto& i : v) {
        cin >> i;
        sum += i;
    }
    if (sum % k != 0) {
        cout << 0;
        return;
    }
    sum /= k;
    back(0, 0, 0);
    cout << ans;
}

int main() {
    faster();
    solution();
    return 0;
}