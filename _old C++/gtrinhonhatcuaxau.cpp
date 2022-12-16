#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int cmp(pair <ll, char>& a, pair<ll, char>& b) {
    if (a.first >= b.first) return 1;
    return 0;
}

ll cal(vector <pair <ll, char>>& v) {
    long long res = 0;
    for (auto i : v) res += i.first * i.first;
    return res;
}

ll process(vector <pair <ll, char>>& v, ll& k) {
    if (k == 0) return cal(v);
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i].first > v[i + 1].first) {
            if (k > v[i].first - v[i + 1].first) {
                for (int j = i; j >= 0; j--) {
                    if (k > v[j].first - v[i + 1].first) {
                        k -= v[j].first - v[i + 1].first;
                        v[j].first = v[i + 1].first;
                    }
                    else {
                        v[j].first -= k;
                        k = 0;
                        return cal(v);
                    }
                }
            }
            else {
                v[i].first -= k;
                return cal(v);
            }
        }
    }
    int x = k / v.size();
    if (x > v.front().first) return 0;
    for (auto& i : v) i.first -= x;
    k %= v.size();
    for (int i = 0; i < k; i++) v[i].first--;
    return cal(v);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll k;
        string s;
        cin >> k >> s;
        vector <pair <ll, char>> v;
        for (auto i : s) {
            int kt = 1;
            for (int j = 0; j < v.size(); j++) {
                if (v[j].second == i) {
                    v[j].first++;
                    kt = 0; break;
                }
            }
            if (kt) v.push_back({ 1, i });
        }
        sort(v.begin(), v.end(), cmp);
        cout << process(v, k) << endl;
    }
}