/*
Cho tập các số A[] = (a1, a2, .., an). Hãy kiểm tra xem ta có thể chia tập A[] thành hai tập con sao cho tổng các phần tử của hai tập con bằng nhau hay không. Đưa ra YES nếu có thể thực hiện được, ngược lại đưa ra NO.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N là số lượng phần tử của dãy số A[]; dòng tiếp theo đưa vào N phần tử của dãy số A[].
T, N, A[i] thỏa mãn ràng buộc: 1≤T ≤100; 1≤N≤100; 1≤ A[i] ≤100.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input
2
4
1 5 11 5
3
1 3 5 

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
    int n, sum;
    sum = 0;
    cin >> n;
    vt v(n);
    for (auto& i : v) {
        cin >> i;
        sum += i;
    }
    if (sum % 2 == 1) {
        cout << "NO";
        return;
    }
    sum /= 2;
    vt dp(sum + 1);

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= 1; j--) {
            if (j >= v[i] && dp[j] == 0 && dp[j - v[i]] == 1) {
                dp[j] = 1;
            }
        }
    }
    cout << (dp[sum] == 1 ? "YES" : "NO");
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