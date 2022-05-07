#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map <int, int> Map;
    map <int, int> ::iterator it;
    set <int> ss;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        Map[a]++;
        if (Map[a] == 1) ss.insert(a);
        while (Map[*ss.begin()] > 1) ss.erase(ss.begin());
        if (!ss.empty()) cout << *ss.begin() << endl;
        else cout << -1 << endl;
    }
}