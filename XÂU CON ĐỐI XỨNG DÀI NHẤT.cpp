/*
Cho xâu S chỉ bao gồm các ký tự viết thường và dài không quá 1000 ký tự.

Hãy tìm xâu con đối xứng dài nhất của S.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test gồm một xâu S có độ dài không vượt quá 1000, chỉ gồm các kí tự thường.
Output:  Với mỗi test, in ra đáp án tìm được.

Ví dụ:

Input
2
abcbadd
aaaaa

Output
5
5
*/
#include <bits/stdc++.h>
using namespace std;

int buildCheck(string S) {
    int ans = 0;
    int n = S.size();
    int CheckPalin[n][n];
    for (int i = n - 1; i >= 0; i--) {
        CheckPalin[i][i] = 1;
        for (int j = i + 1; j < n; j++) {
            CheckPalin[i][j] = (S[i] == S[j]) && (i + 1 == j || CheckPalin[i + 1][j - 1]);
            if (CheckPalin[i][j]) ans = max(ans, j - i);
        }
    }
    return ans + 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << buildCheck(s) << endl;
    }
}