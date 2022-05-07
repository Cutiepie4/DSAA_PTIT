/*
Cho N cặp số, trong đó số thứ nhất bao giờ cũng nhỏ hơn số thứ 2. Ta nói, cặp số <c, d> được gọi là theo sau cặp số <a,b> nếu b<c. Nhiệm vụ của bạn là tìm số lớn nhất chuỗi các cặp thỏa mãn ràng buộc trên. Ví dụ với các cặp {<5, 24>, <39, 60>, <15, 28>, <27, 40>, <50, 90>} ta có kết quả là 3 tương ứng với chuỗi các cặp {<5,24>, <27, 40>, <50, 90>}.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào N là số cặp <a, b>; dòng tiếp theo đưa vào 2*N số là N cặp số <a, b>; các số được viết cách nhau một vài khoảng trống.
T, N, a, b thỏa mãn ràng buộc: 1≤T≤100;  1≤N, a, b ≤100.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
5
5  24 39 60 15 28 27 40 50 90
2
5 10 1 11
Output
3
1
*/
#include <bits/stdc++.h>
using namespace std;

int cmp(pair <int, int> a, pair <int, int> b) {
    if (a.second < b.second) return 1;
    if (a.second == b.second && a.first < b.first) return 1;
    return 0;
}

void solution() {
    int n;
    cin >> n;
    vector <pair <int, int>> v(n);
    for (auto& i : v) cin >> i.first >> i.second;

    sort(v.begin(), v.end(), cmp);
    int ans = 0;
    vector <int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j].second < v[i].first) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}