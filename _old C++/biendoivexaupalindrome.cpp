/*
Cho 1 xâu kí tự s với độ dài n.
1 phép biến đổi trên xâu sẽ thay thế 1 kí tự của xâu thành 1 kí tự khác.
Với mỗi vị trí trên xâu s chỉ được thực hiện không quá 1 phép biến đổi.
Hãy xác định xem sau k phép biến đổi nào đó, sâu s có thể trở thành
1 xâu palindrome hay không. 1 xâu kí tự là xâu Palindrome nếu xâu đó
đọc từ phải sang trái cũng giống như đọc từ trái sang phải.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n;
    cin >> n >> k;
    string s;
    cin >> s;
    int ck = 0;
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            ck++;
        }
    }
    n -= 2 * ck;
    if (k >= ck && k <= ck * 2) cout << "Yes";
    else {
        if (k > ck * 2) {
            k -= ck * 2;
            if ((k % 2 == 0 && k / 2 <= n / 2) || (s.size() % 2 == 1 && k % 2 == 1 && k / 2 <= n / 2)) {
                cout << "Yes";
            }
            else cout << "No";
        }
        else cout << "No";
    }
}