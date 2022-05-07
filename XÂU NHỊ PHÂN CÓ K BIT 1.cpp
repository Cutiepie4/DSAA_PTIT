/*
Hãy in ra tất cả các xâu nhị phân độ dài N, có K bit 1 theo thứ tự từ điển tăng dần.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test gồm 2 số nguyên N, K (1 ≤ K ≤ N ≤ 16).

Output:  Với mỗi test, in ra đáp án tìm được, mỗi xâu in ra trên một dòng.
Ví dụ:
Input
2
4 2
3 2
Output
0011
0101
0110
1001
1010
1100
011
101
110
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

int n, k;
vts S;

void back(string s, int cnt, int i) {
    if (cnt == k) {
        S.push_back(s);
        return;
    }
    if (i == s.size()) {
        return;
    }

    if (cnt < k) {
        s[i] = '1';
        back(s, cnt + 1, i + 1);
        s[i] = '0';
        back(s, cnt, i + 1);
    }
}

void solution() {
    S.clear();
    cin >> n >> k;
    string s;
    for (int i = 0; i < n; i++) s += "0";
    back(s, 0, 0);
    sort(S.begin(), S.end());
    for (auto i : S) cout << i << endl;
}

int main() {
    faster();
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}