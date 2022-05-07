/*
Một xâu kí tự S = (s1, s2, .., sn) được gọi là xâu AB độ dài n nếu với mọi siÎS thì si hoặc là kí tự A hoặc si là kí tự B . Ví dụ xâu S = “ABABABAB” là một xâu AB độ dài 8. Cho số tự nhiên N và số tự nhiên K (1£K<N£15 được nhập từ bàn phím), hãy viết chương trình liệt kê tất cả các xâu AB có độ dài N chứa duy nhất một dãy K kí tự A liên tiếp.

Dữ liệu vào chỉ có một dòng ghi hai số N và K.

Kết quả ghi ra màn hình theo khuôn dạng:

Dòng đầu tiên ghi lại số các xâu AB thỏa mãn yêu cầu bài toán;
Những dòng kế tiếp, mỗi dòng ghi lại một xâu AB thỏa mãn. Các xâu được ghi ra theo thứ tự từ điển.
Ví dụ:

INPUT
5 3 

OUTPUT
5
AAABA
AAABB
ABAAA
BAAAB
BBAAA
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define pi pair <int,int>
#define matrix vector <vt>
#define matrixl vector <vtl>
const int MOD = 1e9 + 7;

int n, k;
vts S;
set <string> ss;

void back(string s, int cnt) {
    if (s.size() == n - k) {
        S.push_back(s);
        return;
    }
    string tmp = s;
    tmp.push_back('B');
    back(tmp, 0);
    if (cnt < k - 1) {
        tmp = s;
        tmp.push_back('A');
        back(tmp, cnt + 1);
    }
}

void solution() {
    cin >> n >> k;
    string s;
    back(s, 0);
    for (int i = 0; i < k; i++) s.push_back('A');
    for (auto i : S) {
        if (i.front() == 'B') {
            ss.insert(s + i);
        }
        if (i.back() == 'B') {
            ss.insert(i + s);
        }
        string head, tail = i;
        for (int j = 1; j < i.size(); j++) {
            head.push_back(i[j - 1]);
            tail.erase(tail.begin());
            if (i[j] == i[j - 1] && i[j] == 'B') {
                ss.insert(head + s + tail);
            }
        }
    }
    cout << ss.size() << endl;
    for (auto i : ss) cout << i << endl;
}

int main() {
    faster();
    solution();
    return 0;
}