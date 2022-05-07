/*
Cho hai đa thức có bậc không quá 10000 (chỉ viết ra các phần tử có hệ số khác 0). Hãy sử dụng danh sách liên kết đơn để viết chương trình tính tổng hai đa thức đó.

Dữ liệu vào: Dòng đầu ghi số bộ test. Mỗi bộ test có hai dòng, mỗi dòng ghi một đa thức theo mẫu như trong ví dụ. Số phần tử của đa thức không quá 20.

Chú ý: Bậc của các hạng tử luôn theo thứ tự giảm dần, trong đa thức chỉ có phép cộng và luôn được viết đầy đủ hệ số + số mũ (kể cả mũ 0).

Kết quả: Ghi ra một dòng đa thức tổng tính được (theo mẫu như ví dụ)

Ví dụ:

Input

Output

1

3*x^8 + 7*x^2 + 4*x^0

11*x^6 + 9*x^2 + 2*x^1 + 3*x^0

3*x^8 + 11*x^6 + 16*x^2 + 2*x^1 + 7*x^0
*/
#include <bits/stdc++.h>
using namespace std;

string a, b;
vector <int> cnt;

void split(string s) {
    stringstream ss(s);
    string tmp;
    while (getline(ss, tmp, '+')) {
        int inx = 0;
        vector <string> v(2);

        for (auto i : tmp) {
            if (isdigit(i)) v[inx].push_back(i);
            else if (!v[inx].empty()) inx++;
        }
        cnt[stoi(v[1])] += stoi(v[0]);
    }
}

void out() {
    int inx = 10000;
    for (int i = inx; i >= 0; i--) {
        if (cnt[i]) {
            cout << cnt[i] << "*x^" << i;
            inx = i - 1;
            break;
        }
    }
    for (int i = inx; i >= 0; i--) {
        if (cnt[i]) {
            cout << " + " << cnt[i] << "*x^" << i;
        }
    }
}

void solution() {
    getline(cin, a);
    getline(cin, b);
    cnt = vector <int>(10000, 0);
    split(a);
    split(b);
    out();
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        solution();
        cout << endl;
    }
}