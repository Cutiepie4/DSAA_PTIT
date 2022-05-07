/*
Cho xâu ký tự S[] bao gồm các ký tự in hoa [A, B, …,Z]. Ta định nghĩa giá trị của xâu S[] là tổng bình phương số lần xuất hiện mỗi ký tự trong xâu. Ví dụ với xâu S[] = “AAABBCD” ta có F(S) = 32 + 22 + 12 + 12 = 15. Hãy tìm giá trị nhỏ nhất của xâu S[] sau khi loại bỏ K ký tự trong xâu.

Input:

Dòng đầu tiên đưa vào số lượng test T (T≤100).
Mỗi test được tổ chức thành 2 dòng. Dòng thứ nhất ghi lại số K. Dòng thứ 2 ghi lại xâu ký tự S[] có độ dài không vượt quá 10^6.
Output:

Đưa ra giá trị nhỏ nhất của mỗi test theo từng dòng.
Input
2
0
ABCC
1
ABCC

Output
6
3
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        string s;
        cin >> k >> s;
        vector <int> v(26, 0);
        for (auto i : s) v[i - 'A']++;
        multiset <int, greater<int>> ms;
        for (auto i : v) {
            if (i > 0) ms.insert(i);
        }
        while (k--) {
            int x = *ms.begin();
            ms.erase(ms.begin());
            ms.insert(x - 1);
        }
        long long ans = 0;
        for (auto i : ms) ans += (long long)i * i;
        cout << ans << endl;
    }
}