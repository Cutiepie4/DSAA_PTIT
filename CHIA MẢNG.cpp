/*
Cho mảng các số nguyên A[] gồm N phần tử. Hãy chia mảng số nguyên A[] thành K tập con khác rỗng sao cho tổng các phần tử của mỗi tập con đều bằng nhau. Mỗi phần tử thuộc tập con xuất hiện duy nhất một lần trong tất cả các tập con. Ví dụ với A[] = {2, 1, 4, 5, 6}, K =3 ta có kết quả {2, 4}, {1, 5}, {6}.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số N và K; dòng tiếp theo đưa vào N số của mmảng A[]; các số được viết cách nhau một vài khoảng trống.
T, N, K, A[i] thỏa mãn ràng buộc: 1≤T ≤100; 1≤N, K≤20, 0≤A[i]≤100.
Output:

Đưa ra 1 nếu có thể chia tập con thành K tập thỏa mãn yêu cầu bài toán, ngược lại đưa ra 0.
Input
2
5 3
2 1 4 5 6
5 3
2 1 5 5 6

Output
1
0
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>

int n, k, s;
vt v, mark;

int back(int index, int sum, int cnt) {
    if (cnt == k) return 1;
    if (index >= n) return 0;
    for (int i = index; i < n; i++) {
        int tmp = sum + v[i];
        if (mark[i]) {
            mark[i] = 0;
            if (tmp <= s) {
                if (tmp == s) {
                    if (back(0, 0, cnt + 1)) return 1;
                }
                else if (back(i + 1, tmp, cnt)) return 1;
            }
            mark[i] = 1;
        }
    }
    return 0;
}

void solution() {
    cin >> n >> k;
    v = vt(n);
    s = 0;
    mark = vt(n, 1);
    for (auto& i : v) {
        cin >> i;
        s += i;
    }
    if (s % k != 0) {
        cout << 0;
        return;
    }
    s /= k;
    cout << back(0, 0, 1);
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