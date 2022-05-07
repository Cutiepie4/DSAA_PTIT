/*
Cho xâu ký tự S bao gồm các ký tự in thường. Nhiệm vụ của bạn là kiểm tra xem ta có thể sắp đặt lại các ký tự trong S để hai ký tự giống nhau đều không kề nhau hay không? Đưa ra 1 nếu có thể sắp đặt lại các ký tự trong S thỏa mãn yêu cầu bài toán, ngược lại đưa ra -1.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự S được viết trên một dòng.
T, S thỏa mãn ràng buộc: 1≤T≤100;  1≤length(S)≤10000.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
3
geeksforgeeks
bbbabaaacd
bbbbb

Output
1
1
-1
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
    vt v(27, 0);
    int x;
    if (s.size() % 2 == 0) x = s.size() / 2;
    else x = s.size() / 2 + 1;
    for (auto i : s) v[i - 'a']++;
    for (int i = 0; i < 27; i++) {
        if (v[i] > x) return -1;
    }
    return 1;
}

void solution() {
    string s;
    cin >> s;
    cout << check(s);
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