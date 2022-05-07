/*
Kỳ thi ICPC có K đội của PTIT tham gia và đội tuyển đang rất đau đầu không biết chọn các cái tên như thế nào cho các đội. Yêu cầu phải đảm bảo tên không có khoảng trống và không được trùng nhau. Sau khi thảo luận, có N cái tên được đề xuất (có thể bị trùng nhau). Với K<15 và 4 < N < 30.

Hãy liệt kê tất cả danh sách các tổ hợp K cái tên khác nhau có thể được tạo ra theo thứ tự từ điển.

Input

Dòng đầu ghi 2 số N và K.

Tiếp theo là 1 dòng ghi N cái tên, mỗi cái tên có độ dài không quá 15 và cách nhau một khoảng trống. Tất cả đều là ký tự in hoa.

Output

Ghi ra tất cả các tổ hợp tên có thể được lựa chọn theo thứ tự từ điển.

Tức là các tên trong mỗi tổ hợp liệt kê theo thứ tự từ điển và các tổ hợp cũng được liệt kê theo thứ tự từ điển.

Ví dụ
Input
6 2
DONG TAY NAM BAC TAY BAC

Output
BAC DONG
BAC NAM
BAC TAY
DONG NAM
DONG TAY
NAM TAY
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define pi pair <int,int>
#define matrix vector <vt>
#define matrixl vector <vtl>
const int MOD = 1e9 + 7;

set <string> D;
int n, k;
vts V;

void next_com(vector <int>& v, int k, int n) {
    string tmp;
    for (int i = 1; i <= k; i++) {
        tmp += V[v[i] - 1] + " ";
    }
    cout << tmp << endl;
    int i;
    // tìm i lớn nhất sao cho a[i] < n - k + i, tức là tìm a[i] mà chưa đạt cấu hình max đầu tiên từ dưới lên
    for (i = k; i > 0; i--) {
        if (v[i] < n - k + i) {
            v[i]++;
            for (int j = i + 1; j <= k; j++) {
                v[j] = v[i] + j - i;
            }
            next_com(v, k, n);
        }
    }
    return;
}

void solution() {
    D.clear();
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        D.insert(tmp);
    }
    for (auto i : D) V.push_back(i);
    vt v(V.size() + 1, 0);
    iota(v.begin() + 1, v.end(), 1);
    next_com(v, k, V.size());
}

int main() {
    faster();
    solution();
    return 0;
}