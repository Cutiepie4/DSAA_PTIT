/*
Cho mảng A[] gồm n phần tử và số k. Đếm tất cả các cặp phần tử của mảng có tổng bằng k. Ví dụ A[] = {1, 5, 3, 4, 2 }, k = 7 ta có kết quả là 2 cặp (3, 4), (5, 2).

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần tử của mảng A[] và k; dòng tiếp theo là n số A[i] của mảng A[]các số được viết cách nhau một vài khoảng trống.
T, n, k, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤100; 0≤ k ≤100, 0≤ A[i] ≤103.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input:
2
5 9 
1 5 4 1 2
3 2
1 1 1

Output:
1
3
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
    int n, k, cnt = 0;
    cin >> n >> k;
    vector <int> v(1001, 0);
    for (int i = 0, tmp; i < n; i++) {
        cin >> tmp;
        v[tmp]++;
    }
    if (k % 2 == 0) {
        int x = k / 2;
        for (int i = 0; i < x; i++) {
            cnt += v[i] * v[k - i];
        }
        cnt += v[x] * (v[x] - 1) / 2;
    }
    else {
        int x = k / 2;
        for (int i = 0; i <= x; i++) {
            cnt += v[i] * v[k - i];
        }
    }
    cout << cnt;
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