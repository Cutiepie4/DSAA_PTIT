/*
Có N con kanguru trong vườn thú, con thứ i có chiều cao bằng A[i]. Con kanguru có chiều cao X có thể chứa được một con có chiều cao bằng Y trong túi của nó nếu như X >= 2*Y.

Một con đã chứa một con kanguru rồi, thì không thể nhảy vào túi một con kanguru khác.

Bầy Kanguru rất thích chơi trốn tìm, vì vậy chúng thường xuyên nhảy vào túi của nhau. Các bạn hãy tính toán xem trong trường hợp tối ưu, số con kanguru nhìn thấy trong vườn thú ít nhất bằng bao nhiêu?

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm số nguyên N (1 ≤ N ≤ 100 000).

Dòng tiếp theo gồm N số nguyên A[i] (1 ≤ A[i] ≤ 100 000).

Output:

Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:

Input

Output

2

8

2 5 7 6 9 8 4 2

8

9 1 6 2 6 5 8 3

5

5

Giải thích test 1: Nhóm 2 – 5, 2 – 6, 4 – 8, 7, 9.
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
    int n;
    cin >> n;
    vt v(n);
    for (auto& i : v) cin >> i;
    sort(v.begin(), v.end());
    int res = n, mid = n / 2;
    for (int i = 0; i < n / 2 && mid < n; i++) {
        while (mid < n) {
            if (v[i] * 2 <= v[mid]) {
                res--, mid++;
                break;
            }
            else mid++;
        }
    }
    cout << res;
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