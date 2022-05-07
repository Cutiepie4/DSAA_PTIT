/*
Cho hai số nguyên dương a,b. Hãy đếm xem trong đoạn [a,b] có bao nhiêu số có tổng các ước số (không tính chính nó) lớn hơn giá trị của nó.
Ví dụ: số 12 có tổng ước số là 1 + 2 + 3 + 4 + 6 = 16 > 12.
Input
Chỉ có hai số a và b (1 <= a <= b <= 106).
Output
Ghi ra số lượng các số thỏa mãn.
Ví dụ

Input
1 50
OUTPUT:
9
*/
// số có tổng ước lớn hơn nó
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int l, r, res = 0;

void process() {
    vector <int> a(r + 1, 1);
    for (int i = 2; i <= r / 2; i++)
        for (int j = 2; j <= r / i; j++)
            a[i * j] += i;
    for (int i = l; i <= r; i++)
        if (a[i] > i) res++;
}

int main() {
    cin >> l >> r;
    process();
    cout << res;
    return 0;
}