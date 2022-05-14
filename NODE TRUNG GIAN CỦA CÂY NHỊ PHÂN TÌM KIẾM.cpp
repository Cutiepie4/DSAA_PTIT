/*
Cho dãy số gồm N số là phép duyệt theo thứ tự trước (Preorder) của một cây nhị phân tìm kiếm. Hãy đưa ra số các node trung gian của cây ?

Ví dụ với dãy A[] = {30, 20, 15, 25, 23, 28, 40, 35, 33, 38, 45} là phép duyệt cây theo thứ tự trước sẽ cho ta kết quả là 5 bao gồm cá40, 35.                     

     Input:

Dòng đầu tiên đưa vào số lượng bộ test T (T≤100).
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất là số tự nhiên N (N≤1000). Dòng tiếp theo là N số là phép duyệt theo thứ tự trước của cây BST.
     Output:

Đưa ra kết quả mỗi test theo từng dòng.
    Ví dụ:

Input:
2
6
10 5 1 7 40 50
11
30 20 15 25 23 28 40 35 33 38 45

Output
3
5
*/
#include <bits/stdc++.h>
using namespace std;

int cnt;

struct node {
    int data;
    node* le, * ri;
    node(int x) {
        data = x;
        le = ri = NULL;
    }
};

void add_node(node*& root, int u) {
    if (!root) {
        root = new node(u);
        return;
    }
    if (root->data < u) add_node(root->ri, u);
    else add_node(root->le, u);
}

void Find_leaf(node*& root) {
    if (root && !root->le && !root->ri) {
        cnt++;
        return;
    }
    if (root->le) Find_leaf(root->le);
    if (root->ri) Find_leaf(root->ri);
}

void solution() {
    int n;
    cin >> n;
    cnt = 0;
    node* root = NULL;
    for (int i = 0, u; i < n; i++) {
        cin >> u;
        add_node(root, u);
    }
    Find_leaf(root);
    cout << n - cnt;
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