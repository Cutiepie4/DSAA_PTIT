/*
Cho cây nhị phân, nhiệm vụ của bạn là dịch chuyển cây nhị phân thành cây nhị phân tìm kiếm. Phép dịch chuyển phải bảo toàn được cấu trúc cây nhị phân ban đầu. Ví dụ dưới đây sẽ minh họa phép dịch chuyển:

    Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được viết cách nhau một vài khoảng trống.
T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
Output:

Đưa ra kết quả mỗi test theo từng dòng là phép duyệt Inorder của cây tìm kiếm.
     Ví dụ:

Input
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output
1 2 3
10 20 30 40 60
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

void add_node(node*& root, int u, int v, char c) {
    if (!root) root = new node(u);
    if (root->data == u) {
        if (c == 'L') root->le = new node(v);
        else root->ri = new node(v);
        return;
    }
    if (root->le) add_node(root->le, u, v, c);
    if (root->ri) add_node(root->ri, u, v, c);
}

void Inorder(node*& root, set <int>::iterator& it) {
    if (root) {
        Inorder(root->le, it);
        cout << *it << " ";
        advance(it, 1);
        Inorder(root->ri, it);
    }
}

void solution() {
    int n;
    cin >> n;
    set <int> S;
    node* root = NULL;
    for (int i = 0, u, v; i < n; i++) {
        char c;
        cin >> u >> v >> c;
        S.insert(u);
        S.insert(v);
        add_node(root, u, v, c);
    }
    auto it = S.begin();
    Inorder(root, it);
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