#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ll n, m, c1, c2, cnt = 1;
    cin >> n >> m >> c1 >> c2;
    map <ll, ll> mp;
    c1 = abs(c1 - c2);
    vector <ll> vn(n), vm(m);
    for (auto& i : vn) cin >> i;
    for (auto& i : vm) cin >> i;
    sort(vn.begin(), vn.end());
    sort(vm.begin(), vm.end());
    vector <ll> ::iterator itn, itm;
    itn = vn.begin();
    itm = vm.begin();
    ll dist = INT64_MAX;
    for (itn; itn != vn.end(); itn++) {
        itm = lower_bound(itm, vm.end(), *itn);
        if (itm == vm.end()) advance(itm, -1);
        ll tmp = abs(*itm - *itn);
        if (dist >= tmp) {
            if (dist == tmp) {
                mp.insert({ *itn, *itm });
            }
            else {
                dist = tmp;
                mp.clear();
                mp.insert({ *itn, *itm });
            }
        }
        if (itm != vm.begin()) advance(itm, -1);
        tmp = abs(*itm - *itn);
        if (dist >= tmp) {
            if (dist == tmp) {
                mp.insert({ *itn, *itm });
            }
            else {
                dist = tmp;
                mp.clear();
                mp.insert({ *itn, *itm });
            }
        }
    }
    cout << (long long)dist + c1 << " " << mp.size();
}