#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <int>>
#define vt vector <int>
#define matrixl vector <vector <ll>>
#define vtl vector <ll>
int kt = 1;

void merge(vt data) {
    sort(data.begin(), data.end());
    int tmp = 0;
    for (auto i : data) tmp = tmp * 10 + i;
    kt = 0;
    cout << tmp << endl;
}

int check(vt data, int xx) {
    int tmp = 0;
    for (auto i : data) tmp += i * i;
    return tmp == xx ? 1 : 0;
}

void solution() {
    kt = 1;
    int x, xx;
    cin >> x >> xx;
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}