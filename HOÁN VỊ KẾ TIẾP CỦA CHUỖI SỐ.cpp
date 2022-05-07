/*
Hãy viết chương trình nhận vào một chuỗi (có thể khá dài) các ký tự số và đưa ra màn hình hoán vị kế tiếp của các ký tự số đó (với ý nghĩa là hoán vị có giá trị lớn hơn tiếp theo nếu ta coi chuỗi đó là một giá trị số nguyên). Chú ý: Các ký tự số trong dãy có thể trùng nhau.

Ví dụ:               123 -> 132

279134399742 -> 279134423799  

Cũng có trường hợp sẽ không thể có hoán vị kế tiếp. Ví dụ như khi đầu vào là chuỗi 987.  

Dữ liệu vào: Dòng đầu tiên ghi số nguyên  t là số bộ test (1 ≤ t ≤ 1000).  Mỗi bộ test có một dòng, đầu tiên là số thứ tự bộ test, một dấu cách, sau đó là chuỗi các ký tự số, tối đa 80 phần tử.  

Kết quả: Với mỗi bộ test hãy đưa ra một dòng gồm thứ tự bộ test, một dấu cách, tiếp theo đó là hoán vị kế tiếp hoặc chuỗi “BIGGEST” nếu không có hoán vị kế tiếp. 

Ví dụ:

INPUT
3
1 123
2 279134399742
3 987

OUTPUT
1 132
2 279134423799
3 BIGGEST
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

int check(string s) {
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] < s[i + 1]) return 1;
    }
    return 0;
}

void solution() {
    int t;
    string s;
    cin >> t >> s;
    cout << t << " ";
    if (!check(s)) {
        cout << "BIGGEST";
    }
    else {
        next_permutation(s.begin(), s.end());
        cout << s;
    }
}

int main() {
    faster();
    int T;
    cin >> T;
    while (T--) {
        solution();
        cout << endl;
    }
    return 0;
}