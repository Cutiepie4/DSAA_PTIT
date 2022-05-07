/*
Cho xâu ký tự S bao gồm các ký tự in hoa khác nhau. Hãy đưa ra tất cả các hoán vị của xâu ký tự S. Ví dụ S=”ABC” ta có kết quả {ABC ACB BAC BCA CAB CBA}. 

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test là một xâu ký tự S được viết trên 1 dòng.
T, S thỏa mãn ràng buộc: 1≤T≤10; 1≤length(S) ≤10;
Output:

Đưa ra kết quả mỗi test theo từng dòng.
 
Input
2
AB
ABC

Output
AB BA
ABC ACB BAC BCA CAB CBA 
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

vt fact(11, 1);

void init() {
    for (int i = 2; i < 11; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

void solution() {
    string s;
    cin >> s;
    vt v(s.size());
    iota(v.begin(), v.end(), 0);
    int x = fact[s.size()];
    while (x--) {
        for (int i = 0; i < s.size(); i++) {
            cout << s[v[i]];
        }
        cout << " ";
        next_permutation(v.begin(), v.end());
    }
}

int main() {
    faster();
    int T;
    cin >> T;
    init();
    while (T--) {
        solution();
        cout << endl;
    }
    return 0;
}