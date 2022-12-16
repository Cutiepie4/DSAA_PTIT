/*
Cho dãy số A[] có n phần tử và số nguyn dương S. 
Hãy tìm dãy con có ít phần tử nhất của A[] có tổng các phần tử đúng bằng S.

Input

Dòng đầu ghi hai số n và S. (n ≤ 30; S  ≤  109).

Dòng thứ 2 ghi n số của dãy A[], các sốđều nguyên 
dương và không quá 9 chữ số.
*/
#include <bits/stdc++.h>
using namespace std;

vector <int> v;
int ans = INT32_MAX, sum, n, cnt = 1;

void process(int index, int cnt, int sumtmp) {
    for (int i = index + 1; i < n; i++) {
        int tmp = v[i] + sumtmp;
        if (tmp <= sum) {
            if (tmp == sum) {
                ans = min(ans, cnt + 1);
                return;
            }
            else process(i, cnt + 1, tmp);
        }
    }
}

int main() {
    cin >> n >> sum;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        if (v[i] <= sum) {
            if (v[i] == sum) {
                cout << "1";
                return 0;
            }
            else process(i, cnt, v[i]);
        }
        if (ans != INT32_MAX) {
            cout << ans;
            return 0;
        }
    }
    cout << "-1";
}