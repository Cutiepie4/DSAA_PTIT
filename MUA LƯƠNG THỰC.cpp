/*
Giả sử bạn là một người nghèo trong địa phương của bạn. Địa phương của bạn có duy nhất một cửa hàng bán lương thực. Cửa hàng của bạn mở cửa tất cả các ngày trong tuần ngoại trừ chủ nhật. Cho bộ ba số N, S, M thỏa mãn ràng buộc sau:

N : số đơn vị lương thực nhiều nhất bạn có thể mua trong ngày.
S : số lượng ngày bạn cần được sử dụng lương thực để tồn tại.
M : số đơn vị lương thực cần có mỗi ngày để bạn tồn tại.
Giả sử bạn đang ở ngày thứ 2 trong tuần và cần tồn tại trong S ngày tới. Hãy cho biết số lượng ngày ít nhất bạn cần phải mua lương thực từ của hàng để tồn tại hoặc bạn sẽ bị chết đói trong S ngày tới.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ 3 số N, S, M được viết trên một dòng.
T, N, S, M thỏa mãn ràng buộc: 1≤T≤100;  1≤N, S, M ≤30.
Output:

Đưa ra số ngày ít nhất bạn có thể mua lương thực để tồn tại hoặc đưa ra -1 nếu bạn bị chết đói.
Ví dụ:


Input

Output

2
16 10 2
20 10 30

2
-1
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

void solution() {
    int n, s, m;
    cin >> n >> s >> m;
    if (s * m > (s - s / 7) * n) cout << -1;
    else {
        for (int i = 1; i <= s - s / 7; i++) {
            if (n * i >= s * m) return cout << i, void();
        }
    }
}

int main() {
    faster();
    int T;
    cin >> T;
    while (T--) {
        solution();
        cout << endl;
    }
    return 0;
}