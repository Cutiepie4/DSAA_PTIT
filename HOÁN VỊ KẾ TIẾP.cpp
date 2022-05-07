/*
Cho số tự nhiên N và một hoán vị X[] của 1, 2, .., N. Nhiệm vụ của bạn là đưa ra hoán vị tiếp theo của X[]. Ví dụ N=5, X[] = {1, 2, 3, 4, 5} thì hoán vị tiếp theo của X[] là {1, 2, 3, 5, 4}.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là số N; dòng tiếp theo đưa vào hoán vị X[] của 1, 2, .., N.
T, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤ N≤103.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input
2
5 
1  2  3  4  5
5
5  4  3  2  1

Output
1 2  3  5  4

1 2  3  4  5
*/
#include <bits/stdc++.h>
using namespace std;

int process(vector <int> &v) {
    for (int i = v.size() - 2; i >= 0; i--) {
        if (v[i] < v[i + 1]) {
            for (int j = v.size() - 1; j > i; j--) {
                if (v[j] > v[i]) {
                    swap(v[j], v[i]);
                    reverse(v.begin() + i + 1, v.end());
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        for (auto& i : v) cin >> i;
        if(process(v) == 0) {
            reverse(v.begin(), v.end());
        }
        for(auto i:v) cout << i << " ";
            cout << endl;
    }
}