
/*
Cho số nguyên N. Nhiệm vụ của bạn hãy đưa ra N số nguyên thủy đầu tiên theo thứ tự từ nhỏ đến lớn.

Số K được gọi là số nguyên thủy nếu số đó thỏa mãn tất cả các điều kiện:

Số các chữ số của K là một số chẵn.
Tất cả các chữ số của K chỉ bao gồm số 4 hoặc 5.
K là một số đối xứng.
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

void out(int n) {
    for (int i = 0; i < n; i++) cout << Data[i] << " ";
    cout << endl;
}

void in(string s) {
    string res = s;
    reverse(s.begin(), s.end());
    Data.push_back(res + s);
}

void init() {
    queue <string> q;
    q.push("4");
    in("4");
    q.push("5");
    in("5");
    for (int i = 2; i < 14; i++) {
        queue <string> tmp;
        while (!q.empty()) {
            tmp.push(q.front() + "4");
            in(q.front() + "4");
            tmp.push(q.front() + "5");
            in(q.front() + "5");
            q.pop();
        }
        q = tmp;
    }
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