/*
Cho mảng A[] gồm N phần. Ta gọi cặp nghịch thế của mảng A[] là số các cặp i, j sao cho i<j và A[i]>A[j]. Đối với mảng đã được sắp xếp thì số cặp nghịch thế bằng 0. Mảng đã sắp theo thứ tự giảm dần có số đảo ngược cực đại. Nhiệm vụ của bạn là hãy đưa ra số cặp nghịch thế của mảng A[] gồm N phần tử.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N tương ứng với số phần tử của mảng A[]; phần thứ 2 là N số của mảng A[]; các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤107; 1≤A[i]≤1018.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
5
2 4 1 3 5
5
5 4 3 2 1

Output
3
10
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vtl vector <ll>

ll Merge(vtl& v, int l, int m, int r) {
    int i, j, k, n1 = m - l + 1, n2 = r - m;
    vtl L(n1), R(n2);

    for (i = 0; i < n1; i++) L[i] = v[l + i];
    for (i = 0; i < n2; i++) R[i] = v[m + i + 1];

    i = 0, j = 0, k = l;
    ll ans = 0;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) v[k++] = L[i++];
        else {
            ans += n1 - i;
            v[k++] = R[j++];
        }
    }
    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];
    return ans;
}

ll prs(vtl& v, int l, int r) {
    ll ans = 0;
    if (l < r) {
        int m = (l + r) / 2;
        ans += prs(v, l, m);
        ans += prs(v, m + 1, r);
        ans += Merge(v, l, m, r);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vtl v(n);
        for (auto& i : v) cin >> i;
        cout << prs(v, 0, n - 1) << endl;
    }
}