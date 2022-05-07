/*
Cho dãy số A[] có N phần tử là các chữ số từ 0 đến 9. Nhiệm vụ của bạn là hãy chọn lấy một tổ hợp các phần tử và sắp xếp chúng sao cho thu được số lớn nhất chia hết cho 3.

Nếu không tìm được số nào, in ra -1.

Input:

Dòng đầu tiên là số lượng bộ test T (1 <= N <= 50).

Mỗi test bắt đầu bởi số nguyên N (1 <= N <= 100 000).

Dòng tiếp theo gồm N số nguyên A[i] (0 <= A[i] <= 9).

Output: 

Với mỗi test, in ra đáp án tìm được trên một dòng.

Test ví dụ:

Input
3
3
8 1 9
5
8 1 7 6 0
2
5 2

OUTPUT
981
8760
-1
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, tmp, sum = 0;
        cin >> n;
        map <int, vector <int>> mp;
        for (int i = 0; i < 3; i++) mp.insert({ i, vector <int>(0) });
        vector <int> v;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            mp[tmp % 3].push_back(tmp);
            if (tmp % 3 != 0) sum += tmp;
        }
        for (int i = 0; i < 3; i++)
            sort(mp[i].begin(), mp[i].end(), greater <int>());

        if (sum % 3 != 0) {
            if (sum % 3 == 1) {
                if (!mp[1].empty()) mp[1].pop_back();
                else {
                    mp[2].pop_back();
                    mp[2].pop_back();
                }
            }
            if (sum % 3 == 2) {
                if (!mp[2].empty()) mp[2].pop_back();
                else {
                    mp[1].pop_back();
                    mp[1].pop_back();
                }
            }
        }

        if (!v.empty() || !mp[0].empty()) {
            for (int j = 0; j < 3; j++) {
                for (int i = 0; i < mp[j].size(); i++)
                    v.push_back(mp[j][i]);
            }
            sort(v.begin(), v.end(), greater <int>());
            for (auto i : v) cout << i;
            cout << endl;
        }
        else cout << "-1" << endl;
    }
}