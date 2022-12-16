/*
John có một đàn bò. Một ngày đẹp trời, anh ta quyết định mua xe tải với khả năng chở được C kg (1000 ≤ C ≤ 25000) để đưa những con bò đi xem phim. Cho số con bò là N (20 ≤ N ≤ 00) và khối lượng w[i] của từng con (đều nhỏ hơn C), 
hãy cho biết khối lượng bò lớn nhất mà John có thể đưa đi xem phim là bao nhiêu.
*/
#include <bits/stdc++.h>
using namespace std;

void TestCase() {
    int c, n, w;
    cin >> c >> n;

    vector<int> f(c + 1, 0);
    f[0] = 1;

    for (int i = 1; i <= n; ++i) {
        cin >> w;
        for (int j = c; j >= w; --j) {
            if (f[j] == 0 && f[j - w] == 1)
                f[j] = 1;
        }
    }

    for (int i = c; i >= 0; --i) {
        if (f[i] == 1) {
            cout << i;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 1;
    while (T--) {
        TestCase();
        cout << endl;
    }
    return 0;
}