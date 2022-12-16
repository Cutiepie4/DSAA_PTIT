/*
Ví dụ: có các mẩu cáp với chất lượng lần lượt là 1, 7, 0, 5, 3, 81,7,0,5,3,8.
Nối vào ta được đoạn cáp 170538170538. Đoạn cáp này có thể chia làm 3 phần
có tổng chất lượng bằng nhau lần lượt là 17, 053 và 8:
    1 + 7 = 0 + 5 + 3 = 81+7=0+5+3=8.
Input
Dòng đầu tiên nhập vào T là số đoạn cáp đã nối sẵn.(1≤T≤100)
Với mỗi đoạn cáp nối sẵn, nhập vào:
Dòng thứ nhất nhập vào số nguyên N là số lượng mẩu cáp. (2≤n≤1000).
Dòng thứ hai nhập vào dãy số gồm N chữ số là đoạn cáp đã được nối.
Output
Nếu dãy số chính xác thì in YES, ngược lại thì in NO.
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k; cin >> k;
        string n;
        cin >> n;
        int tmp = 0;
        for (int i = 0; i < n.size(); i++) tmp += n[i] - '0';
        vector<int>a;
        for (int i = 2; i * i <= tmp; i++) {
            if (tmp % i == 0) {
                a.push_back(i);
                if (i * i != tmp) a.push_back(tmp / i);
            }
        }
        a.push_back(1);
        int ck = 1;
        for (int i = 0; i < a.size(); i++) {
            int x = 0;
            for (int j = 0; j < n.size(); j++) {
                x += n[j] - '0';
                if (x > a[i]) break;
                if (x == a[i]) x = 0;
            }
            if (x == 0) {
                cout << "YES" << endl;
                ck = 0; break;
            }
        }
        if (ck) cout << "NO" << endl;
    }
}