/*
Cho số nguyên dương N. Nhiệm vụ của bạn là tìm số K nhỏ nhất, sao cho K có đúng N ước. Input đảm bảo rằng đáp án không vượt quá 1018.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤  20).

Mỗi test gồm 1 số nguyên N ( 1 ≤  N ≤  1000).

Output:  Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:

Input

Output

2

4

6



6

12
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll res;
int p[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
void Try(int i, ll tmp, ll uoc) {
    if (uoc > n) return;
    if (uoc == n) res = min(res, tmp);
    for (int j = 1; ; j++) {
        if (tmp * p[i] > res) break;
        tmp *= p[i];
        Try(i + 1, tmp, uoc * (j + 1));
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        res = 1e18;
        cin >> n;
        Try(0, 1, 1);
        cout << res << endl;
    }
}