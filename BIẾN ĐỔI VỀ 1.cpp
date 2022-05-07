/*
Cho số nguyên dương N. Hãy đếm số bước ít nhất để đưa N về 1 bằng cách thực hiện ba thao tác dưới đây:

Nếu N chia hết cho 2 bạn có thể giảm N = N/2.
Nếu N chia hết cho 3 bạn có thể giảm N = N/3.
Giảm N đi 1.
Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số N được viết trên một dòng.
T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤100000.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:
Input
2
10
6
Output
3
2
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

int ans;

void back(int n, int cnt) {
    if(cnt > ans) return;
    if (n == 1) {
        ans = min(ans, cnt);
        return;
    }
    if (n % 3 == 0) {
        back(n / 3, cnt + 1);
    }
    if (n % 2 == 0) {
        back(n / 2, cnt + 1);
    }
    back(n - 1, cnt + 1);
}

void solution() {
    int n;
    cin >> n;
    ans = n;
    back(n, 0);
    cout << ans;
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