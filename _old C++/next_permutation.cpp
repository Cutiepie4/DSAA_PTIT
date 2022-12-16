#include <bits/stdc++.h>
using namespace std;

void next_per(vector <int>& v) {
    for (auto i : v) cout << i << " ";
    cout << endl;
    int i, j, kt = 1;
    // tìm i lớn nhất mà a[i] < a[i+1]
    for (i = v.size() - 1; i >= 0; i--) {
        if (v[i] < v[i + 1]) {
            kt = 0;
            break;
        }
    }
    // ko thấy thì đó là cấu hình cuối cùng
    if (kt) return;
    // tìm j lớn nhất từ i+1 trở đi mà a[j] > a[i], swap chúng
    for (j = v.size() - 1; j > i; j--) {
        if (v[j] > v[i]) {
            swap(v[j], v[i]);
            break;
        }
    }
    // lật ngược lại từ i+1 trở đi, là được cấu hình kế tiếp
    reverse(v.begin() + i + 1, v.end());
    next_per(v);
}

int main() {
    int n;
    cin >> n;
    vector <int> v(n);
    for (auto& i : v) cin >> i;
    next_per(v);
}