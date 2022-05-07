/*
Ta gọi số nguyên dương K là một số BDN nếu các chữ số trong K chỉ bao gồm các 0 hoặc 1 có nghĩa. Ví dụ số K =  101 là số BDN, k=102 không phải là số BDN.

Số BDN của N là số P =M´N sao cho P là số BDN. Cho số tự nhiên N (N<1000), hãy tìm số BDN nhỏ nhất của N.

Ví dụ. Với N=2, ta tìm được số BDN của N là P = 5´2=10. N = 17 ta tìm được số BDN của 17 là P = 653´17=11101.

Input:

Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test;
T dòng kế tiếp mỗi dòng ghi lại một bộ Test. Mỗi test là một số tự nhiên N.
Output:
Đưa ra kết quả mỗi test theo từng dòng.
Input
3
2
12
17

Output
10
11100
11101
*/

#include <bits/stdc++.h>
using namespace std;

string process(int n) {
    queue <pair <string, int>> q;
    q.push({ "1", 1 });
    while (1) {
        if (q.front().second % n == 0) return q.front().first;
        q.front().second %= n;
        q.push({ q.front().first + "0", q.front().second * 10 });
        q.push({ q.front().first + "1", q.front().second * 10 + 1 });
        q.pop();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << process(n) << endl;
    }
}