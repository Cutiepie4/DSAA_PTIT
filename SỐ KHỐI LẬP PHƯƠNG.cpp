/*
Một số X được gọi là số khối lập phương nếu X là lũy thừa bậc 3 của số Y (X= Y3). Cho số nguyên dương N, nhiệm vụ của bạn là tìm số khối lập phương lớn nhất bằng cách loại bỏ đi các chữ số của N. Ví dụ số 4125 ta có kết quả là 125 = 53.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤1018.
Output:

Đưa ra kết quả mỗi test theo từng dòng. Nếu không tìm được đáp án in ra -1.
Input
2
4125
976

OUTPUT
125
-1
*/
#include <bits/stdc++.h>
using namespace std;

bool isOK(string s, string str) {
    int index = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (s[index] == str[i])
            index++;
    }
    return index == s.length();
}

void TestCase() {
    long long x;
    cin >> x;
    long long y = cbrt(x);
    string str = to_string(x);

    for (int i = y; i >= 1; --i) {
        long long z = pow(i, 3);
        string s = to_string(z);
        if (isOK(s, str)) {
            cout << s << endl;
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        TestCase();
    }
    return 0;
}