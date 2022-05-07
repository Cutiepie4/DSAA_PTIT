/*
Tại Chương Mỹ Resort, vào nửa đêm, cả trung đội nhận lệnh tập trung ở sân. Mỗi chiến sỹ được đánh số từ 1 đến N (1<N<40). Giám thị yêu cầu chọn ra một dãy K chiến sỹ để tập đội ngũ và cứ lần lượt duyệt hết tất cả các khả năng chọn K người như vậy từ nhỏ đến lớn (theo số thứ tự). Bài toán đặt ra là cho một nhóm K chiến sỹ hiện đang phải tập đội ngũ, hãy tính xem trong lượt chọn K người tiếp theo thì mấy người trong nhóm cũ sẽ được tạm nghỉ. Nếu đã là nhóm cuối cùng thì tất cả đều sẽ được nghỉ.

Dữ liệu vào: Dòng đầu ghi số bộ test, không quá 20. Mỗi bộ test viết trên hai dòng

Dòng 1: hai số nguyên dương N và K (K<N)
Dòng 2 ghi K số thứ tự của các chiến sỹ đang phải tập đội ngũ (viết từ nhỏ đến lớn)
Kết quả: Với mỗi bộ dữ liệu in ra số lượng chiến sỹ được tạm nghỉ.

 Ví dụ:

INPUT
3
5 3
1 3 5
5 3
1 4 5
6 4
3 4 5 6

OUTPUT
1
2
4
*/

#include <bits/stdc++.h>
using namespace std;

int process(vector <int>& v, int n, int k) {
    int kt = 1, i;
    for (i = k; i > 0; i--) {
        if (v[i] < n - k + i) {
            v[i]++;
            kt = 0; break;
        }
    }
    if (kt) return 0;
    for (int j = i + 1; j <= k; j++) {
        v[j] = v[i] + j - i;
    }
    return 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <int> v(k + 1);
        v.push_back(0);
        for (int i = 1; i <= k; i++) cin >> v[i];
        vector <int> v1 = v;
        int cnt = 0;
        if (process(v, n, k)) {
            sort(v.begin(), v.end());
            sort(v1.begin(), v1.end());
            for (auto i : v1) {
                if (i != 0 && !binary_search(v.begin(), v.end(), i)) {
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
        else {
            cout << k << endl;
        }
    }
}