// Tìm số nghiệm của phương trình đồng dư
// x2 = 1(mod) p trong khoảng [1,b].
//  Ví dụ với b=5, p=7 ta tìm được x = 1 €[1,5] 
//  để x2 = 1 %7=1. Với b = 8, p=6 ta tìm được 
//  x = {1, 5, 7} để x2 = 1(mod 6).
// Nhận thấy quy luật sẽ lặp lại sau mỗi số nguyên lần số cần lấy dư


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long b, p, count = 0;
        cin >> b >> p;
        long long q;
        if (b < p) {
            q = b;
            for (long long i = 1; i <= q; i++) {
                if ((i * i) % p == 1) count++;
            }
        }
        else {
            q = p;
            for (long long i = 1; i <= q; i++) {
                if ((i * i) % p == 1) count++;
            }
        }
        if (q == b) cout << count << endl;
        else {
            count *= b / p;
            q = b % p;
            for (long long i = 1; i <= q; i++) {
                if ((i * i) % p == 1) count++;
            }
            cout << count << endl;
        }
    }
}