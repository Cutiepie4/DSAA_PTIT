/*
Hãy xây dựng một cây nhị phân tìm kiếm cân bằng từ dãy số A[] =(a0, a1, .., an-1}. Đưa ra phép duyệt theo thứ tự sau (post-order) của cây tìm kiếm cân bằng.  Ví dụ với dãy A[]={40, 28, 45, 38, 33, 15, 25, 20, 23, 35, 30} ta sẽ có phép duyệt theo thứ tự trước của cây nhị phân tìm kiếm cân bng với node gốc là 33 : 15, 23, 20, 30, 28, 25, 35, 38, 45, 40, 33.  

Input:

Dòng đầu tiên đưa vào số lượng bộ test T (T≤100).
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất là số tự nhiên N (N≤106). Dòng tiếp theo là N số của mảng A[].
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input:
2
11
40  28  45 38  33  15  25  20  23  35  30
10
1  2  3  4  5  6  7  8  9  10

Output
20 15 28 25 23 35 33 45 40 38 30
1 4 3 2 7 6 10 9 8 5
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

int n;
vector <int> v;

void build_tree(int l, int r, node*& root) {
    if (l == r) {
        root = new node(v[l]);
        return;
    }
    int mid = (l + r) / 2;
    root = new node(v[mid]);
    if (l <= mid - 1) build_tree(l, mid - 1, root->le);
    if (r >= mid + 1) build_tree(mid + 1, r, root->ri);
}

void Postorder(node*& root) {
    if (root) {
        Postorder(root->le);
        Postorder(root->ri);
        cout << root->data << " ";
    }
}

void solution() {
    node* root = NULL;
    cin >> n;
    v = vector <int>(n);
    for (auto& i : v) cin >> i;
    sort(v.begin(), v.end());
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