/*
Cho tập các số A[] = (a1, a2, ..,an). 
Hãy kiểm tra xem ta có thể chia tập A[] tành hai 
tập con sao cho tổng các phần tử của ai tập con 
bằng nhau hay không. Đưa ra YES nếu có hể thực 
hiện được, ngược lại đưa ra NO.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <int>>
#define vt vector <int>
#define matrixl vector <vector <ll>>
#define vtl vector <ll>
const ll MOD = 1e9 + 7;

int sum;

int process(vt v, int index, int sumtmp) {
    for (int i = index + 1; i < v.size(); i++) {
        int tmp = v[i] + sumtmp;
        if (tmp <= sum) {
            if (tmp == sum) {
                return 1;
            }
            else if (process(v, i, tmp)) return 1;
        }
    }
    return 0;
}

void solution() {
    int n, kt = 1;
    sum = 0;
    cin >> n;
    vt v(n);
    for (auto& i : v) {
        cin >> i;
        sum += i;
    }
    if (sum % 2 == 1) {
        cout << "NO" << endl;
        return;
    }
    sum /= 2;
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        if (v[i] <= sum) {
            if (v[i] == sum) {
                cout << "YES" << endl;
                return;
            }
            else if (process(v, i, v[i])) {
                cout << "YES" << endl;
                return;
            }
        }
        else {
            cout << "NO" << endl;
            return;
        }
    }
    if (kt) cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}