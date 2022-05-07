#include <bits/stdc++.h>
using namespace std;
#define vts vector <string>

int n;
vts S(10001);

string cvt(int n) {
    string res;
    while (n > 0) {
        res += to_string(n % 2);
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

void init() {
    for (int i = 1; i <= 10000; i++) {
        S[i] = cvt(i);
    }
}

int main() {
    int t;
    cin >> t;
    init();
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cout << S[i] << " ";
        cout << endl;
    }
}