#include <bits/stdc++.h>
using namespace std;

vector <string> res;
unordered_map <int, char> mp;

void next_com(vector <int>& v, int k, int n) {
    string tmp;
    for (int i = 1; i <= k; i++) tmp.push_back(mp[v[i]]);
    res.push_back(tmp);
    int i, kt = 1;
    // tìm i lớn nhất sao cho a[i] < n - k + i, tức là tìm a[i] mà chưa đạt cấu hình max đầu tiên từ dưới lên
    for (i = k; i > 0; i--) {
        if (v[i] < n - k + i) {
            v[i]++;
            for (int j = i + 1; j <= k; j++) {
                v[j] = v[i] + j - i;
            }
            next_com(v, k, n);
        }
    }
    return;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        mp.clear();
        res.clear();
        cin >> n >> s;
        sort(s.begin(), s.end());
        vector <int> v(n + 1);
        for (int i = 0; i < s.size(); i++) {
            mp.insert({ i + 1, s[i] });
            v[i + 1] = i + 1;
        }
        for (int i = 1; i <= n; i++) {
            vector <int> tmp;
            tmp.push_back(0);
            for (int j = 1; j <= i; j++) tmp.push_back(v[j]);
            next_com(tmp, i, n);
        }
        sort(res.begin(), res.end());
        for (auto i : res) cout << i << " ";
        cout << endl;
    }
}
