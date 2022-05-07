/*
Cho ma trận vuông Ci,j cấp N (1<= i, j <= N<10) gồm N2 số tự nhiên và số tự nhiên K (các số trong ma trận không nhất thiết phải khác nhau và đều không quá 100, K không quá 104). Hãy viết chương trình lấy mỗi hàng, mỗi cột duy nhất một phần tử sao cho tổng các phần tử này đúng bằng K.

Dữ liệu vào: Dòng 1 ghi hai số N và K. N dòng tiếp theo ghi ma trận C. 

Kết quả: dòng đầu ghi số cách tìm được. Mỗi dòng tiếp theo ghi một cách theo vị trí của số đó trong lần lượt từng hàng của ma trận. Xem ví dụ để hiểu rõ hơn. 

Ví dụ:
INPUT
3 10
2 4 3
1 3 6
4 2 4
    
OUTPUT
2
1 3 2
3 2 1
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

int n, k;
matrix M, V;

void back(int r, int sum, vt v, vt mark) {
    if (sum == k && r == n) {
        V.push_back(v);
        return;
    }
    if(r >= n) return;
    for (int i = 0; i < n; i++) {
        int sumtmp = sum + M[r][i];
        if (sumtmp <= k && mark[i]) {
            vt tmp = v, tmp1 = mark;
            tmp.push_back(i + 1);
            mark[i] = 0;
            back(r + 1, sumtmp, tmp, mark);
            mark[i] = 1;
        }
    }
}

void solution() {
    cin >> n >> k;
    M = matrix(n, vt(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> M[i][j];
    }
    vt v, mark(n, 1);
    back(0, 0, v, mark);
    cout << V.size() << endl;
    for (auto i : V) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    faster();
    solution();
    return 0;
}