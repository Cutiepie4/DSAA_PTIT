/*
Cho một cây có N đỉnh và gốc tại đỉ 1. Mỗi nút lá 
có chức năng tổng hợp chất dinh dưỡồng thời lan 
truyền năng lượng cũng nhưác chất 
dinh dưỡng cho nút cha của nó để thựn quá trình 
tổng hợp.

Quá trình lan truyền năng lượng sẽ làng giá trị 
dinh dưỡng lên 1. Tức là nếu một nút tổng hợp được giá trị dinh dưỡng bằng V, sẽ giúp cho nút cha của nó sẽ tổng hợp được giá trị dinh dưỡng bằng V+1. Nếu một nút cha có nhiều nút con, giá trị dinh dưỡng của nó bằng tổng của giá trị dinh dưỡng của các nút con gửi lên.

Biết rằng mỗi nút lá ban đầu tổng hợđược chất dinh 
dưỡng có giá trị 1. Nhiệm vụ của bạà hãy xác định 
xem mỗi nút của cây tổng hợp đượnhiêu giá trị 
dinh dưỡng?
*/
// bị TLE
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vt vector <int>
#define matrix vector <vt>

int n;
vt node, leaf, Prv;

void bfs() {
    queue <int> q;
    vt mark(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        if (leaf[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        if (mark[Prv[q.front()]]) {
            q.push(Prv[q.front()]);
            mark[Prv[q.front()]] = 0;
        }
        mark[q.front()] = 1;
        node[Prv[q.front()]] += node[q.front()] + 1;
        q.pop();
    }
}

void process() {
    bfs();
    for (int i = 1; i <= n; i++) cout << node[i] << " ";
}

void solution() {
    cin >> n;
    leaf = vt(n + 1, 1);
    Prv = vt(n + 1);
    node = vt(n + 1, 1);
    Prv[1] = 0;
    Prv[0] = 0;
    for (int i = 2; i <= n; i++) {
        cin >> Prv[i];
        leaf[Prv[i]] = 0;
    }
    process();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solution();
    return 0;
}