#include <bits/stdc++.h>
using namespace std;
const int oo = 1500000;

vector<int>check(oo, 1);
vector<int>prime;

int q = sqrt(oo);

void eratos() {
    check[0] = check[1] = 0;
    for (int i = 2; i <= q; i++) {
        if (check[i]) {
            for (int j = i * i; j <= oo; j += i) {
                check[j] = 0;
            }
        }
    }
    for (int i = 2; i < oo; i++) if (check[i]) prime.push_back(i);
}

int main() {
    eratos();
    int n;
    cin >> n;
    int a[n];
    long long res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < prime.size(); j++) {
            while (a[i] % prime[j] == 0) {
                res += prime[j];
                a[i] /= prime[j];
            }
            if (a[i] == 1) break;
        }
    }
    cout << res;
}