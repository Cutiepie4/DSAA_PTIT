// vét cạn giống sàng erathones
// số có tổng ước lớn hơn nó
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int l, r, res = 0;

void process() {
    vector <int> a(r + 1, 1);
    for (int i = 2; i <= r / 2; i++)
        for (int j = 2; j <= r / i; j++)
            a[i * j] += i;
    for (int i = l; i <= r; i++)
        if (a[i] > i) res++;
}

int main() {
    cin >> l >> r;
    process();
    cout << res;
    return 0;
}