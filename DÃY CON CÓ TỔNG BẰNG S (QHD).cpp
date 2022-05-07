/*
Cho N  số nguyên dương tạo thành dãy A={A1, A2, ..., AN}. Tìm ra một dãy con của dãy A (không nhất thiết là các phần tử liên tiếp trong dãy) có tổng bằng S cho trước.

Input: Dòng đầu ghi số bộ test T (T<10).  Mỗi bộ test có hai dòng, dòng đầu tiên ghi hai số nguyên dương N và S (0 < N ≤ 200) và S (0 < S ≤ 40000). Dòng tiếp theo lần lượt ghi N số hạng của dãy A là các số A1, A2, ..., AN (0 < Ai ≤ 200).

Output:  Với mỗi bộ test, nếu bài toán vô nghiệm thì in ra “NO”, ngược lại in ra “YES”

Ví dụ:

Input
2
5 6
1 2 4 3 5
10 15
2 2 2 2 2 2 2 2 2 2

Output
YES
NO
*/
#include <bits/stdc++.h>
using namespace std;

void TestCase() {
    int n, S;
    cin >> n >> S;
    vector<int> a(n), f(S + 1);
    for (int &x : a) cin >> x;

    f[0] = 1; // QHD
    for (int i = 0; i < n; ++i) {
        for (int j = S; j >= a[i]; --j) {
            if (f[j] == 0 && f[j - a[i]] == 1) {
                f[j] = 1;
            }
        }
    }
    cout << (f[S] == 1 ? "YES" : "NO");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1; cin >> T;
    while (T--) {
        TestCase();
        cout << "\n";
    }
    return 0;
}