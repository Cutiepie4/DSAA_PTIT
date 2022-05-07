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

vector <deque <node*>> Level(1000);

void Level_order(node*& root) {
    queue <pair <node*, int>> Q;
    Q.push({ root, 0 });

    while (!Q.empty()) {
        node* X = Q.front().first;
        int lv = Q.front().second;
        Q.pop();

        Level[lv].push_back(X);
        if (X->le != NULL) Q.push({ X->le, lv + 1 });
        if (X->ri != NULL) Q.push({ X->ri, lv + 1 });
    }
}

void Spiral_order(int lv, int ok) {
    while (!Level[lv].empty()) {
        ok = 1;
        cout << Level[lv].front()->data << " ";
        Level[lv].pop_front();
        lv++;
    }
    lv--;
    while (!Level[lv].empty()) {
        ok = 1;
        cout << Level[lv].front()->data << " ";
        Level[lv].pop_front();
    }
    lv--;
    while (!Level[lv].empty()) {
        ok = 1;
        cout << Level[lv].back()->data << " ";
        Level[lv].pop_back();
        lv--;
    }
    if (ok == 0) return;
    Spiral_order(lv + 1, 0);
}

void solution() {
    int n;
    cin >> n;
    node* root;
    add_node(root, n);
    Level_order(root);
    Spiral_order(0, 0);
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