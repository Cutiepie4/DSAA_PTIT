/*
Một bản tin M đã mã hóa bí mật thành cá con số theo 
ánh xạ như sau: ‘A’->1, ‘B’->2, ., ‘Z’->26. 
Hãy cho biết có bao nhiêu cách khác nhau ể giải 
mã bản tin M. Ví dụ với bản mã M=”13” nó có thể 
được giải mã thành ABC (1 2 3), LC (12 3), AW(1 23).
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <int>>
#define vt vector <int>
#define matrixl vector <vector <ll>>
#define vtl vector <ll>
const ll MOD = 1e9 + 7;

ll decode(string s) {
    s.insert(s.begin(), '@');
    vtl dp(s.size(), 0);
    dp[0] = 1, dp[1] = 1;
    if (s[1] == '0') return 0;
    for (int i = 2; i < s.size(); i++) {
        if (s[i - 1] == '0') {
            if (s[i] == '0') return 0;
            dp[i] += dp[i - 1];
        }
        else {
            if (s[i] == '0') {
                if (s[i - 1] < '3') dp[i] += dp[i - 2];
                else return 0;
            }
            else {
                dp[i] += dp[i - 1];
                string tmp = s.substr(i - 1, 2);
                if (stoi(tmp, 0, 10) < 27) dp[i] += dp[i - 2];
            }
        }
    }
    return dp[s.size() - 1];
}

void solution() {
    string s;
    cin >> s;
    cout << decode(s) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}