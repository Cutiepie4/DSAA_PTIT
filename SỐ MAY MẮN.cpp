/*
Hoàng yêu thích các số may mắn. Ta biết rằng một số là số may mắn nếu biểu diễn thập phân của nó chỉ chứa các chữ số may mắn là 4 và 7. Ví dụ, các số 47, 744, 4 là số may mắn và 5, 17, 467 không phải. Hoàng muốn tìm số may mắn bé nhất có tổng các chữ số bằng n. Hãy giúp anh ấy

Dữ liệu vào: Dòng đầu ghi số bộ test, mỗi bộ test có một dòng chứa số nguyên n (1 ≤ n ≤ 106) — tổng các chữ số của số may mắn cần tìm.

Kết quả: In ra trên 1 dòng số may mắn bé nhất, mà tổng các chữ số bằng n. Nếu không tồn tại số thỏa mãn, in ra -1.

Ví dụ:

Input
2
11
10
Output
47
-1
*/

#include <bits/stdc++.h>
using namespace std;

void out(int cnt4, int cnt7) {
    for (int i = 0; i < cnt4; i++) cout << 4;
    for (int i = 0; i < cnt7; i++) cout << 7;
}

void solution() {
    int n, m;
    cin >> n;
    m = n;
    int cnt4, cnt7;
    cnt7 = n / 28 * 4;
    n %= 28;
    if (n % 7 == 0) return out(0, cnt7);
    if (n % 4 == 0) return out(n / 4, cnt7);

    while (n % 4) {
        n += 7;
        cnt7--;
    }
    if (n > m) return cout << -1, void();
    return out(n / 4, cnt7);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}