/*
Cho cây nhị phân, nhiệm vụ của bạn là tính tổng của tất cả các node lá bên phải trên cây? Ví dụ với cây dưới đây ta có kết quả là 2.





     Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được viết cách nhau một vài khoảng trống.
T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
Output:

Đưa ra kết quả mỗi test theo từng dòng.
      Ví dụ:

Input

Output

2
2
1 2 L 1 3 R
5
10 20 L 10 30 R 20 40 L 20 60 R 30 90 L

3
60
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

int sum = 0;

void sum_right_node(node*& root, int ok) {
    if (root == NULL) return;
    if (ok && root->left == NULL && root->right == NULL) sum += root->data;
    sum_right_node(root->right, 1);
    sum_right_node(root->left, 0);
}

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

void solution() {
    map <int, int> mark;
    node* root = NULL;
    int e, u, v;
    char c;
    cin >> e;
    add_node(e, root);
    sum = 0;
    sum_right_node(root, 0);
    cout << sum;
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