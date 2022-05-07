/*
Cho mảng A[] gồm N số nguyên dương phân biệt và số X. Nhiệm vụ của bạn là tìm phép tổ hợp các số trong mảng A[] có tổng bằng X. Các số trong mảng A[] có thể được sử dụng nhiều lần. Mỗi tổ hợp các số của mảng A[] được in ra theo thứ tự không giảm các số. Ví dụ với A[] = {2, 4, 6, 8}, X = 8 ta có các tổ hợp các số như sau:

[2, 2, 2, 2], [2, 2, 4], [2, 6], [4, 4], [8].

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số N và X; dòng tiếp theo đưa vào N số của mmảng A[]; các số được viết cách nhau một vài khoảng trống.
T, N, X, A[i] thỏa mãn ràng buộc: 1≤T ≤10; 1≤X, A[i]≤100. N ≤ 20.
Output:

Đưa ra kết quả mỗi test theo từng dòng. Mỗi đường tổ hợp được bao bởi cặp ký tự [, ]. Đưa ra -1 nếu không có tổ hợp nào thỏa mãn yêu cầu bài toán.
Input
1
4  8
2  4  6  8

Output
[2 2 2 2] [2 2 4] [2 6] [4 4] [8]
*/
#include <bits/stdc++.h>
using namespace std;

int n, sum;
vector <string> Data;
vector <int> v;

void process(int index, string tmp1, int tmp2) {
    for (int i = index; i < v.size(); i++) {
        if (v[i] + tmp2 <= sum) {
            string tmp = tmp1;
            tmp += " ";
            tmp += to_string(v[i]);
            if (v[i] + tmp2 == sum) {
                tmp += "]";
                Data.push_back(tmp);
                return;
            }
            else process(i, tmp, v[i] + tmp2);
        }
        else return;
    }
    return;
}

void output() {
    for (auto i : Data) cout << i;
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        v.clear(), Data.clear();
        cin >> n >> sum;
        for (int i = 0, a; i < n; i++) {
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            string tmp = "[";
            tmp += to_string(v[i]);
            if (v[i] == sum) {
                tmp += "]";
                Data.push_back(tmp);
                continue;
            }
            process(i, tmp, v[i]);
        }
        if (Data.empty()) cout << "-1" << endl;
        else output();
    }
}