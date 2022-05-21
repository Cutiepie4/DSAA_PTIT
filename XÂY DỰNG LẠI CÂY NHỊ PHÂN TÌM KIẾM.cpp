/*
Cho một mảng là phép duyệt level-order của cây nhị phân tìm kiếm. Nhiệm vụ của bạn là xây dựng lại cây nhị phân tìm kiếm bảo toàn được cấu trúc cây nhị phân ban đầu.

     Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm dòng: dòng đầu tiên đưa vào số N là số lượng node của cây tìm kiếm; dòng tiếp theo đưa vào phép duyệt level-order của cây tìm kiếm; các số được viết cách nhau một vài khoảng trống.
T, N, node thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤node≤104;
Output:

Đưa ra kết quả mỗi test theo từng dòng là phép duyệt trước (preOrder) của cây tìm kiếm.
      Ví dụ:

Input
2
9
7 4 12 3 6 8 1 5 10
6
1 3 4 6 7 8

Output
7 4 3 1 6 5 12 8 10
1 3 4 6 7 8
*/
#include <bits/stdc++.h>
using namespace std;

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

void Preorder(node*& root) {
    if (root) {
        cout << root->data << " ";
        Preorder(root->le);
        Preorder(root->ri);
    }
}

void solution() {
    int n;
    node* root = NULL;
    cin >> n;
    for (int i = 0, u; i < n; i++) {
        cin >> u;
        add_node(root, u);
    }
    Preorder(root);
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