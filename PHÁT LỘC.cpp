/*
Một xâu ký tự số chỉ bao gồm các chữ số 6 và 8 sẽ được gọi là “phát lộc” nếu thỏa mãn các điều kiện sau:

Độ dài xâu ít nhất là 6
Chữ số đầu tiên là chữ số 8, chữ số cuối cùng là chữ số 6
Không có 2 chữ số 8 nào ở cạnh nhau
Không có nhiều hơn 3 chữ số 6 ở cạnh nhau.
Viết chương trình liệt kê các xâu ký tự phát lộc độ dài N theo thứ tự tăng dần.

Input

Chỉ có 1 dòng ghi số N (5 < N < 16).

Output

Ghi ra các xâu ký tự phát lộc độ dài N, mỗi xâu trên một dòng.

Ví dụ

Input
6

Output
866686
866866
868666
868686
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
vts S;

void back(int cnt6, string s) {
    if (s.size() == n) {
        S.push_back(s);
        return;
    }
    if (s.back() != '8' && s.size() < n - 1) back(0, s + "8");
    if (cnt6 < 3) back(cnt6 + 1, s + "6");
}

void solution() {
    cin >> n;
    back(0, "8");
    sort(S.begin(), S.end());
    for (auto i : S) cout << i << endl;
}

int main() {
    faster();
    solution();
    return 0;
}