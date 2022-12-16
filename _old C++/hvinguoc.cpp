#include <bits/stdc++.h>
using namespace std;

void next_per(vector <pair <int, int>>& v) {
    for (auto i : v) cout << i.first;
    cout << " ";
    int i, j, kt = 1;
    // tìm i lớn nhất mà a[i] < a[i+1]
    for (i = v.size() - 2; i >= 0; i--) {
        if (v[i].second < v[i + 1].second) {
            kt = 0;
            break;
        }
    }
    // ko thấy thì đó là cấu hình cuối cùng
    if (kt) return;
    // tìm j lớn nhất từ i+1 trở đi mà a[j] > a[i], swap chúng
    for (j = v.size() - 1; j > i; j--) {
        if (v[j].second > v[i].second) {
            swap(v[j], v[i]);
            break;
        }
    }
    // lật ngược lại từ i+1 trở đi, là được cấu hình kế tiếp
    reverse(v.begin() + i + 1, v.end());
    next_per(v);z
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x = 1;
        cin >> n;
        vector <pair<int, int>> v(n);
        for (auto& i : v) {
            i.second = x++;
            i.first = n + 1 - i.second;
        }
        next_per(v);
        cout << endl;
    }
}