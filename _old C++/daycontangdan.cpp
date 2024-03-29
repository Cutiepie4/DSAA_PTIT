/*
Cho dãy số a[] có n phần tử là các số nguyên dương khác nhu từng đôi một. 
Hãy liệt kê tất cả các dãy con có từ 2 phần tử trở lên của dãy a[] thỏa mãn tính chất tăng dần.

Dãy con tạo được bằng cách lấy ra các phần tử trong dãy a[] nhưng vẫn giữ nguyên thứ tự ban đầu.

Coi mỗi dãy con như một xâu ký tự với các phần tử cách nhau một khoảng trống, hãy liệt kê theo thứ tự từ điển.
*/
#include <bits/stdc++.h>
using namespace std;

vector <string> Data;
vector <int> v;

void process(int index, string tmp1) {
    for (int i = index + 1; i < v.size(); i++) {
        if (v[i] >= v[index]) {
            string tmp = tmp1;
            tmp += " ";
            tmp += to_string(v[i]);
            Data.push_back(tmp);
            process(i, tmp);
        }
    }
    return;
}

void output() {
    sort(Data.begin(), Data.end());
    vector <string> ::iterator it;
    for (auto i : Data) cout << i << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    for (int j = 0; j < v.size(); j++) {
        string tmp;
        tmp += to_string(v[j]);
        process(j, tmp);
    }
    output();
}