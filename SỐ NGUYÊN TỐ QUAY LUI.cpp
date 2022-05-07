/*
Cho ba số N, P, S. Trong đó, P là một số nguyên tố. Nhiệm vụ của bạn là đưa ra tất cả N số nguyên tố tính từ P có tổng bằng S. Ví dụ với S = 28, P=7, N =2 ta có kết quả 11 + 17 = 28. Với N = 3, P = 2, S = 23 ta có kết quả : {3, 7, 13}, {5, 7, 11}

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ ba số S, P, N được viết trên một dòng.
S, P, N thỏa mãn ràng buộc: 1≤T ≤100; 1 ≤ N ≤ 10; 2≤S, P≤200.
Output:

Với mỗi test, dòng đầu tiên in ra số lượng đáp án tìm được. Mỗi dòng tiếp theo in ra kết quả tìm được theo thứ tự từ điển.
Input
2
2  7  28
3  2  23

Output
1
11 17
2
3 7 13
5 7 11
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

int N, P, S;
vts D;
vt p;

void init() {
    vt check(200, 1);
    check[0] = check[1] = 0;
    for (int i = 0; i * i < 200; i++) {
        if (check[i]) {
            for (int j = i * i; j <= 200; j += i) {
                check[j] = 0;
            }
        }
    }
    for (int i = 2; i < 200; i++) if (check[i]) p.push_back(i);
}

void back(int index, string s, int sum, int cnt) {
    for (int i = index; i < p.size() - 1; i++) {
        if (p[i] > S) return;
        int sumtmp = sum + p[i];
        if (sumtmp <= S) {
            if (sumtmp == S) {
                if (cnt == N - 1) D.push_back(s + to_string(p[i]));
                return;
            }
            else back(i + 1, s + to_string(p[i]) + " ", sumtmp, cnt + 1);
        }
        else return;
    }
}

void solution() {
    cin >> N >> P >> S;
    D.clear();
    int i = 0;
    while (p[i] <= P) i++;
    back(i, "", 0, 0);
    cout << D.size() << endl;
    sort(D.begin(), D.end());
    for (auto i : D) cout << i << endl;
}

int main() {
    faster();
    int T;
    cin >> T;
    init();
    while (T--) {
        solution();
        cout << endl;
    }
    return 0;
}