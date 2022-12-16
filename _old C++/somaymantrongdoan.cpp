/*
Trong bài tập môn CTDL và GT, số may mắn ược hiểu 
là số chỉ có hai chữ số 4 và 7. 
Với mỗi số nguyên dương N thì số may mn tiếp theo 
của N được định nghĩa là số may mắn nỏ nhất lớn hơn 
hoặc bằng N.

Cho hai số nguyên dương a và b (với  <= b). 
Hãy tính tổng các số may mắn tiếp theocủa tất cả 
các số trong đoạn [a,b]
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set <string> ss;
vector <ll> Data;
set <string> ::iterator it;
vector <ll> ::iterator it1, it2, it3;

ll cvt(string s) {
    ll res = 0;
    for (auto i : s) res = res * 10 + i - '0';
    return res;
}

void init() {
    ss.insert("");
    for (ll i = 1; i <= 10; i++) {
        set <string> tmp = ss;
        for (it = tmp.begin(); it != tmp.end(); it++) {
            ss.insert(*it + "4");
            ss.insert(*it + "7");
        }
    }
    for (it = ss.begin(); it != ss.end(); it++) {
        Data.push_back(cvt(*it));
    }
    sort(Data.begin(), Data.end());
}

void solution() {
    ll l, r;
    ll ans = 0;
    cin >> l >> r;
    init();
    it1 = lower_bound(Data.begin(), Data.end(), l);
    it2 = upper_bound(it1, Data.end(), r);
    advance(it2, 1);
    ll tmp = l;
    for (it3 = it1; it3 != it2; it3++) {
        if (*it3 <= r) {
            ans += *it3 * (*it3 - tmp + 1);
            tmp = *it3 + 1;
        }
        else {
            ll x = *it3;
            advance(it3, -1);
            ans += x * (r - *it3);
            break;
        }
    }
    cout << ans;
}

int main() {
    solution();
}