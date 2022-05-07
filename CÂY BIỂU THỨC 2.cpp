/*
Cho một cây biểu thức là một cây nhị phân đầy đủ bao gồm các phép toán +, -, *. / và một số toán hạng có giá trị nguyên. Nhiệm vụ của bạn là hãy tính toán giá trị biểu thức được biểu diễn trên cây nhị phân đầy đủ. Ví dụ với cây dưới đây là biểu diễn của biểu thức P = ( (5*4) + (100-20)) sẽ cho ta giá trị là 100.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test là gồm hai dòng: dòng thứ nhất đưa vào N là số lượng node của cây; dòng thứ hai đưa vào nội dung các node của cây; các node được viết cách nhau một vài khoảng trống. Các số có giá trị nguyên không vượt quá 1000.
T, N, P thỏa mãn ràng buộc : 1≤T≤100; 1≤N, lenght(P)≤100.
Output:

Đưa ra giá trị của cây biểu thức.
     Ví dụ:

Input
2
7
+ * - 5 4 100 20
3
- 4 7 

Output
100
-3
*/

#include <bits/stdc++.h>
using namespace std;
#define vts vector <string>

int cal(vts v, int idx) {
    if (v[idx] == "+") return cal(v, idx * 2 + 1) + cal(v, idx * 2 + 2);
    if (v[idx] == "-") return cal(v, idx * 2 + 1) - cal(v, idx * 2 + 2);
    if (v[idx] == "*") return cal(v, idx * 2 + 1) * cal(v, idx * 2 + 2);
    if (v[idx] == "/") return cal(v, idx * 2 + 1) / cal(v, idx * 2 + 2);
    return stoi(v[idx]);
}

void solution() {
    int n;
    cin >> n;
    vts v(n);
    for (auto& i : v) cin >> i;
    cout << cal(v, 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}