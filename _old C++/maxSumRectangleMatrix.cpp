// /*
// Ta tính tất cả các đoạn con của từng row, lấy các đoạn con giống nhau
// của từng row đưa vào 1 vector rồi tìm max sum contigious array.
// Đó tính là kq cần tìm
// */

// #include <bits/stdc++.h>
// using namespace std;

// int findmax(vector <int> v) {
//     int res = v[0];
//     for (int i = 1; i < v.size(); i++) {
//         if (v[i - 1] > 0) v[i] += v[i - 1];
//     }
//     return *max_element(v.begin(), v.end());
// }

// int process(vector <vector <int>> v, int r, int c) {
//     int ans = INT32_MIN;
//     vector <int> sum_row;
//     for (int i = 0; i < c; i++) {
//         for (int z = 0; z < r; z++) {
//             sum_row.push_back(0);
//             for (int k = 0; k <= i; k++) {
//                 sum_row.back() += v[z][k];
//             }
//         }
//         ans = max(findmax(sum_row), ans);
//         for (int j = 1; j < c - i; j++) {
//             for (int z = 0; z < r; z++) {
//                 sum_row[z] -= v[z][j-1];
//                 sum_row[z] += v[z][j+i];
//             }
//             ans = max(findmax(sum_row), ans);
//         }
//         sum_row.clear();
//     }
//     return ans;
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int r, c;
//         cin >> r >> c;
//         vector <vector <int>> v(r, vector <int>(c, 0));
//         for (int i = 0; i < r; i++)
//             for (int j = 0; j < c; j++)
//                 cin >> v[i][j];
//         cout << process(v, r, c) << endl;
//     }
// }

#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n][m];
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                cin >> a[i][j];
            }
        }
        int res = INT_MIN;
        for (int i = 0;i < m;i++) {
            vector<int>sum(n, 0);
            for (int j = i;j < m;j++) {
                int m = 0;
                for (int k = 0;k < n;k++) {
                    sum[k] += a[k][j];
                    m = max(sum[k], sum[k] + m);
                    res = max(res, m);
                }
            }
        }
        cout << res << endl;
    }
}