/*
Cho dãy A[] gồm N số tự nhiên khác nhau và số tự nhiên K. Hãy viết chương trình liệt kê tất cả các dãy con của dãy số A[] sao cho tổng các phần tử trong dãy con đó đúng bằng K. Dữ liệu vào trên bàn phím (n=5, K=50), 5 số dòng thứ 2 là các phần tử dãy A:

5  50       

5 10 15 20 25

Các dãy con thoả mãn điều kiện tìm được liệt kê trên màn hình:

Mỗi dòng ghi lại một dãy con. Hai phần tử khác nhau của dãy con được viết cách nhau bởi một  khoảng trống.
Dòng cuối cùng ghi lại số các dãy con có tổng các phần tử đúng bằng K tìm được.
10 15 25
5 20 25
5 10 15 20

3
*/
#include <bits/stdc++.h>
using namespace std;

vector <int> v;
int sum, n;
vector <string> D;

void process(int index, string s, int sumtmp) {
    for (int i = index + 1; i < n; i++) {
        int tmp = v[i] + sumtmp;
        if (tmp <= sum) {
            string stmp = s;
            stmp += " ";
            stmp += to_string(v[i]);
            if (tmp == sum) {
                D.push_back(stmp);
                return;
            }
            else process(i, stmp, tmp);
        }
    }
}

int main() {
    cin >> n >> sum;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        string s = to_string(v[i]);
        if (v[i] <= sum) {
            if (v[i] == sum) {
                D.push_back(s);
            }
            else process(i, s, v[i]);
        }
    }
    for (int i = D.size() - 1; i >= 0; i--) {
        cout << D[i] << endl;
    }
    cout << D.size();
}