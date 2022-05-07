/*
cho độ cao và vị trí của nhiều bức tường
nước đổ xuống từ vị trí 0, tìm vị trí cuối cùng mà nước chảy qua tường
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct wall {
    int h, pos;
    ll V;
};

int n;
ll K;
vector <wall> W;

int bin_search(vector <wall> W, ll x) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (W[mid].V < x) {
            l = mid + 1;
        }
        else r = mid;
    }
    return W[l - 1].pos;
}

void init() {
    stack <wall> st;
    wall F;
    F.pos = 0, F.h = 1e9, F.V = 0;
    st.push(F);
    for (auto& i : W) {
        while (st.top().h < i.h) st.pop();
        i.V = (ll)(i.pos - st.top().pos) * i.h + st.top().V;
        st.push(i);
    }
    // for (int i = 0; i < W.size(); i++) {
    //     cout << W[i].V << " ";
    // }
    // cout << endl;
}

void Ans() {
    int Q;
    cin >> Q;
    while (Q--) {
        cin >> K;
        cout << bin_search(W, K) << endl;
    }
}

void solution() {
    cin >> n;
    W = vector <wall>(n);
    for (auto& i : W) cin >> i.pos;
    for (auto& i : W) cin >> i.h;
    init();
    Ans();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}