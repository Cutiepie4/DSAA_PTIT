/*
Cho mảng X[] gồm n phần tử và mảng Y[] gồm m phần tử. Hãy đếm số các cặp xy>yx, trong đó x€X[] và y€Y[]. Ví dụ X[] = {2, 1, 6 }, Y[] = {1, 5} ta có kết quả là 3 cặp (2, 1), (2, 5), (6, 1).

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm ba dòng: dòng đầu tiên đưa vào n, m tương ứng với số phần tử của mảng X[] và Y[]; dòng tiếp theo là n số X[i] của mảng X[]; dòng cuối cùng là m số của mảng Y[]; các số được viết cách nhau một vài khoảng trống.
T, n, m, X[i], Y[j] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n, m ≤105; 0≤ X[i], Y[j] ≤103.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input:
1
3 2
2 1 6
1 5
Output:
3
*/
#include <bits/stdc++.h>
using namespace std;

void Solution() {
    // y = 0 && x > 0 thoả mãn
    // y = 1 && x > 1 thoả mãn
    // x < y thoả mãn
    // special x = 2 -> y >= 5 thoả mãn
    int n, m, cnt = 0;
    cin >> n >> m;
    int x[n], y[m];
    int num3 = 0, num2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        if (x[i] == 3) num3++;
    }
    for (int i = 0; i < m; i++) {
        cin >> y[i];
        if (y[i] == 2) num2++;
    }
    cnt += num3 * num2; // x = 3 && y = 2
    sort(x, x + n); sort(y, y + m);

    int special = 0;
    for (int i = 0; i < m; i++) if (y[i] < 5 && y[i] > 2) special++;

    int i, j = 0;
    for (i = 0; i < m; i++) {
        if (y[i] > 1) break;
        while (x[j] <= y[i]) j++;
        cnt += (n - j);
    }
    int k = 0;
    for (i = j; i < n; i++) {
        while (y[k] <= x[i]) k++;
        if (k >= m) break;
        cnt += (m - k);
        if (x[i] == 2) cnt -= special;
    }
    cout << cnt << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Solution();
    }
    return 0;
}
