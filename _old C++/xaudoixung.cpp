/*
Cho xâu ký tự S. Nhiệm vụ của bạn là tì số phép chèn 
tối thiểu các ký tự vào S để S trở thàn xâu đối xứng. 
Ví dụ: S = “ab” ta có số phép chèn tốithiểu là 1 để 
trở thành xâu đối xứng “aba” hoặc“bab”. Với xâu 
S = “aa” thì số phép chèn tối thiểu à 0. Với xâu 
S = “abcd” có 
số phép chèn tối thiểu là 3 để trở thành xâu “dcbabcd”
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <int>>
#define vt vector <int>
#define matrixl vector <vector <ll>>
#define vtl vector <ll>
// c b a d b c
void process(string a, string b) {
    matrix mt(a.size() + 1, vt(b.size() + 1, 0));
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1]) {
                mt[i][j] = mt[i - 1][j - 1] + 1;
            }
            else mt[i][j] = max(mt[i][j - 1], mt[i - 1][j]);
        }
    }
    cout << a.size() - mt[a.size()][b.size()] << endl;
}

void solution() {
    string s;
    cin >> s;
    string tmp = s;
    reverse(s.begin(), s.end());
    process(tmp, s);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}