/*
Cho ma trận vuông A kích thước N x N. Nhiệm vụ của bạn là hãy tính ma trận X = AK với K là số nguyên cho trước. Đáp số có thể rất lớn, hãy in ra kết quả theo modulo 109+7.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 100).

Mỗi test bắt gồm một số nguyên N và K (1 ≤ N ≤ 10, 1 ≤ K ≤ 109) là kích thước của ma trận và số mũ.

Output: 

Với mỗi test, in ra kết quả của ma trận X.

Ví dụ:

Input:
2
2 5
1 1
1 0
3 1000000000
1 2 3
4 5 6
7 8 9
8 5
5 3

OUTPUT:
597240088 35500972 473761863
781257150 154135232 527013321
965274212 272769492 580264779
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <ll>> 
const ll MOD = 1e9 + 7;

ll n, k;

matrix multi(matrix a, matrix b) {
    matrix res(n, vector <ll>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] = (res[i][j] % MOD + (a[i][k] % MOD * b[k][j]) % MOD) % MOD;
            }
        }
    }
    return res;
}

matrix sqr(matrix a) {
    return multi(a, a);
}

matrix power(matrix a, ll k) {
    if (k == 1) return a;
    else {
        if (k % 2 == 0) {
            return sqr(power(a, k / 2));
        }
        else return multi(a, sqr(power(a, k / 2)));
    }
}


void output(matrix a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void input(matrix& a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

void solution() {
    cin >> n >> k;
    matrix mt(n + 1, vector <ll>(n + 1, 0));
    input(mt);
    output(power(mt, k));
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}