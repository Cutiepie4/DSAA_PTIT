/*
Cho N điểm trên mặt phẳng Oxy. Để vẽ được đoạn thẳng nối A và B sẽ tốn chi phí tương đương với khoảng cách từ A tới B.

Nhiệm vụ của bạn là nối các điểm với nhau, sao cho N điểm đã cho tạo thành 1 thành phần liên thông duy nhất và chi phí để thực hiện là nhỏ nhất có thể.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test bắt đầu bởi số nguyên N (1 ≤ N ≤ 100).
N dòng tiếp theo, mỗi dòng gồm 2 số thực x[i], y[i] là tọa độ của điểm thứ i (|x[i]|, |y[i]| ≤ 100).
Output:

Với mỗi test, in ra chi phí nhỏ nhất tìm được với độ chính xác 6 chữ số thập phân sau dấu phẩy.
Ví dụ:

Input:
1
3
1.0 1.0
2.0 2.0
2.0 4.0

Output
3.414214
*/
#include <bits/stdc++.h>
using namespace std;
#define point pair <int,int>
#define pp pair <double, point>
#define f first
#define s second

int n;
vector <point> P;
vector <pp> E;

double dis(point a, point b) {
    double res = 0;
    res = (a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s);
    return sqrt(res);
}

void init() {
    E.clear();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            E.push_back({ dis(P[i],P[j]), {i, j} });
        }
    }
    sort(E.begin(), E.end());
}

int check(int u, int v, vector <int>& mark) {
    return (mark[u] == 0 && mark[v]) || (mark[u] && mark[v] == 0);
}

double build_graph() {
    int cnt = 2;
    vector <int> mark(n, 1);
    double ans = E[0].f;
    mark[E[0].s.f] = mark[E[0].s.s] = 0;

    while (cnt != n) {
        for (int i = 1; i < E.size(); i++) {
            int u = E[i].s.f, v = E[i].s.s;
            if (check(u, v, mark)) {
                mark[u] = mark[v] = 0;
                ans += E[i].f;
                cnt++;
                E.erase(E.begin() + i);
                break;
            }
        }
    }

    return ans;
}

void solution() {
    P.clear();
    cin >> n;
    for (int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        P.push_back({ a,b });
    }
    init();
    cout << setprecision(6) << fixed << build_graph();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}