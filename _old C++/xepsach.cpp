/*
Có N quyển sách, đánh nhãn đôi một khác nhau từ 1 đến N xếp ngẫu nhiên
trên một chồng. Bạn cần sắp xếp lại chồng sách theo thứ tự nhãn từ 1 đến N 
(tính từ đỉnh của chồng sách). Mỗi lượt di chuyển, bạn cỉ có thể lấy ra một 
quyển sách và đặt nó lên đỉnh của chồng sách.

Ví dụ: Nếu N=3, và thứ tự nhãn từ đỉnh ban đầu của chồng sách là {3,2,1},
bạn có thể lấy ra cuốn có nhãn là 2 và đặt lên đầu, chồng sách trở thành {2,3,1}.
Tiếp theo, lấy cuốn có nhãn là 1, và đặt lên đầu, chồng sách trở thành {1,2,3}.

Nhiệm vụ của bạn là tìm xem cần tối thiểu bao nhiêu lượt di chuyển.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n + 1], res = 0, x = n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i > 0; i--) {
		if (a[i] == x) {
			x--;
		}
		else res++;
	}
	cout << res;
}