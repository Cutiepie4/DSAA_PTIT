/*
Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một và một số K < N.

Hãy liệt kê tất cả các dãy con khác nhau có K phần tử của A[], mỗi dãy đều được sắp xếp theo thứ tự tăng dần.

Các dãy con được liệt kê lần lượt theo thứ tự từ điển.

Input

Dòng đầu ghi số bộ test, mỗi test có 2 dòng:

Dòng đầu ghi hai số N và K (2 < K < N <15)
Dòng thứ 2 ghi N số của dãy A[], các số đều nguyên dương, nhỏ hơn 100 và khác nhau từng đôi một.
Output
Với mỗi test, liệt kê tất cả các dãy con thỏa mãn, mỗi dãy con trên một dòng. 
Ví dụ
Input
1
4 3
3 2 5 4
OUTPUT:
2 3 4
2 3 5
2 4 5
3 4 5
*/
#include <bits/stdc++.h>
using namespace std;

int cmp(vector <int> a, vector <int> b) {
    if (a < b) return 1;
    return 0;
}

vector <vector <int>> Data;

void process(vector <int>& v, vector <int> tmp1, int index, int k) {
    if (k == 0) return;
    for (int i = index; i >= 0; i--) {
        vector <int> tmp = tmp1;
        tmp.push_back(v[i]);
        if (k == 1) Data.push_back(tmp);
        process(v, tmp, i - 1, k - 1);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Data.clear();
        int n, k;
        cin >> n >> k;
        vector <int> v(n);
        for (auto& i : v) cin >> i;
        sort(v.begin(), v.end(), greater<int>());
        for (int i = 0; i < v.size(); i++) {
            vector <int> tmp;
            tmp.push_back(v[i]);
            if (k == 1) {
                Data.push_back(tmp);
                continue;
            }
            process(v, tmp, i - 1, k - 1);
        }
        sort(Data.begin(), Data.end(), cmp);
        for (int i = 0; i < Data.size(); i++) {
            for (auto j : Data[i]) cout << j << " ";
            cout << endl;
        }
    }
}