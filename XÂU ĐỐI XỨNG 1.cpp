/*
Cho xâu ký tự str. Nhiệm vụ của bạn là tìm số phép chèn tối thiểu các ký tự vào str để str trở thành xâu đối xứng. Ví dụ: str =”ab” ta có số phép chèn tối thiểu là 1 để trở thành xâu đối xứng “aba” hoặc “bab”. Với xâu str=”aa” thì số phép chèn tối thiểu là 0. Với xâu str=”abcd” có số phép chèn tối thiểu là 3 để trở thành xâu “dcbabcd”
Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự được viết trên một dòng
T, str thỏa mãn ràng buộc: 1≤T≤100;  1≤length(str)≤40.
Output:

Đưa ra kết quả mỗi test theo từng dòng.

Input
3
abcd
aba
geeks

Output
3
0
3
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
            if (a[i - 1] == b[j - 1]) mt[i][j] = mt[i - 1][j - 1] + 1;
            else mt[i][j] = max(m[i-1][j], m[i][j-1]);
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