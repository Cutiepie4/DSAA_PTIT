/*
Cho dãy số A[] gồm có N phần tử.  Một dãy con liên tiếp được gọi là dãy tam giác nếu như dãy đó tăng dần rồi lại giảm dần, hay tồn tại i, j, k sao cho A[i] ≤ A[i+1] ≤ … ≤ A[k] ≥ A[k+1] ≥ … ≥ A[j].

Nhiệm vụ của bạn là hãy tìm dãy con liên tiếp là dãy tam giác có độ dài lớn nhất.

Lưu ý: Dãy đơn điệu không giảm hoặc không tăng cũng là dãy tam giác. Ví dụ A[] = {10, 20, 30, 40} là một dãy tam giác.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

Mỗi test gồm số nguyên N(1≤ N ≤ 100 000).

Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 106).

Output: 

Với mỗi test, in ra trên một dòng là độ dài của dãy con tìm được.

Ví dụ:

Input
2
6
12 4 78 90 45 23
8
20 4 1 2 3 4 2 10
OUTPUT
5
5

Giải thích test 1:
Dãy tìm được là 4, 78, 90, 45, 23
*/

#include <bits/stdc++.h>
using namespace std;

void TestCase() {
    int n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> L(n), R(n);
    L[0] = R[n - 1] = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1]) L[i] = L[i - 1] + 1;
        else L[i] = 1;
    }
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] > a[i + 1]) R[i] = R[i + 1] + 1;
        else R[i] = 1;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, L[i] + R[i] - 1);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 1; cin >> T;
    while (T--) {
        TestCase();
        cout << "\n";
    }
    return 0;
}