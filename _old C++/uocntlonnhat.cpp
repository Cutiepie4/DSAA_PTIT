#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long maxp;
        while (n % 2 == 0) {
            maxp = 2; n /= 2;
        }
        for (long long i = 3; i <= sqrt(n); i += 2) {
            while (n % i == 0) {
                n /= i; maxp = i;
            }
        }
        if (n > 1) maxp = n;
        cout << maxp << endl;
    }
}