/*
Xâu ký tự str được gọi là xâu AB nếu mỗi ký tự trong xâu hoặc là ký tự ‘A’ hoặc là ký tự ‘B’. 
Ví dụ xâu str=”ABBABB” là xâu AB độ dài 6. Nhiệm vụ của bạn là hãy liệt kê tất cả các xâu AB có độ dài n.
Input
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên n.
T, n thỏa mãn ràng buộc: 1≤T≤10; 1≤n≤10.
Output:
Đưa ra kết quả mỗi test theo từng dòng. Mỗi xâu cách nhau 1 khoảng trống.
Input
2
2
3
Output
AA AB BA BB
AAA AAB ABA ABB BAA BAB BBA BBB
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

vector <vts> D(11);

void init() {
    D[1].push_back("A");
    D[1].push_back("B");
    for (int i = 2; i < 11; i++) {
        for (auto j : D[i - 1]) {
            D[i].push_back(j + 'A');
            D[i].push_back(j + 'B');
        }
    }
}

void solution() {
    int n;
    cin >> n;
    for (auto i : D[n]) cout << i << " ";
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