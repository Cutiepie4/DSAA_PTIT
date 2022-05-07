/*
Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các cách phân tích số tự nhiên N thành tổng các số tự nhiên nhỏ hơn hoặc bằng N. Phép hoán vị của một cách được xem là giống nhau. Ví dụ với N = 5 ta có kết quả là: (5), (4, 1), (3, 2), (3, 1, 1), (2, 2, 1), (2, 1, 1, 1), (1, 1, 1, 1, 1) .

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
T, n thỏa mãn ràng buộc: 1≤T, N≤10.
Output:

Dòng đầu tiên là số lượng cách phân tích thỏa mãn. Dòng tiếp theo liệt kê đáp án theo mẫu ví dụ đã cho.
Ví dụ:

Input
2
4
5

Output
5
(4) (3 1) (2 2) (2 1 1) (1 1 1 1)
7
(5) (4 1) (3 2) (3 1 1) (2 2 1) (2 1 1 1) (1 1 1 1 1)
*/
#include <bits/stdc++.h>
using namespace std;

vector <string> D;

void process(vector <int> v, int index, string tmp1, int n, int sum) {
    for (int i = index; i < n; i++) {
        int x = sum + v[i];
        if (x <= n) {
            string tmp = tmp1;
            tmp += " ";
            tmp += to_string(v[i]);
            if (x == n) {
                tmp += ")";
                D.push_back(tmp);
            }
            else process(v, i, tmp, n, x);
        }
    }
}

void solution() {
    int n;
    D.clear();
    cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) v[i] = n - i;

    for (int i = 0; i < n; i++) {
        string tmp = "(";
        tmp += to_string(v[i]);
        if (i == 0) {
            tmp += ")";
            D.push_back(tmp);
        }
        else process(v, i, tmp, n, v[i]);
    }
    cout << D.size() << endl;
    for(auto i:D) cout << i << " ";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}