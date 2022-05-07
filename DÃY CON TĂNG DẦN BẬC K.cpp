/*
Cho dãy gồm N số phân biệt AN = {a1, a2, .., aN } và số tự nhiên K (K<=N<=100). Ta gọi một dãy con tăng dần bậc K của dãy số AN là một dãy các số gồm K phần tử trong dãy đó thỏa mãn tính chất tăng dần. Bài toán được đặt ra là in ra màn hình  số các dãy con tăng dần bậc K của dãy số AN. Ví dụ :

Input:  5 3

2 5 15 10 20

Dòng đầu tiên ghi lại hai số N và K tương ứng với số phần tử của dãy số và bậc của dãy con.
Dòng kế tiếp : N số của dãy số AN, các số trong dãy không lớn hơn 100. 
thì Output : 7 (số các dãy con tăng dần bậc 3 của dãy số AN)
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

void back(int index, int cnt) {
    if (cnt == k) {
        ans++;
        return;
    }
    for (int i = index + 1; i < n; i++) {
        if (v[i] > v[index]) {
            back(i, cnt + 1);
        }
    }
}

void solution() {
    ans = 0;
    cin >> n >> k;
    v = vt(n);
    for (auto& i : v) cin >> i;
    for (int i = 0; i < n - k; i++) {
        back(i, 1);
    }
    cout << ans;
}

int main() {
    faster();
    solution();
    return 0;
}