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
    }
    if (root->le) add_node(root->le, u, v, c);
    if (root->ri) add_node(root->ri, u, v, c);
}

void Levelorder(node*& root) {
    vector <string> S(1000, "");
    queue <pair <node*, int>> Q;
    int Max = 0;
    Q.push({ root, 0 });
    while (Q.size()) {
        node* curr = Q.front().first;
        int lv = Q.front().second;
        Max = max(Max, lv);
        Q.pop();

        S[lv] = S[lv] + to_string(curr->data) + " ";
        if (curr->le) Q.push({ curr->le, lv + 1 });
        if (curr->ri) Q.push({ curr->ri, lv + 1 });
    }
    for (int i = Max; i >= 0; i--) {
        cout << S[i];
    }
}

void solution() {
    int n;
    cin >> n;
    node* root = NULL;
    while (n--) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        add_node(root, u, v, c);
    }
    Levelorder(root);
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