/*
Chúng ta đều biết chỉ có 4 chữ số nguyên tố là 2, 3, 5, 7. Hãy liệt kê tất cả các số có ít nhất 4 chữ số nhưng không quá N chữ số và thỏa mãn tất cả các điều kiện sau:

Chỉ có các chữ số 2, 3, 5, 7
Có đầy đủ 4 chữ số 2, 3, 5, 7
Không phải là số chẵn.
Input

Chỉ có 1 dòng ghi số N (3 < N < 10)

Output

Ghi ra lần lượt các số thỏa mãn theo thứ tự tăng dần, mỗi số trên một dòng

Ví dụ

Input
4
Output
2357
2375
2537
2573
2735
2753
3257
3275
3527
3725
5237
5273
5327
5723
7235
7253
7325
7523
*/
#include <bits/stdc++.h>
using namespace std;

vector <vector <string>> Data(10);

void back(string s, int cnt2, int cnt3, int cnt5, int cnt7, int odd) {
    if (s.size() == 10) return;
    if (cnt2 && cnt3 && cnt5 && cnt7 && odd) Data[s.size()].push_back(s);
    back(s + '2', cnt2 + 1, cnt3, cnt5, cnt7, 0);
    back(s + '3', cnt2, cnt3 + 1, cnt5, cnt7, 1);
    back(s + '5', cnt2, cnt3, cnt5 + 1, cnt7, 1);
    back(s + '7', cnt2, cnt3, cnt5, cnt7 + 1, 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    back("", 0, 0, 0, 0, 0);
    for (int i = 4; i <= n; i++) {
        sort(Data[i].begin(), Data[i].end());
        for (auto j : Data[i]) cout << j << endl;
    }
}