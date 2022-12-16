/*
Cho mảng A[] gồm n phần tử gồm các số âm và dương.
Hãy tìm giá trị lớn nhất tích các phần tử của tất 
cả các dãy con liên tục trong mảng A[].
Ví dụ với mảng A[] = {6, -3, - 10, 0, 2 }
ta có kết quả là 180 tương ứng với tích các
phần tử của dài dãy con {6, -3, -10}.
1≤ T ≤100; 1≤ n ≤100; 1≤ A[i] ≤200
*/
// tính tích tất cả các dãy con rồi so sánh so số liệu nhỏ

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll maxproduct(vector <int> v, int n) {
    ll res = v[0];
    for (int i = 0; i < n; i++) {
        ll x = v[i];
        for (int j = i+1; j < n; j++) {
            res = max(res, x);
            x *= v[j];
        }
        res = max(res, x);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cout << maxproduct(v,n) << endl;
    }
}