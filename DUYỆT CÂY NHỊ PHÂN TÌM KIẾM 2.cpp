/*
Cho mảng A[] gồm N node là biểu diễn phép duyệt theo thứ tự giữa (Preorder) của cây nhị phân tìm kiếm. Nhiệm vụ của bạn là đưa ra phép duyệt theo thứ tự sau của cây nhị phân tìm kiếm.

            Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N là số lượng node; dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống.
T, N, node thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤A[i]≤104;
Output:

Đưa ra kết quả phép duyệt Postorder theo từng dòng.
     Ví dụ:



Input
2
5
40 30 35 80 100
8
40 30 32 35 80 90 100 120

Output
35 30 100 80 40
35 32 30 120 100 90 80 40
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

void Postorder(node*& root) {
    if (root) {
        Postorder(root->le);
        Postorder(root->ri);
        cout << root->data << " ";
    }
}

void solution() {
    int n;
    cin >> n;
    node* root = NULL;
    for (int i = 0, u; i < n; i++) {
        cin >> u;
        add_node(root, u);
    }
    Postorder(root);
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