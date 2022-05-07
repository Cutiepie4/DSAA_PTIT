/*
Cho dãy số A[] gồm có N phần tử.

Nhiệm vụ của bạn là hãy kiểm tra tồn tại bộ ba (i, j, k) mà A[i] + A[j] + A[k] = K cho trước hay không.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm số nguyên N và K (1≤ N ≤5000, 0 ≤ K ≤ 10^9).

Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^9).

Output: 

Với mỗi test, in ra trên một dòng là “YES” nếu tìm được bộ ba thỏa mãn, “NO” trong trường hợp ngược lại.

Ví dụ:
Input:
2
6 22
1 4 15 6 10 8
3 4
1 1 1

Output
YES
NO
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
    int n, k;
    cin >> n >> k;
    vt v(n);
    for (auto& i : v) cin >> i;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = v[i] + v[j];
            x = k - x;
            if (x <= v[i]) {
                if (binary_search(v.begin(), v.begin() + i, k - x)) {
                    cout << "YES";
                    return;
                }

            }
            else {
                if (x > v[i] && x <= v[j]) {
                    if (binary_search(v.begin() + i + 1, v.begin() + j, x)) {
                        cout << "YES";
                        return;
                    }
                }
                else if (binary_search(v.begin() + j + 1, v.end(), x)) {
                    cout << "YES";
                    return;
                }
            }
        }
    }
    cout << "NO";
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