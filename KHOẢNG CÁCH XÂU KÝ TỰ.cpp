/*
Cho tập n xâu ký tự S và hai xâu s, t Î S. Ta giả thiết các xâu ký tự S[i] Î S có độ dài bằng nhau.  Hãy tìm khoảng cách đường đi ngắn nhất từ s đến t. Biết từ một xâu ký tự bất kỳ ta chỉ được phép dịch chuyển đến xâu khác với nó duy nhất 1 ký tự. Ví dụ ta có tập các từ S = { POON, TOON, PLEE, SAME, POIE, PLEA, PLIE, POIN }, s = TOON, t = PLEA ta có độ dài đường đi ngắn nhất là 7 tương ứng với các phép dịch chuyển : TOON -> POON –> POIN –> POIE –> PLIE –> PLEE –> PLEA.

Input:

Dòng đầu tiên đưa vào số lượng test T (T≤100).
Mỗi test được tổ chức thành 2 dòng. Dòng thứ nhất ghi lại n là số từ trong S và hai từ s, t.  Dòng thứ 2 đưa vào n xâu xâu ký tự của S; các xâu ký tự được viết cách nhau một vài khoảng trống, có độ dài không vượt quá 10 kí tự.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:



Input

Output

1

8 TOON  PLEA

POON TOON PLEE SAME  POIE  PLEA  PLIE  POIN

7
*/
#include <bits/stdc++.h>
using namespace std;

int n;
string s, d;
vector <string> S;
map <string, vector <string>> Data;

void Load() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < S[i].size(); j++) {
            string tmp = S[i].substr(0, j) + "*" + S[i].substr(j + 1);
            Data[tmp].push_back(S[i]);
        }
    }
}

int bfs() {
    map <string, int> mark;
    mark[s] = 0;
    queue <pair <string, int>> Q;
    Q.push({ s, 1 });
    while (!Q.empty()) {
        string x = Q.front().first;
        int cnt = Q.front().second;
        Q.pop();
        if (x == d) return cnt;

        for (int i = 0; i < x.size(); i++) {
            vector <string> tmp = Data[x.substr(0, i) + "*" + x.substr(i + 1)];
            for (auto j : tmp) {
                if (mark[j] == 0) {
                    mark[j] = 1;
                    Q.push({ j, cnt + 1 });
                }
            }
        }
    }
    return -1;
}

void solution() {
    cin >> n >> s >> d;
    Data.clear();
    S = vector <string>(n);
    for (auto& i : S) cin >> i;
    if (s == d) return cout << 1, void();
    Load();
    cout << bfs();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solution();
        cout << endl;
    }
    return 0;
}