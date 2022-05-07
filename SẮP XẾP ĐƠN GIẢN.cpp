/*
Cho một dãy số a[] có n phần tử gồm các số từ 1 đến n theo 1 thứ tự ngẫu nhiên. Nhiệm vụ của bạn là sắp xếp lại dãy số này theo thứ tự tăng dần với điều kiện : ở mỗi bước sắp xếp, bạn chỉ được chọn 1 số ở 1 vị trí bất kì và chuyển số đó lên đầu dãy hoặc về cuối dãy.

Hãy tính số bước tối thiểu cần thực hiện để hoàn thành việc sắp xếp.

Input

Dòng đầu tiên ghi 1 số n: số lượng phần tử của dãy a (1 ≤ n ≤ 100000)
Dòng tiếp theo gồm n số từ 1 đến n theo thứ tự ngẫu nhiên
Output

Một số nguyên duy nhất là số bước tối thiểu cần thực hiện để hoàn thành việc sắp xếp.
Ví dụ

Input

Output

5

4 1 2 5 3

2
*/
// Tìm dãy tăng thoả mãn liên tiếp và dài nhất lấy trừ đi
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define pi pair <int,int>
#define matrix vector <vt>
#define matrixl vector <vtl>
const int MOD = 1e9 + 7;

void solution() {
    int n;
    cin >> n;
    vector <pi> v(n);
    for (auto i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    int ans = 0, cnt = 1;
    for (int i = 0; i < n - 1; i++) {
        if (v[i].second < v[i + 1].second) {
            cnt++;
            ans = max(ans, cnt);
        }
        else cnt = 1;
    }
    cout << n - ans;
}

int main() {
    faster();
    solution();
    return 0;
}