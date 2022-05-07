/*
Cho hai số nguyên dương L, R. Hãy đưa ra số các số K trong khoảng [L, R] thỏa mãn điều kiện:

Tất cả các chữ số của K đều khác nhau.
Tất cả các chữ số của K đều nhỏ hơn hoặc bằng 5.
Ví dụ với L = 4, R = 13 ta có 5 số thỏa mãn yêu cầu là 4, 5, 10, 12, 13,

Input:

Dòng đầu tiên đưa vào số lượng test T.
Dòng tiếp theo đưa vào các bộ test. Mỗi bộ test được là một cặp L, R được viết trên một dòng.
T, L, R thỏa mãn ràng buộc: 1≤T≤100; 0≤L≤R≤105.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:
Input
2
4  13
100  1000

Output
5
100
*/

#include <bits/stdc++.h>
using namespace std;

set <int> ss;

int gt(int x) {
    if (x == 1) return 1;
    return gt(x - 1) * x;
}

int convert(vector <int> v) {
    int x = 0;
    for (auto i : v) x = x * 10 + i;
    return x;
}

void next_com(vector <int>& v, int k, int n) {
    int x = gt(k);
    vector <int> tmp = v;
    while (x--) {
        ss.insert(convert(tmp));
        next_permutation(tmp.begin(), tmp.end());
    }
    int i;
    for (i = k; i > 0; i--) {
        if (v[i] < n - k + i) {
            v[i]++;
            for (int j = i + 1; j <= k; j++) {
                v[j] = v[i] + j - i;
            }
            next_com(v, k, n);
        }
    }
    return;
}


void init() {
    for (int i = 1; i < 6; i++) {
        vector <int> tmp;
        tmp.push_back(0);
        for (int j = 0; j < i; j++) tmp.push_back(j);
        next_com(tmp, i, 5);
    }
}

int main() {
    int t;
    cin >> t;
    init();
    set <int> ::iterator it;
    vector <int> data(100000, 0);
    for (it = ss.begin(); it != ss.end(); it++) data[*it]++;
    for (int i = 1; i < data.size(); i++) data[i] += data[i - 1];
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << data[r] - data[l - 1] << endl;
    }
}