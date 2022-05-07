/*
Cho hai cây nhị phân, nhiệm vụ của bạn là kiểm tra xem cây nhị phân có giống nhau hay không?

    Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái của mỗi cây; u, v, x được viết cách nhau một vài khoảng trống.
T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
Output:

Đưa ra kết quả mỗi test theo từng dòng.
      Ví dụ:

Input
2
2
1 2 L 1 3 R
2
1 2 L 1 3 R
2
1 2 L 1 3 R
2
1 3 L 1 2 R

Output
1
0
*/
#include <bits/stdc++.h>
using namespace std;
#define vt vector <int>

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

void Inorder(node*& root, vt& path) {
    if (root->le != NULL) Inorder(root->le, path);
    path.push_back(root->data);
    if (root->ri != NULL) Inorder(root->ri, path);
}

void solution() {
    int n;
    node* root1, * root2;
    cin >> n;
    add_node(root1, n);
    cin >> n;
    add_node(root2, n);
    vt p1, p2;
    Inorder(root1, p1);
    Inorder(root2, p2);
    cout << (p1 == p2);
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