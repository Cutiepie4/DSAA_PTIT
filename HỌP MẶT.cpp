/*
Có K người (1 ≤ K ≤ 100) đứng tại vị í nào đó trong 
N địa điểm cho trước (1 ≤ N ≤ 1,000được đánh số 
từ 1..N. Các điểm được nối với nhau bởi M đoạn đường 
một chiều (1 ≤ M ≤ 10,000) (không có đoạn đường nào 
nối một điểm với chính nó).

Mọi người muốn cùng tụ họp tại mộtịa điểm nào đó. 
Tuy nhiên, với các đường đi cho trước, ỉ có một số 
địa điểm nào đó có thể được chọ là điểm họp mặt. 
Cho trước K, N, M và vị trí ban đầu của người cùng 
với M đường đi một chiều, 
hãy xác định xem có bao nhiêu điểm có t được chọn 
làm điểm họ mặt. 
*/
#include <bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define matrix vector <vector <int>>

int people, venue, road;
matrix M;
vt cur_stand, tmp;

vt intersec(vt& a, vt& b) {
    sort(b.begin(), b.end());
    vt c(max(a.size(), b.size()), -1);
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), c.begin());
    while (c.back() == -1) c.pop_back();
    return c;
}

void bfs(int s) {
    vt mark(venue + 1, 1);
    vt visit;
    mark[s] = 0;
    queue <int> q;
    q.push(s);
    while (!q.empty()) {
        int x = q.front();
        visit.push_back(x);
        q.pop();
        for (auto i : M[x]) {
            if (mark[i]) {
                mark[i] = 0;
                q.push(i);
            }
        }
    }
    tmp = intersec(tmp, visit);
}

void process() {
    tmp = vt(1001);
    iota(tmp.begin(), tmp.end(), 1);
    for (auto i : cur_stand) bfs(i);
    cout << tmp.size();
}

void solution() {
    cin >> people >> venue >> road;
    for (int i = 0, a; i < people; i++) {
        cin >> a;
        cur_stand.push_back(a);
    }
    M = matrix(venue + 1);
    for (int i = 0, a, b; i < road; i++) {
        cin >> a >> b;
        M[a].push_back(b);
    }
    process();
}

int main() {
    faster();
    solution();
    return 0;
}