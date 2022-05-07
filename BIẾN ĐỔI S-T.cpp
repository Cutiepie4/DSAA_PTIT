#include <bits/stdc++.h>
using namespace std;
#define MAX 20005

int S, T;
vector <int> dt;

void solution() {
    cin >> S >> T;
    if (S >= T) {
        cout << S - T;
        return;
    }
    dt = vector <int>(MAX, -1);
    dt[S] = 0;

    queue <int> Q;
    Q.push(S);
    while (dt[T] == -1) {
        int x = Q.front();
        Q.pop();

        if (x - 1 >= -1 && dt[x - 1] == -1) {
            dt[x - 1] = dt[x] + 1;
            Q.push(x - 1);
        }
        if (x * 2 < MAX && dt[2 * x] == -1) {
            dt[2 * x] = dt[x] + 1;
            Q.push(2 * x);
        }
    }
    cout << dt[T];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}