/*
Cho dãy A[] có N số nguyên, mỗi số có đúng K chữ số (có thể có chữ số 0 ở đầu). 
Gọi độ chênh lệch của dãy là hiệu giữa phần tử lớn nhất và bé nhất của dãy.
Bạn có thể hoán vị các chữ số của một số để tạo số mới (có thể có chữ số 0 ở đầu). 
Bằng cách hoán vị tất cả n số theo cùng một cách, ta nhận được dãy số mới.
Tìm độ chênh lệch nhỏ nhất có thể tạo được.
*/
#include <bits/stdc++.h>
using namespace std;

int cvt(string s) {
    int res = 0;
    for (auto i : s) res = res * 10 + i - '0';
    return res;
}

int process(vector <string> v) {
    int res = 0;
    vector <int> tmp(v.size());
    for (int i = 0; i < v.size(); i++) tmp[i] = cvt(v[i]);
    for (int i = 0; i < tmp.size();i++) {
        for (int j = i + 1; j < tmp.size(); j++) {
            res = max(res, abs(tmp[i] - tmp[j]));
        }
    }
    return res;
}

int main() {
    int n, k, ans = INT32_MAX;
    cin >> n >> k;
    vector <int> x(k), cnt(k + 1);
    cnt[0] = 1;
    for (int i = 0; i < k; i++) {
        cnt[i + 1] = cnt[i] * (i + 1);
    }
    for (int i = 0; i < k; i++) x[i] = i;


    vector <string> v(n);
    for (auto& i : v) cin >> i;
    while (cnt[k]--) {
        vector <string> tmp(n);
        for (int i = 0; i < n; i++) {
            string s;
            for (int j = 0; j < k; j++) {
                s.push_back(v[i][x[j]]);
            }
            tmp[i] = s;
        }
        ans = min(ans, process(tmp));
        next_permutation(x.begin(), x.end());
    }
    cout << ans;
}