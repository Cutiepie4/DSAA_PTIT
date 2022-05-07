/*
Trong bài tập môn CTDL và GT, số may mắược hiểu 
là số chỉ có hai chữ số 4 và 7. 
Với mỗi số nguyên dương N thì sốn tiếp theo 
của N được định nghĩa là số may mắỏ nhất lớn hơn 
hoặc bằng N.

Cho hai số nguyên dương a và b (vớ <= b). 
Hãy tính tổng các số may mắn tiếcủa tất cả 
các số trong đoạn [a,b]
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector <ll> Data;
vector <ll> ::iterator it1, it2, it3;

void init() {
    queue <string> Q;
    Q.push("4");
    Q.push("7");
    while (Q.size()) {
        string s = Q.front();
        Data.push_back(stoll(s));
        Q.pop();

        if (s.size() < 10) {
            Q.push(s + '4');
            Q.push(s + '7');
        }
    }
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