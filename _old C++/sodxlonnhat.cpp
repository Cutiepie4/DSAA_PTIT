/*
Cho số nguyên dương gồm N chữ số. Bạn chỉ được phép thực hiện hai thao tác:

Thao tác A: loại bỏ tất cả các chữ số giống nhau.

Thao tác B: sắp đặt lại vị trí các chữ số.

Hãy tìm số nguyên đối xứng lớn nhất có thể được tạo ra bằng cách thực hiện hai thao tác A hoặc B ở trên. Ví dụ với số N = 1122233300000998, ta có thể tạo ra số đối xứng lớn nhất là 910000019 bằng cách thực hiện các thao tác A, B như sau:

Thao tác A: loại bỏ các chữ số 2 ta nhận được số 1133300000998.

Thao tác A: loại bỏ các chữ số 3 ta nhận được số 1100000998.

Thao tác A: loại bỏ các chữ số 8 ta nhận được số 110000099.

Thao tác B: sắp đặt lại các số còn lại 110000099 để được số 910000019.

Input:


*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int maxx = 0;
        string s;
        cin >> s;
        vector <int> v(10, 0);
        for (int i = 0; i < s.size(); i++) v[s[i] - '0']++;
        int z = 0, kt = 0;
        for (int i = 0; i < 10; i++) {
            if (v[i] % 2 == 1) {
                if (v[i] >= maxx) {
                    z = i;
                    maxx = v[i];
                }
            }
            if (v[i] > 0 && v[i] % 2 == 0) kt = 1;
        }
        if (z == 0 && kt != 1) {
            maxx = 0;
            for (int i = 1; i < 10; i++) {
                if (v[i] % 2 == 1) {
                    if (v[i] >= maxx) {
                        z = i;
                        maxx = v[i];
                    }
                }
            }
        }
        for (int i = 9; i >= 0; i--) {
            if (v[i] % 2 == 1 && i != z) {
                v[i] = 0;
                int x = s.find(i + '0');
                while (x != -1) {
                    s.erase(x);
                    x = s.find(i + '0');
                }
            }
        }
        string res;
        for (int i = 9; i >= 0; i--) {
            if (v[i] > 0 && i != z) {
                for (int j = 0; j < v[i] / 2; j++) res.push_back(i + '0');
            }
        }
        string tmp = res;
        while (v[z]--) res.push_back(z + '0');
        reverse(tmp.begin(), tmp.end());
        res += tmp;
        while (res.front() == '0') res.erase(res.begin());
        while (res.back() == '0') res.pop_back();
        cout << res << endl;
    }
}