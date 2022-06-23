/*
Cho hai số N, K và một tập con K phần tử X[] =(X1, X2,.., XK) của 1, 2, .., N. Nhiệm vụ của bạn là hãy đưa ra tập con K phần tử tiếp theo của X[]. Ví dụ N=5, K=3, X[] ={2, 3, 4} thì tập con tiếp theo của X[] là {2, 3, 5}.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là hai số N và K; dòng tiếp theo đưa vào K phần tử của X[] là một tập con K phần tử của 1, 2, .., N.
T, K, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤K≤N≤103.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input
2
5  3
1  4  5
5  3
3  4  5

OUTPUT
2  3  4
1  2  3
*/
#include <bits/stdc++.h>
using namespace std;

int n, k;

void next_combination(vector <int>& v) {
    for (int i = k; i > 0; i--) {
        if (v[i] < n - k + i) {
            v[i]++;
            for (int j = i + 1; j <= k; j++) {
                v[j] = v[i] + j - i;
            }
            return;
        }
    }
    for (int i = 1; i <= k; i++) v[i] = i;
    return;
}

void solution() {
    cin >> n >> k;
    vector <int> v(k + 1);
    for (int i = 1; i <= k; i++) cin >> v[i];
    next_combination(v);
    for (int i = 1; i <= k; i++) cout << v[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}