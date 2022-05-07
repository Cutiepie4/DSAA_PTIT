/*
Cho cặp số S và T là các số nguyên tố có 4 chữ số (Ví dụ S = 1033, T = 8197 là các số nguyên tố có 4 chữ số). Hãy viết chương trình tìm cách dịch chuyển S thành T thỏa mãn đồng thời những điều kiện dưới đây:

Mỗi phép dịch chuyển chỉ được phép thay đổi một chữ số của số ở bước trước đó (ví dụ nếu S=1033 thì phép dịch chuyển S thành 1733 là hợp lệ);
Số nhận được cũng là một số nguyên tố có 4 chữ số (ví dụ nếu S=1033 thì phép dịch chuyển S thành 1833 là không hợp lệ, và S dịch chuyển thành 1733 là hợp lệ);
Số các bước dịch chuyển là ít nhất.
Ví dụ số các phép dịch chuyển ít nhất để S = 1033 thành  T = 8179 là 6 bao gồm các phéch chuyển như sau:       

8179 ß 8779ß 3779ß 3739ß 3733ß 1733ß 1033.

Input:

Dòng đầu tiên đưa vào số lượng test T (T≤100)
Những dòng kế tiếp mỗi dòng đưa vào một test. Mỗi test là một bộ đôi S, T.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
1033 8179
1033 8779

Output
6
5
*/
#include <bits/stdc++.h>
using namespace std;

int n;
string s, d;
vector <int> p;
vector <int> Data[10000][4];

void init() {
    vector <int> check(10000, 1);
    check[0] = check[1] = 0;
    for (int i = 2; i < sqrt(10000); i++) {
        if (check[i]) {
            for (int j = i * i; j < 10000; j += i) {
                check[j] = 0;
            }
        }
    }
    for (int i = 1000; i < 10000; i++)
        if (check[i]) p.push_back(i);

    for (int i = 0; i < p.size(); i++) {
        string ss = to_string(p[i]);
        for (int j = 0; j < ss.size(); j++) {
            string tmp = ss.substr(0, j) + ss.substr(j + 1);
            Data[stoi(tmp)][j].push_back(p[i]);
        }
    }
}

int bfs() {
    vector <int> mark(10000, 1);
    queue <pair <string, int>> Q;
    Q.push({ s, 0 });
    while (!Q.empty()) {
        string x = Q.front().first;
        int cnt = Q.front().second;
        Q.pop();
        if (x == d) return cnt;

        for (int i = 0; i < x.size(); i++) {
            vector <int> tmp = Data[stoi(x.substr(0, i) + x.substr(i + 1))][i];
            for (auto j : tmp) {
                if (mark[j]) {
                    mark[j] = 0;
                    Q.push({ to_string(j), cnt + 1 });
                }
            }
        }
    }
    return -1;
}

void solution() {
    cin >> s >> d;
    cout << bfs();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    init();
    int T;
    cin >> T;
    while (T--) {
        solution();
        cout << endl;
    }
    return 0;
}