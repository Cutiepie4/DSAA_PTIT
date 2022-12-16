/*
Ta định nghĩa phép toán tor (a tor b) như sau: giả xử ta cần tính
toán phép tính a tor b, 2 số a và b sẽ được chuyển sang hệ cơ số 3 và
sau đó thêm vào các số 0 ở đầu sao cho ta được 2 xâu có cùng độ dài.
Với các bit tương ứng trong 2 xâu, bit tương ứng của kết quả sẽ là tổng
2 bit của 2 xâu đó và sau đó lấy phần dư khi chia cho 3.
Cuối cùng kết quả được tính ngược về hệ cơ số 10.
Vd: 1610 tor 6110 = 01213 tor 20213 = 21123 = 6810
Bài toán đặt ra yêu cầu: Cho 2 số a và c tìm số b thỏa mãn a tor b = c.”
Input
Dòng đầu chưa 2 số nguyên a và c (0 <= a, c <= 109)
Output
Số nguyên b duy nhất là số cần tìm thỏa mãn a tor b = c.
*/
#include <bits/stdc++.h>
using namespace std;
string reverse(string a) {
	string res = "";
	for (int i = a.size() - 1; i >= 0; i--) res.push_back(a[i]);
	return res;
}
int cvston(string a) {
	int res = 0;
	for (int i = 0; i < a.size(); i++) res = res * 10 + a[i] - '0';
	return res;
}
string cv10to3(int a) {
	string res = "";
	while (a > 0) {
		res.push_back(a % 3 + '0');
		a /= 3;
	}
	return reverse(res);
}
string tor(string a, string b) {
	while (a.size() < max(a.size(), b.size())) a = "0" + a;
	while (b.size() < max(a.size(), b.size())) b = "0" + b;
	string tmp = "";
	for (int i = 0; i < a.size(); i++)
		tmp.push_back((a[i] + b[i] - '0' - '0') % 3 + '0');
	return tmp;
}

int cv3to10(string a) {
	int res = 0;
	for (int i = a.size() - 1; i >= 0; i--) {
		res += (a[i] - '0') * pow(3, a.size() - 1 - i);
	}
	return res;
}
int main() {
	string a, c;
	cin >> a >> c;
	int x = cvston(c);
	for (int i = 0; i <= 99999999; i++) {
		string tmp = tor(cv10to3(cvston(a)), cv10to3(i));
		int x1 = cv3to10(tmp);
		if (x1 == x) {
			cout << i; return 0;
		}
	}
}