/*
Cho một xâu s. Xâu F(s) được xác định bằng cách ghép xâu xâu s ban đầu với xâu s sau khi đã được quay vòng sang bên phải 1 kí tự (kí tự cuối cùng của s được chuyển lên đầu).
Thực hiện liên tiếp các bước cộng xâu như trên với xâu mới thu được, ta có được xâu X.
Nhiệm vụ của bạn là hãy xác định kí tự thứ N trong xâu X là kí tự nào?

Input: Dòng đầu ghi số bộ test T (T<10). Mỗi bộ test gồm một xâu s có độ dài không vượt quá 30 kí tự và số nguyên N (1 ≤ N ≤ 1018).

Output: Với mỗi bộ test ghi ra trên một dòng kí tự tìm được.
Ví dụ:
Input
1
COW 8

Output
C
Giải thích test: COW à COWWCO à COWWCOOCOWWC. Kí tự thứ 8 là ‘C’.
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

vtl dp;
string s;
ll k;

void init(int x) {
    dp.push_back(x);
    for (int i = 1; i < 65; i++) {
        ll tmp = dp[i - 1] * 2;
        dp.push_back(tmp);
        if (tmp >= k) return;
    }
}
// COWWCO  OCOWWC
char back(int n, ll k) {
    if (k <= s.size()) return s[k - 1];
    if (k == dp[n]) {
        if (n == 0) return back(n - 1, k);
        return back(n - 1, dp[n - 1] - 1);
    }
    if (k == dp[n] + 1) return back(n - 1, k - 1);
    if (k > dp[n]) return back(n - 1, k - dp[n] - 1);
    return back(n - 1, k);
}

void solution() {
    dp.clear();
    cin >> s >> k;
    init(s.size());
    cout << back(dp.size() - 1, k);
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