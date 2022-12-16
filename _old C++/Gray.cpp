#include <bits/stdc++.h>
using namespace std;

int m;
int n;
int A[65538];

void output() {
    int b[20];
    for (int i = 0; i < n; i++) {
        int k = 0;
        int u = A[i];
        while (u > 0) {
            b[k++] = u % 2;
            u /= 2;
        }
        for (int j = k + 1; j <= m;j++) cout << "0";
        while (k >= 1) printf("%d", b[--k]);
        cout << " ";
    }
    cout << endl;
}

void input() {
    cin >> m;
    A[0] = 0;
    A[1] = 1;
    int p = 1;
    n = 2;
    for (int i = 2;i <= m;i++) {
        p = p * 2;
        int u = 2 * n - 1;
        for (int j = n; j <= u; j++) A[j] = A[u - j] + p;
        n = n * 2;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        input();
        output();
    }
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <vector <string>> Data(11);

void init() {
    Data[1] = { "0", "1" };
    for (int i = 2; i <= 10; i++) {
        for (int j = 0; j < Data[i - 1].size(); j++) {
            Data[i].push_back("0" + Data[i - 1][j]);
        }
        for (int j = Data[i - 1].size() - 1; j >= 0; j--) {
            Data[i].push_back("1" + Data[i - 1][j]);
        }
    }
}

void solution() {
    int n;
    cin >> n;
    for (auto i : Data[n]) cout << i << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    init();
    while (t--) {
        solution();
    }
}