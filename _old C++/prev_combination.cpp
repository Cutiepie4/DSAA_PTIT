#include <bits/stdc++.h>
using namespace std;

void prev_com(vector <int>& v, int n, int k) {
    for (int i = k; i >= 1; i--) {
        if (i == 1) {
            int x = n;
            if (v[1] > 1) {
                v[1]--;
                for (int j = k; j > 1; j--) {
                    v[j] = x--;
                }
                return;
            }
            else {
                for (int j = k; j > 0; j--) {
                    v[j] = x--;
                }
                return;
            }
        }
        else {
            if (v[i] > i) {
                if (v[i] - 1 > v[i - 1]) {
                    v[i]--;
                    int x = n;
                    for (int j = k; j > i; j--) {
                        v[j] = x--;
                    }
                    return;
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <int> v(k + 1), mark(n + 1, 0);
        for (int i = 1; i <= k; i++) {
            cin >> v[i];
        }
        prev_com(v, n, k);
        v.erase(v.begin());
        for (auto i : v) cout << i << " ";
        cout << endl;
    }
}