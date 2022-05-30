/*
Cho hai mảng là phép duyệt Inorder và Level-order, nhiệm vụ của bạn là xây dựng cây nhị phân và đưa ra kết quả phép duyệt Postorder. Level-order là phép duyệt theo từng mức của cây. Ví dụ như cây dưới đây ta có phép Inorder và Level-order như dưới đây:

Inorder : 4  8  10  12 14 20 22

Level order: 20  8  22  4  12  10  14



      Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng đầu tiên đưa vào số N là số lượng node; dòng tiếp theo đưa vào N số là phép duyệt Inorder; dòng cuối cùng đưa vào N số là phép duyệt Level-order; các số được viết cách nhau một vài khoảng trống.
T, N, node thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤A[i]≤104;
Output:

Đưa ra kết quả phép duyệt Postorder theo từng dòng.
     Ví dụ:

Input
2
3
1 0 2
0 1 2
7
3 1 4 0 5 2 6
0 1 2 3 4 5 6

Output
1 2 0
3 4 1 5 6 2 0
*/
#include <bits/stdc++.h>
using namespace std;
#define vt vector <int>

struct node {
    int data;
    node* le, * ri;
    node(int x) {
        data = x;
        le = ri = NULL;
    }
};

int n;
vt Le, In, pos;

void build_tree(int l, int r, node*& root) {
    int lv_min = l;
    for (int i = l; i <= r; i++) {
        if (pos[In[i]] < pos[In[lv_min]]) lv_min = i;
    }
    if (!root) root = new node(In[lv_min]);
    if (l <= lv_min - 1) build_tree(l, lv_min - 1, root->le);
    if (lv_min + 1 <= r) build_tree(lv_min + 1, r, root->ri);
}

void Postorder(node*& root) {
    if (root) {
        Postorder(root->le);
        Postorder(root->ri);
        cout << root->data << " ";
    }
}

void solution() {
    cin >> n;
    Le = vt(n), In = Le, pos = vt(1e4, -1);
    for (auto& i : In) cin >> i;
    for (int i = 0; i < n;i++) {
        cin >> Le[i];
        pos[Le[i]] = i;
    }
    node* root = NULL;
    build_tree(0, n - 1, root);
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

