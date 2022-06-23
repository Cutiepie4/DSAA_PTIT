/*
Hãy in ra tất cả các xâu nhị phân độ dài N, có K bit 1 theo thứ tự từ điển tăng dần.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test gồm 2 số nguyên N, K (1 ≤ K ≤ N ≤ 16).

Output:  Với mỗi test, in ra đáp án tìm được, mỗi xâu in ra trên một dòng.
Ví dụ:
Input
2
4 2
3 2
Output
0011
0101
0110
1001
1010
1100
011
101
110
*/
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector <string> Data[17][17];

void back(int cnt, string s) {
    if (s.size() < 17) Data[s.size()][cnt].push_back(s);
    if (s.size() + 1 < 17) {
        back(cnt, s + '0');
        back(cnt + 1, s + '1');
    }
}

void solution() {
    cin >> n >> k;
    for (auto i : Data[n][k]) cout << i << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    back(0, "");
    int t;
    cin >> t;
    while (t--) {
        solution();
        // cout << endl;
    }
}