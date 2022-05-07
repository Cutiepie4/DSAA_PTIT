/*
nhìn từ trái qua, hạ bit đầu tiên xuống lấy bit đó so sánh với bit tiếp theo nếống bằng 0 khác bằng 1 
Vd: 100011
hạ bit đầu : 1 lấy 1 này so sánh bit tiếp theo là 0 thấy khác nhau =1 rồi so sánh 1 này với bit tiếp theo nữa ,,,, đến hết
ta  được 111101
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) s[i] = '0';
        else s[i] = '1';
    }
    cout << s;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}
