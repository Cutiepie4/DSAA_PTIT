/*
Cho cây nhị phân, nhiệm vụ của bạn là duyệt cây theo Level-order. Phép duyệt level-order trên cây là phép thăm node theo từng mức của cây. Ví dụ với cây dưới đây sẽ cho ta kết quả của phép duyệt level-order: 20  8  22  4  12  10  14.



    Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được viết cách nhau một vài khoảng trống.
T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
Output:

Đưa ra kết quả phép duyệt level-order theo từng dòng.
     Ví dụ:

Input
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output
1 3 2
10 20 30 40 60
*/
#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* le;
    node* ri;
    node(int x) {
        data = x;
        le = ri = NULL;
    }
};

void add_node(node*& root, int n) {
    map <int, node*> m;
    int u, v;
    char c;
    while (n--) {
        cin >> u >> v >> c;
        if (m.find(u) == m.end()) {
            root = new node(u);
            if (c == 'L') {
                root->le = new node(v);
                m[v] = root->le;
            }
            else {
                root->ri = new node(v);
                m[v] = root->ri;
            }
            m[u] = root;
        }
        else {
            if (c == 'L') {
                m[u]->le = new node(v);
                m[v] = m[u]->le;
            }
            else {
                m[u]->ri = new node(v);
                m[v] = m[u]->ri;
            }
        }
    }
}

void Level_order(node*& root) {
    queue <node*> Q;
    Q.push(root);

    while (!Q.empty()) {
        node* X = Q.front();
        Q.pop();
        cout << X->data << " ";

        if (X->le != NULL) Q.push(X->le);
        if (X->ri != NULL) Q.push(X->ri);
    }
}

void solution() {
    int n;
    cin >> n;
    node* root;
    add_node(root, n);
    Level_order(root);
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