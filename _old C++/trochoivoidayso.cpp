/*
Cho trước n số nguyên không âm a1, a2, …, an.
Mỗi lần lặp, bạn thay đổi dãy này thành một dãy mới theo cách: phần
tử thứ k trong dãy mới bằng trị tuyệt đối của ak -  ak+1.
Phần tử cuối cùng sẽ là an – a1.
Quá trình lặp sẽ dừng lại khi được một dãy bằng nhau.
*/
#include <bits/stdc++.h>
using namespace std;
int check(long long a[], int n) {
    for (int i = 0; i < n - 1; i++) if (a[i] != a[i + 1]) return 0;
    return 1;
}
int main() {
    int t = 1;
    while (1) {
        int n;
        cin >> n;
        int kt = 0;
        if (n == 0) break;
        long long a[n] = {}, res = 0;
        for (int i = 0; i < n; i++) cin >> a[i];
        if (check(a, n)) {
            cout << "Case " << t << ": 0 iterations" << endl; t++; continue;
        }
        while (1) {
            long long x = a[0];
            for (int i = 0; i < n - 1; i++) {
                a[i] = abs(a[i] - a[i + 1]);
            }
            a[n - 1] = abs(a[n - 1] - x);
            res++;
            if (check(a, n)) break;
            if (res >= 1000) {
                cout << "Case " << t << ": " << "not attained" << endl; kt = 1; break;
            }
        }
        if (kt == 0) cout << "Case " << t << ": " << res << " iterations" << endl;
        t++;
    }
}