/*
Cho một cây có N đỉnh và gốc tại đỉn 1. Mỗi nút lá 
có chức năng tổng hợp chất dinh dưỡng, ồng thời lan 
truyền năng lượng cũng như ác chất 
dinh dưỡng cho nút cha của nó để thực hin quá trình 
tổng hợp.

Quá trình lan truyền năng lượng sẽ làm tng giá trị 
dinh dưỡng lên 1. Tức là nếu một nút tổng hợp được giá trị dinh dưỡng bằng V, sẽ giúp cho nút cha của nó sẽ tổng hợp được giá trị dinh dưỡng bằng V+1. Nếu một nút cha có nhiều nút con, giá trị dinh dưỡng của nó bằng tổng của giá trị dinh dưỡng của các nút con gửi lên.

Biết rằng mỗi nút lá ban đầu tổng hợpđược chất dinh 
dưỡng có giá trị 1. Nhiệm vụ của bạn à hãy xác định 
xem mỗi nút của cây tổng hợp được baonhiêu giá trị 
dinh dưỡng?
*/
// bị TLE
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define fi first
#define se second
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define matrix vector <vector <int>>
#define matrixl vector <vector <ll>>
const ll MOD = 1e9 + 7;

int n;
vt node, leaf, M;

void bfs() {
    queue <int> q;
    vt mark(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        if (leaf[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        if (mark[M[q.front()]]) {
            q.push(M[q.front()]);
            mark[M[q.front()]] = 0;
        }
        mark[q.front()] = 1;
        node[M[q.front()]] += node[q.front()] + 1;
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
    M = vt(n + 1);
    node = vt(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        cin >> M[i];
        leaf[M[i]] = 0;
    }
    process();
}

int main() {
    faster();
    solution();
    return 0;
}