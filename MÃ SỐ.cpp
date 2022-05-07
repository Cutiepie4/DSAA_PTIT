/*
Số lượng máy tính ở các phòng thực hành nhà A3 tăng lên nhanh chóng. Để gán mã cho các máy tính của PTIT người ta sử dụng mã gồm 2*N ký tự, trong đó:

N ký tự đầu tiên là hoán vị của N chữ cái in hoa đầu tiên, tính từ A.
N ký tự tiếp theo là các ký tự số bất kỳ từ 1 đến N (có thể trùng nhau).
Người ta ước tính chỉ cần N = 5 là đủ để gán mã cho toàn bộ máy tính kể cả khi mở rộng quy mô các phòng thực hành. Hãy viết chương trình liệt kê các mã tạo được với giá trị N cho trước.

Input

Chỉ có duy nhất số N (1 < N < 6)

Output

Ghi ra lần lượt các mã khác nhau tạo được theo thứ tự từ điển, mỗi mã ghi trên một dòng
Ví dụ

Input
2

OUTPUT:
AB11
AB12
AB21
AB22
BA11
BA12
BA21
BA22
*/
#include <bits/stdc++.h>
using namespace std;

int n;
vector <string> Data_f, Data_s;
vector <string> Data;
vector <int> x(10);

void init_f() {
    x[0] = 1;
    for (int i = 1; i < 10; i++) x[i] = x[i - 1] * i;
    string tmp;
    for (char i = 'A'; i < n + 'A'; i++) {
        tmp.push_back(i);
    }
    while (x[n]--) {
        Data_f.push_back(tmp);
        next_permutation(tmp.begin(), tmp.end());
    }
}

void process(char a, char n, int k, string tmp1) {
    if (k == 0) {
        Data_s.push_back(tmp1);
        return;
    }
    for (char i = a; i <= n; i++) {
        string tmp = tmp1;
        tmp.push_back(i);
        process('1', n, k - 1, tmp);
    }
}

void init_s() {
    for (char i = '1'; i <= (char)(n + '0'); i++) {
        string tmp;
        tmp.push_back(i);
        int k = n;
        process('1', (char)(n + '0'), k - 1, tmp);
    }
}

void merge() {
    for (int i = 0; i < Data_f.size(); i++) {
        for (int j = 0; j < Data_s.size(); j++) {
            Data.push_back(Data_f[i] + Data_s[j]);
        }
    }
    sort(Data.begin(), Data.end());
}

void output() {
    for (auto i : Data) cout << i << endl;
}

int main() {
    cin >> n;
    init_f();
    init_s();
    merge();
    output();
}