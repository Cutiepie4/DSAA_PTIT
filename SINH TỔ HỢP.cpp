/*

Input

2
4  3
5  3

Output
123 124 134 234
123 124 125 134 135 145 234 235 245 345
*/
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector <int> v;

void next_combination(vector <int>& v) {
    for (int i = 1; i <= k; i++) cout << v[i];
    cout << " ";
    for (int i = k; i > 0; i--) {
        if (v[i] < n - k + i) {
            v[i]++;
            for (int j = i + 1; j <= k; j++) {
                v[j] = v[i] + j - i;
            }
            next_combination(v);
        }
    }
}

void solution() {
    cin >> n >> k;
    v = vector <int>(k + 1);
    for (int i = 1; i <= k; i++) v[i] = i;
    next_combination(v);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}