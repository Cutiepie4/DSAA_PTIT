#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define pi pair <int,int>
#define matrix vector <vt>
#define matrixl vector <vtl>
const int MOD = 1e9 + 7;

int n;

void back(int i, string a, string b, string c) {
    if (i == 1) {
        cout << a << " -> " << c << endl;
        return;
    }
    back(i - 1, a, c, b);
    back(1, a, b, c);
    back(i - 1, b, a, c);
}

void solution() {
    cin >> n;
    back(n, "A", "B", "C");
}

int main() {
    faster();
    solution();
    return 0;
}