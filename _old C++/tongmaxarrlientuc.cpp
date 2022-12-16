/*
Cho mảng A[] gồm n phần tử.
Nhiệm vụ của bạn là tìm tổng lớn nhất các dãy con
liên tục của mảng A[].
Ví dụ với A[] = { -2, -3, 4, -1, -2, 1, 5, -3}
ta có câu trả lời là 7 tương ứng với
tổng lớn nhất của dãy con liên tục {4, -1, -2, 1, 5}.
1≤ T ≤100; 1≤ n  ≤106; -106≤ A[i]  ≤106. 
*/
// khi tính tổng 1 dãy số để nó max thì ta sẽ ko tính phần âm
// phía trước nó. Chính vì thế ta duyệt 1 vòng for để tính tổng 
// các phần tử liên tiếp, nếu tổng tạm thời bị âm thì ta bỏ luôn cả phần
// phía trước, tất nhiên luôn lấy max ở từng bước đối chiếu

#include <bits/stdc++.h>
using namespace std;

long long max_sum_subarr(vector <int> v, int n) {
    long long maxend = INT32_MIN, maxcurr = 0;
    for (int i = 0; i < n; i++) {
        maxcurr += v[i];
        maxend = max(maxend, maxcurr);
        if (maxcurr < 0) maxcurr = 0;
    }
    return maxend;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cout << max_sum_subarr(v, n) << endl;
    }
}