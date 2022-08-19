/*
Cho xâu ký tự s chỉ bao gồm hai chữ cái là ‘A’ và ‘B’.

Mỗi bước được phép biến đổi một vị trí bất kỳ trong xâu (A thành B, B thành A) hoặc cũng có thể biến đổi một dãy liên tiếp các ký tự nào đó tính từ đầu xâu.

Hãy tính xem cần ít nhất bao nhiêu bước để biến đổi xâu về dạng toàn chữ cái A.
Input

Chỉ có 1 dòng ghi xâu ký tự s, độ dài không quá 1 triệu ký tự.  

Output

Ghi ra kết quả bài toán

Ví dụ

Input
AAABBBAAABBB 

Output
4
*/

#include <bits/stdc++.h>
using namespace std;

int process(vector <pair <char, int>>& v) {
    int ans = 0, status = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        if (status % 2 == 0) {
            if (v[i].first == 'B') {
                if (v[i].second > 1) ans++, status++;
                else ans++;
            }
        }
        else {
            if(v[i].first == 'A') {
                if(v[i].second > 1) ans++, status++;
                else ans++;
            }
        }
    }
    return ans;
}

vector <pair <char, int>> init(string& s) {
    vector <pair <char, int>> res;
    int cnt = 1;
    while (s.back() == 'A') s.pop_back();
    res.push_back({ s.front(), 1 });
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != res.back().first) res.push_back({ s[i], 1 });
        else res.back().second++;
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    vector <pair <char,int>> v = init(s);
    cout << process(v);
}