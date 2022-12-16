#include <bits/stdc++.h>
using namespace std;

vector<int>check(100000, 1);
vector<int>prime;

void eratos() {
    check[0] = check[1] = 0;
    for (int i = 2; i <= sqrt(100000); i++) {
        if (check[i]) {
            for (int j = i * i; j <= 100000; j += i) {
                check[j] = 0;
            }
        }
    }
    for (int i = 2; i <= 100000; i++) if (check[i]) prime.push_back(i);
}

int main() {
    eratos();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < prime.size(); i++) {
            if (prime[i] <= n) cout << prime[i] << " ";
            else {
                cout << endl; break;
            }
        }
    }
}