#include <bits/stdc++.h>
using namespace std;

vector <int> In, Pre;

/*
Cho duyệt Inorder + Preorder -> tìm Postorder
Inorder    : 4  2  5  1  3  6
Preorder   : 1  2  4  5  3  6
Postorder  : 4  5  2  6  3  1
*/

int search_(int x, int l, int r) {
    for (int i = l; i <= r; i++) if (In[i] == x) return i;
    return -1;
}

void Postorder(int l, int r, int& idx) {
    if (l == r) {
        cout << In[l] << " ";
        return;
    }
    else {
        int x = search_(Pre[idx], l, r);
        if (x - 1 >= l) Postorder(l, x - 1, ++idx);
        if (x + 1 <= r) Postorder(x + 1, r, ++idx);
        cout << In[x] << " ";
    }
}

void solution() {
    int n;
    cin >> n;
    In = vector <int>(n);
    Pre = In;
    for (auto& i : In) cin >> i;
    for (auto& i : Pre) cin >> i;
    int idx = 0;
    Postorder(0, n - 1, idx);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}