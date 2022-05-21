/*
Hãy xây dựng một cây nhị phân tìm kiếm cân bằng từ dãy số A[] =(a0, a1, .., an-1}. Đưa ra nội dung node gốc của cây tìm kiếm cân bằng.  Ví dụ với dãy A[]={40, 28, 45, 38, 33, 15, 25, 20, 23, 35, 30} ta sẽ có cây nhị phân tìm kiếm cân bằng với node gốc là 33.

     Input:

Dòng đầu tiên đưa vào số lượng bộ test T (T≤100).
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất là số tự nhiên N (N≤106). Dòng tiếp theo là N số của mảng A[].
     Output:

Đưa ra kết quả mỗi test theo từng dòng.
     Ví dụ:

Input

Output

2

11

40  28  45 38  33  15  25  20  23  35  30

10

1  2  3  4  5  6  7  8  9  10

Output
30
5
*/
#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n;
    cin >> n;
    vector <int> v(n);
    for (auto& i : v) cin >> i;
    sort(v.begin(), v.end());
    if (n % 2) cout << v[n / 2];
    else cout << v[n / 2 - 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}