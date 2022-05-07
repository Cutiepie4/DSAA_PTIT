/*
Giả sử bạn đang ở điểm có tọa độ nguyên dương (n,m) và cần dịch chuyển về tọa độ (0,0). Mỗi bước dịch chuyển bạn chỉ được phép dịch chuyển đến tọa độ (n-1, m) hoặc (n, m-1); Từ ô (0,m), hoặc (n, 0) thì có thể di chuyển 1 bước để về gốc (0,0).

Hãy đếm số cách bạn có thể dịch chuyển về tọa độ (0,0).

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ n, m được viết cách nhau một vài khoảng trống.
T, n, m thỏa mãn ràng buộc: 1≤T≤100;  1≤n, m ≤25.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
3
3 2
3 6
3 0
Output
10
84
1
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vtl vector <ll>
#define mtl vector <vtl>

mtl M(26, vtl(26, 1));

void init() {
    M[0][0] = 0;
    for (int i = 1; i < 26; i++) {
        for (int j = 1; j < 26; j++) {
            M[i][j] = M[i - 1][j] + M[i][j - 1];
        }
    }
}

void solution() {
    int r, c;
    cin >> r >> c;
    cout << M[r][c];
}

int main() {
    faster();
    init();
    int T;
    cin >> T;
    while (T--) {
        solution();
        cout << endl;
    }
    return 0;
}