/*
Mỗi ng có 1 trong 3 tờ: 25k, 50k, 100k đến mua vé giá 25k.
Xem có thể bán vé theo đúng thứ tự được ko
*/

#include <bits/stdc++.h>
using namespace std;

int x25 = 0, x50 = 0, x100 = 0, a[1000000];

void pay(int x) {
    if (x == 25) x25++;
    if (x == 50) x50++;
    if (x == 100) x100++;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        pay(a[i]);
        if (a[i] > 25) {
            a[i] -= 25;
            while (a[i] >= 100 && x100 > 0) {
                x100--; a[i] -= 100;
            }
            while (a[i] >= 50 && x50 > 0) {
                x50--; a[i] -= 50;
            }
            while (a[i] >= 25 && x25 > 0) {
                x25--; a[i] -= 25;
            }
            if (a[i] != 0) {
                cout << "NO"; return 0;;
            }
        }
    }
    cout << "YES";
}