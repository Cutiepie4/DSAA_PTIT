#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* le;
    node* ri;
    node(int x) {
        data = x;
        le = ri = NULL;
    }
};

void add_node(node*& root, int n) {
    int u, v;
    char c;
    map <int, node*> m;
    while (n--) {
        cin >> u >> v >> c;
        if (m.find(u) == m.end()) {
            root = new node(u);
            if (c == 'L') {
                root->le = new node(v);
                m[v] = root->le;
            }
            else {
                root->ri = new node(v);
                m[v] = root->ri;
            }
            m[u] = root;
        }
        else {
            if (c == 'L') {
                m[u]->le = new node(v);
                m[v] = m[u]->le;
            }
            else {
                m[u]->ri = new node(v);
                m[v] = m[u]->ri;
            }
        }
    }
}

void ziczac_order(node*& root) {
    stack <node*> st1, st2;
    st1.push(root);

    while (st1.size() || st2.size()) {
        while (st1.size()) {
            node* X = st1.top();
            st1.pop();
            cout << X->data << " ";

            if (X->ri != NULL) st2.push(X->ri);
            if (X->le != NULL) st2.push(X->le);
        }

        while (st2.size()) {
            node* X = st2.top();
            st2.pop();
            cout << X->data << " ";

            if (X->le != NULL) st1.push(X->le);
            if (X->ri != NULL) st1.push(X->ri);
        }
    }
}

void solution() {
    int n;
    cin >> n;
    node* root;
    add_node(root, n);
    ziczac_order(root);
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