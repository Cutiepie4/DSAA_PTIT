/*
Hệ thống máy tính mới chuyển sang sử dụng hệ đếm tam phân với ba chữ số 0, 1, 2.

Do vốn đã quen với hệ đếm nhị phân nên Nam chỉ quan tâm đến các số tam phân thỏa mãn chữ số 2 chiếm ưu thế, tức là số lượng chữ số 2 chiếm nhiều hơn 50% số chữ số của số đó.

Hãy giúp Nam liệt kê N số tam phân ưu thế 2 đầu tiên.

Input
Dòng đầu ghi số bộ test (không quá 20)

Mỗi bộ test ghi số nguyên dương N (không quá 1000)

Output

Với mỗi test, viết trên một dòng N số tam phân ưu thế 2, các số cách nhau một khoảng trống.

Ví dụ

Input

Output

2

5

10

2 22 122 202 212

2 22 122 202 212 220 221 222 1222 2022
*/
#include <bits/stdc++.h>
using namespace std;

vector <string> Data;

void init() {
    queue <pair <string, int>> Q;
    Q.push({ "", 0 });
    while (1) {
        string s = Q.front().first;
        int cnt = Q.front().second;
        if (s[0] != '0' && cnt > s.size() / 2) {
            Data.push_back(s);
        }
        if (Data.size() > 1000) return;
        Q.pop();

        Q.push({ s + "0", cnt });
        Q.push({ s + "1", cnt });
        Q.push({ s + "2", cnt + 1 });
    }
}

int main() {
    init();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cout << Data[i] << " ";
        cout << endl;
    }
}