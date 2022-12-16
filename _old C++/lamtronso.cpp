/*
Cho trước một số nguyên, người ta sẽ làm tròn số này theo quy tắc sau:

Nếu số đó lớn hơn 10 thì sẽ được làm tròn đến số hàng chục gần nhất
Sau đó nếu kết quả lớn hơn 100 thì làm tròn đến số hàng trăm gần nhất
Sau đó nếu kết quả lớn hơn 1000 thì làm tròn đến số hàng nghìn gần nhất
…cứ tiếp tục như vậy …
Chú ý: giá trị 5 được làm tròn lên.

Hãy viết chương trình làm tròn số theo quy tắc trên.
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