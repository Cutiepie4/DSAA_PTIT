/*
Cho số nguyên dương không quá 9 chữ số. Hãy làm tròn số N theo quy tắc sau:

Nếu N>10, làm tròn đến số hàng chục gần nhất
Sau đó nếu kết quả lớn hơn 100 thì làm tròn đến số hàng trăm gần nhất
Sau đó nếu kết quả lớn hơn 1000 thì làm trong đến số hàng nghìn gần nhất
Cứ tiếp tục như vậy …
Chú ý: Giá trị 5 sẽ được làm tròn lên.

Input

Dòng đầu ghi số bộ test (không quá 100)

Mỗi bộ test ghi số N trên một dòng (N nguyên dương và không quá 9 chữ số)

Output
Với mỗi test, ghi ra kết quả làm tròn tương ứng trên một dòng.
Ví dụ
Input
7
15
14
5
99
12345678
44444445
1445

OUTPUT:
20
10
5
100
10000000
50000000
200
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        int mem = 0;
        for (int i = a.size() - 1; i > 0; i--) {
            if (a[i] < '5') a[i] = '0';
            else {
                mem = 1; a[i] = '0';
                a[i - 1] += mem; mem = 0;
            }
        }
        if (a[0] > '9') {
            a[0] = '0', a.insert(0, "1");
        }
        cout << a << endl;
    }
}