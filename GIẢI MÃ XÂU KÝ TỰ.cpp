#include <bits/stdc++.h>
using namespace std;

/*
Xâu đầu vào: “abbbababbbababbbab ”
Xâu mã hóa : "3[a3[b]1[ab]]"
*/

string repeat(int rp, string s) {
    string x = s;
    for (int i = 1; i < rp; i++) s += x;
    return s;
}

string decode(string s) {
    string a, alp, num;
    deque <char> dq;

    for (auto i : s) {
        if (i != ']') dq.push_back(i);
        else {
            while (!dq.empty() && dq.back() != '[') {
                alp.insert(alp.begin(), dq.back());
                dq.pop_back();
            }
            dq.pop_back();
            while (!dq.empty() && isdigit(dq.back())) {
                num.insert(num.begin(), dq.back());
                dq.pop_back();
            }
            if (num.empty()) num = "1";
            a = repeat(stoi(num), alp);
            num.clear(), alp.clear();
            for (auto j : a) dq.push_back(j);
        }
    }
    a.clear();
    for (auto i : dq) a.push_back(i);
    return a;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << decode(s) << endl;
    }
}