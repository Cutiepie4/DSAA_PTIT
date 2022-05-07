/*
Một máy ATM hiện có n (n ≤ 30) tờ tiền có giá trị t[1], t[2], …, t[n]. Hãy tìm cách trả ít tờ nhất với số tiền đúng bằng S (các tờ tiền có giá trị bất kỳ và có thể bằng nhau, mỗi tờ tiền chỉ được dùng một lần).

Input: Dòng đầu tiên ghi số bộ test T (T<10). Mỗi bộ test gồm 2 số nguyên n và S (S ≤ 109). Dòng thứ hai chứa n số nguyên t[1], t[2], …, t[n] (t[i] ≤ 109)

Output: Với mỗi bộ test ghi ra số tờ tiền ít nhất phải trả.

Nếu không thể tìm được kết quả, in ra -1.

Ví dụ

Input
1
3 5
1 4 5

Output
1
*/
#include <bits/stdc++.h>
using namespace std;

vector <int> v;
int ans, sum, n, cnt;

void process(int index, int cnt, int sumtmp) {
    for (int i = index; i < n; i++) {
        int tmp = v[i] + sumtmp;
        if (tmp <= sum) {
            if (tmp == sum) {
                ans = min(ans, cnt + 1);
                return;
            }
            else process(i + 1, cnt + 1, tmp);
        }
        else return;
    }
}

void solution() {
    cin >> n >> sum;
    ans = INT32_MAX, cnt = 0;
    v = vector <int>(n);
    for (auto& i : v) cin >> i;
    process(0, 0, 0);
    if (ans != INT32_MAX) cout << ans;
    else cout << "-1";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}