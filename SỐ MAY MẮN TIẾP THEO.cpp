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
    auto it = lower_bound(Data.begin(), Data.end(), l);
    for (int i = l; i <= r;) {
        ans += (*it - i + 1) * *it;
        i = *it + 1;
        it++;
    }
    cout << ans;
}

int main() {
    solution();
}