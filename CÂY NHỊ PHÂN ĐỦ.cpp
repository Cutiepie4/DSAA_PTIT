/*
Cho cây nhị phân, nhiệm vụ của bạn là kiểm tra xem cây nhị phân có phải là một cây đủ hay không (full binary tree)? Một cây nhị phân được gọi là cây đủ nếu tất cả các node trung gian của nó đều có hai node con.

      Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được viết cách nhau một vài khoảng trống.
T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
Output:

Đưa ra kết quả mỗi test theo từng dòng.
     Ví dụ:

Input
2
4
1 2 L 1 3 R 2 4 L 2 5 R
3
1 2 L 1 3 R 2 4 L

Output
1
0
*/
#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int x) {
        data = x;
        left = right = NULL;
    }
};

void add_node(int n, node*& root) {
    map <int, node*> m;
    while (n--) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        if (m.find(u) == m.end()) {
            root = new node(u);
            if (c == 'L') {
                root->left = new node(v);
                m[v] = root->left;
            }
            else {
                root->right = new node(v);
                m[v] = root->right;
            }
            m[u] = root;
        }
        else {
            if (c == 'L') {
                m[u]->left = new node(v);
                m[v] = m[u]->left;
            }
            else {
                m[u]->right = new node(v);
                m[v] = m[u]->right;
            }
        }
    }
}

int check(node*& root) {
    queue <pair <node*, int>> Q;
    Q.push({ root,0 });

    while (!Q.empty()) {
        node* X = Q.front().first;
        int cnt = Q.front().second;
        Q.pop();

        if (X->left != NULL) {
            if (X->right == NULL) return 0;
            Q.push({ X->left, cnt + 1 });
        }
        if (X->right != NULL) {
            if (X->left == NULL) return 0;
            Q.push({ X->right, cnt + 1 });
        }
    }
    return 1;
}

void solution() {
    node* root = NULL;
    int e;
    cin >> e;
    add_node(e, root);
    cout << check(root);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(), cout.tie();
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}