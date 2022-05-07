/*
Sau khi thi trượt môn CTDL&GT, lớp PTIT_TLE được thành lập và có N sinh viên, xếp ngẫu nhiên thành một hàng dọc. Giả sử anh em đều nói khá to nên mỗi người có thể hỏi tên của chiến hữu đứng cách mình không quá K vị trí. Và nếu cặp nào đó có độ dài tên đúng bằng nhau thì sẽ trở thành một cặp bạn tốt, hứa hẹn sẽ hỗ trợ nhau trong những lần TLE tiếp theo.

Hãy đếm xem có bao nhiêu cặp bạn tốt tồn tại trong hàng.

Input

Ghi hai số N và K (3<=N<=300 000; 1<= K <=N)

Tiếp theo là N dòng, mỗi dòng ghi một cái tên (đều là chữ cái in hoa không dấu, không có khoảng trống).

Output

Ghi ra số cặp bạn tốt tìm được.

Ví dụ

Input

Output

4 2

NAM

TAM

THU

HAI

5

6 3

NAM

TRUNG

TRUONG

HUYEN

TU

NGUYEN

2
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> c(n);
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        c[i] = x.size();
    }
    ll ans = 0;
    map <ll, ll> M;
    for (int i = 0; i < k; i++) {
        ans += M[c[i]];
        M[c[i]]++;
    }
    for (int i = k; i < n; i++) {
        ans += M[c[i]];
        M[c[i]]++;
        M[c[i - k]]--;
    }
    cout << ans;
}