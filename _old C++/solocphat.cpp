/*
Một số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8. Cho số tự nhiên N. 
Hãy liệt kê các số lộc phát có không quá N chữ số.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <int>>
#define vt vector <int>
#define matrixl vector <vector <ll>>
#define vtl vector <ll>
const ll MOD = 1e9 + 7;

vector <string> Data;
vt cnt(15, 0);

void out(int n) {
    cout << cnt[n] << endl;
    for (int i = Data.size() - 1; i >= 0; i--) {
        if (Data[i].size() <= n) cout << Data[i] << " ";
    }
    cout << endl;
}

void init() {
    queue <string> q;
    cnt[1] = 2;
    q.push("6"), q.push("8");
    Data.push_back("6");
    Data.push_back("8");
    for (int i = 2; i < 15; i++) {
        queue <string> tmp;
        while (!q.empty()) {
            tmp.push(q.front() + "6");
            Data.push_back(q.front() + "6");
            tmp.push(q.front() + "8");
            Data.push_back(q.front() + "8");
            q.pop();
        }
        cnt[i] = tmp.size();
        q = tmp;
    }
    for (int i = 1; i < 15; i++) cnt[i] += cnt[i - 1];
}

void solution() {
    int n;
    cin >> n;
    out(n);
}

int main() {
    int t;
    cin >> t;
    init();
    while (t--) {
        solution();
    }
    return 0;
}