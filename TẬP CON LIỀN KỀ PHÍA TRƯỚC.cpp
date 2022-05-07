/*
Cho hai số N, K và một tập con K phần tử X[] =(X1, X2,.., XK) của 1, 2, .., N. Nhiệm vụ của bạn là hãy đưa ra tập con K phần tử trước đó của X[]. Ví dụ N=5, K=3, X[] ={2, 3, 5} thì tập con trước đó của X[] là {2, 3, 4}. Chú ý nếu tập con trong input là đầu tiên thì trước đó là tập con cuối cùng.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là hai số N và K; dòng tiếp theo đưa vào K phần tử của X[] là một tập con K phần tử của 1, 2, .., N.
T, K, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤K≤N≤103.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
5  3
2  3  5
5  3
1  2  3

Output
2 3 4
3 4 5
*/
#include <bits/stdc++.h>
using namespace std;

void prev_com(vector <int>& v, int n, int k) {
    for (int i = k; i >= 1; i--) {
        if (i == 1) {
            int x = n;
            if (v[1] > 1) {
                v[1]--;
                for (int j = k; j > 1; j--) {
                    v[j] = x--;
                }
                return;
            }
            else {
                for (int j = k; j > 0; j--) {
                    v[j] = x--;
                }
                return;
            }
        }
        else {
            if (v[i] > i) {
                if (v[i] - 1 > v[i - 1]) {
                    v[i]--;
                    int x = n;
                    for (int j = k; j > i; j--) {
                        v[j] = x--;
                    }
                    return;
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <int> v(k + 1);
        for (int i = 1; i <= k; i++) {
            cin >> v[i];
        }
        prev_com(v, n, k);
        v.erase(v.begin());
        for (auto i : v) cout << i << " ";
        cout << endl;
    }
}