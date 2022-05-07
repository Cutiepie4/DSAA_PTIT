/*
Cho mảng A[]  gồm n phần tử. Nhiệm vụ của bạn là tìm phần tử gần nhất phía bên phải có số lần xuất hiện lớn hơn phần tử hiện tại. Nếu không có phần tử nào có số lần xuất hiện lớn hơn phần tử hiện tại hãy đưa ra -1.

Ví dụ với dãy A[] = {1, 1, 2, 3, 4, 2, 1 }, ta nhận được kết quả ans[] = {-1, -1, 1, 2, 2, 1, -1} vì số lần xuất hiện mỗi phần tử trong mảng là F = {3, 3, 2, 1, 1, 2, 3} vì vậy phần tử A[0] = 1 có số lần xuất hiện là 3 và không có phần tử nào xuất hiện nhiều hơn 3 nên ans[0] = -1, tương tự như vậy với A[2]=2 tồn tại A[6] =1 có số lần xuất hiện là 3 nên ans[2] = 1.



Input:

Dòng đầu tiên đưa vào số lượng bộ test T;
Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test gồm hai dòng, dòng đầu tiên đưa vào số n là số các phần tử của mảng A[]; dòng tiếp theo đưa vào n số của mảng A[]; các phần tử được viết cách nhau một vài khoảng trống.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ràng buộc:

T, n, A[i] thỏa mãn ràng buộc: 1≤T≤100; 0≤n, A[i]≤106.
Ví dụ:

Input

Output

1

7

1  1  2  3  4  2  1

-1 -1 1 2 2 1 -1
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        vector <int> Map(1e6, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            Map[a[i]]++;
        }
        vector <pair <int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({ Map[a[i]], a[i] });
        }
        deque <int> ans;
        stack <pair <int, int>> st;
        for (int i = v.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first <= v[i].first) st.pop();
            if (st.empty()) {
                ans.push_front(-1);
            }
            else ans.push_front(st.top().second);
            st.push({ v[i].first, v[i].second });
        }
        for (auto i : ans) cout << i << " ";
        cout << endl;
    }
}