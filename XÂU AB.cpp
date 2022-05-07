/*
Xâu ký tự được gọi là xâu AB nếu mỗi ký tự trong xâu hoặc là ký tự ‘A’ hoặc là ký tự ‘B’. Ví dụ xâu “ABBABB” là xâu AB độ dài 6. Bạn là hãy liệt kê tất cả các xâu AB có độ dài n.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên n.
T, n thỏa mãn ràng buộc: 1 ≤ T ≤ 10;  1 ≤ n ≤ 10.
Output:

Đưa ra kết quả mỗi test theo từng dòng. Mỗi xâu cách nhau 1 dấu phẩy.
Input

Output

2

2

3



AA,AB,BA,BB

AAA,AAB,ABA,ABB,BAA,BAB,BBA,BBB
*/
#include <bits/stdc++.h>
using namespace std;

vector <string> Data;

int next(string& s) {
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'A') {
            s[i] = 'B';
            for (int j = i + 1; j < s.size(); j++) {
                s[j] = 'A';
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
        Data.clear();
        int n;
        cin >> n;
        string s;
        for (int i = 0; i < n; i++) s += 'A';
        Data.push_back(s);
        while (next(s)) Data.push_back(s);
        for (int i = 0; i < Data.size() - 1; i++) cout << Data[i] << ",";
        cout << Data.back() << endl;
    }
}