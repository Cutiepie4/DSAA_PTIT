/*
Cho 2 xâu S1 và S2. Hãy tìm xâu con chung dài nhất của 2 xâu này (các phần tử không nhất thiết phải liên tiếp nhau).

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test gồm hai dòng, mô tả xâu S1 và S2, mỗi xâu có độ dài không quá 1000 và chỉ gồm các chữ cái in hoa.

Output:  Với mỗi test, in ra độ dài dãy con chung dài nhất trên một dòng.

Input
2
AGGTAB
GXTXAYB

Output
AA
BB
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <int>>
#define vt vector <int>

void solution() {
    string a, b, res;
    cin >> a >> b;
    matrix mt(a.size() + 1, vector <int>(b.size() + 1, 0));
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1]) mt[i][j] = mt[i - 1][j - 1] + 1;
            else mt[i][j] = max(mt[i][j - 1], mt[i - 1][j]);
        }
    }
    cout << mt[a.size()][b.size()] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}