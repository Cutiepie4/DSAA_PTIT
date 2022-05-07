/*
Cho dãy số A[] có N phần tử, N không quá 105, các số trong dãy đều nguyên dương và không quá 9 chữ số. Hãy tính độ dài của dãy con liên tiếp có trung bình cộng lớn nhất trong dãy.

Trong trường hợp có nhiều dãy con liên tiếp đều có trung bình cộng lớn nhất thì dãy nào dài hơn sẽ được chọn.

Input

Dòng đầu ghi số N.

Dòng thứ 2 ghi N số của dãy A[]

Output

Ghi ra độ dài dãy con liên tiếp có trung bình cộng lớn nhất tìm được.

Ví dụ

Input

Output

5

5 1 6 7 2

2
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    int Max = -1, cntmax = 0;
    vector <int> v(n);
    for (auto& i : v) {
        cin >> i;
        Max = max(Max, i);
    }
    for (auto& i : v) {
        if (i == Max) {
            cntmax++;
            ans = max(cntmax, ans);
        }
        else cntmax = 0;
    }
    cout << ans;
}