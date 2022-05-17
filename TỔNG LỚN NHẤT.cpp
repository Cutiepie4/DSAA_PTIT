/*
Cho cây nhị phân có giá trị mỗi node là một số, nhiệm vụ của bạn là tìm tổng lớn nhất từ một node lá này sang một node lá khác? Ví dụ với cây dưới đây ta có tổng lớn nhất là 27.



     Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được viết cách nhau một vài khoảng trống.
T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
Output:

Đưa ra kết quả mỗi test theo từng dòng.
      Ví dụ:

Input
1
12
-15 5 L -15 6 R 5 -8 L 5 1 R -8 2 L -8 -3 R 6 3 L 6 9 R 9 0 R 0 4 L 0 -1 R -1 10 L

Output
27
*/
#include <bits/stdc++.h>
using namespace std;

int ans;

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

int Postorder(node*& root) {
    if (!root->le && !root->ri) return root->data;

    int le = 0, ri = 0;
    if (root->le && !root->ri) {
        le = Postorder(root->le);
        ans = max(ans, le + root->data);
        return le + root->data;
    }
    else if (!root->le && root->ri) {
        ri = Postorder(root->ri);
        ans = max(ans, ri + root->data);
        return ri + root->data;
    }
    else {
        le = Postorder(root->le);
        ri = Postorder(root->ri);
        ans = max(ans, le + ri + root->data);
        return max(le + root->data, ri + root->data);
    }
}

void solution() {
    ans = INT32_MIN;
    int n;
    cin >> n;
    node* root = NULL;
    while (n--) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        add_node(root, u, v, c);
    }
    Postorder(root);
    cout << ans;
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