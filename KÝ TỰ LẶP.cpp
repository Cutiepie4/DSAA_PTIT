/*
Cho một dãy các xâu ký tự chỉ bao gồm các chữ cái in hoa từ A đến Z, trong đó các ký tự trong mỗi xâu đều đã được sắp xếp theo thứ tự từ điển và mỗi chữ cái chỉ xuất hiện nhiều nhất một lần (tức là độ dài xâu tối đa là 26). Nếu một ký tự xuất hiện trong hai xâu liên tiếp thì được coi là một lần lặp. Hãy tìm cách sắp xếp lại thứ tự các xâu sao cho số lần lặp là nhỏ nhất có thể. Ví dụ dưới đây là cùng một dãy xâu nhưng với cách sắp xếp lại thì số lần lặp chỉ còn 2.

ABC
ABEF
DEF
ABCDE
FGH

=> Số lần lặp là 6

ABEF
DEF
ABC
FGH
ABCDE

=> Số lần lặp là 2.

Input

Dòng đầu tiên ghi số N (2 ≤ N ≤ 10) là số xâu ký tự. N dòng tiếp theo, mỗi dòng ghi một xâu. 

Output

In ra trên một dòng số lần lặp nhỏ nhất có thể. 

Ví dụ:
Test 2:
5
ABC
ABEF
DEF
ABCDE
FGH

2

Test 3:
6
BDE
FGH
DEF
ABC
BDE
ABEF

3

Test 4:
4
XYZ
XYZ
ABYZ
Z

4
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

int n, ans = INT32_MAX;
vts S;
matrix M;
vt mark, prv;
// mark đánh dấu đã đi, prv là ghi nhớ đỉnh phía trước đỉnh hiện tại
// M lưu sự so sánh giữa 2 string
void back(int ith, int sum) {
    if (ith == n) {
        ans = min(ans, sum);
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (mark[j] && sum + M[prv[ith]][j] < ans) {
            mark[j] = 0;
            prv[ith + 1] = j;
            back(ith + 1, sum + M[prv[ith]][j]);
            mark[j] = 1;
        }
    }
}

int compare(string a, string b) {
    vt tmp(30, 0);
    for (auto i : a) tmp[i - 'A']++;
    int res = 0;
    for (auto i : b) res += tmp[i - 'A'];
    return res;
}

void solution() {
    cin >> n;
    S = vts(n + 1);
    mark = vt(n + 1, 1);
    prv = vt(n + 1, 0);
    M = matrix(n + 1, vt(n + 1, 0));
    for (int i = 1; i <= n; i++) cin >> S[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            M[i][j] = M[j][i] = compare(S[i], S[j]);
        }
    }
    back(0, 0);
    cout << ans;
}

int main() {
    faster();
    solution();
    return 0;
}