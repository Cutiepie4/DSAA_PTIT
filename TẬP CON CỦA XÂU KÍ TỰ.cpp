/*
Cho một xâu ký tự S không có ký tự lặp lại. Hãy đưa ra tất cả các tập con của xâu ký tự S theo thứ tự từ điển.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự.
T, S thỏa mãn ràng buộc: 1≤T≤100; 1≤length(S)≤16.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
1
3
abc

Output
a ab abc ac b bc c
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

int n;
string s;
vts V;

void back(int index, string tmp) {
    if(!tmp.empty()) cout << tmp << " ";
    for (int i = index; i < n; i++) {
        back(i + 1, tmp + s[i]);
    }
}

void solution() {
    cin >> n >> s;
    back(0, "");
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