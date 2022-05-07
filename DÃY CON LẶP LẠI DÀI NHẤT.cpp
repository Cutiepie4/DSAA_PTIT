/*
Cho xâu ký tự S. Nhiệm vụ của bạn là tìm độ dài dãy con lặp lại dài nhất trong S. Dãy con có thể chứa các phần tử không liên tiếp nhau.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào độ dài xâu str; dòng tiếp theo đưa vào xâu S.
T, str thỏa mãn ràng buộc: 1 ≤ T ≤ 100;  1 ≤ size(S) ≤ 100.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
3
abc
5
axxxy

Output
0
2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <int>>
#define vt vector <int>

void solution() {
    string a, b;
    int ans = 0, tmp;
    cin >> tmp >> a;
    b = a;
    matrix mt(a.size() + 1, vector <int>(b.size() + 1, 0));
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1] && i != j) mt[i][j] = mt[i - 1][j - 1] + 1;
            else mt[i][j] = max(mt[i][j - 1], mt[i - 1][j]);
            ans = max(ans, mt[i][j]);
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}