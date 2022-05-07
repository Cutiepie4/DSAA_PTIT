/*
Cho xâu nhị phân X[], nhiệm vụ của bạn là hãy đưa ra xâu nhị phân trước của X[]. Ví dụ X[] =”111111” thì xâu nhị phân trước của X[] là “111110”. Với xâu X[] =“000001” thì xâu nhị trước của X[] là “000000”. Chú ý: nếu xâu dữ liệu trong input là xâu đầu tiên thì trước nó sẽ là xâu cuối cùng.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu nhi phân X.
T, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤length(X)≤103.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

 Input
2
010101
111111

Output
010100
111110
*/
#include <bits/stdc++.h>
using namespace std;

int next_bin(string& s) {
    for (int i = s.size(); i >= 0; i--) {
        if (s[i] == '1') {
            s[i] = '0';
            for (int j = i + 1; j < s.size(); j++) {
                s[j] = '1';
            }
            return 1;
        }
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (next_bin(s)) cout << s << endl;
        else {
            for (int i = 0; i < s.size(); i++) cout << '1';
            cout << endl;
        }
    }
}