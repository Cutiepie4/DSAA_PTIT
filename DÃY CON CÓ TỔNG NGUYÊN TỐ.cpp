/*
Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một. Hãy sắp xếp dãy theo thứ tự giảm dần, sau đó liệt kê tất cả các dãy con của A[] có tổng các phần tử là số nguyên tố.

Input

Dòng đầu ghi số bộ test, mỗi test có 2 dòng:

Dòng đầu ghi số N (2 < N <15)
Dòng thứ 2 ghi N số của dãy A[], các số đều nguyên dương, nhỏ hơn 100 và khác nhau từng đôi một.
Output
Với mỗi test, liệt kê tất cả các dãy con có tổng các phần tử là số nguyên tố theo, mỗi dãy con trên một dòng. 
Ví dụ
Input
1
4
3 2 5 4

OUTPUT:
2
3
3 2
4 3
5
5 2
5 4 2
*/
#include <bits/stdc++.h>
using namespace std;

int cmp(vector <int>& a, vector <int>& b) {
    if (a < b) return 1;
    return 0;
}

vector <int> check(1501, 1);
vector <vector <int>> Data;

void eratos() {
    check[0] = check[1] = 0;
    for (int i = 2; i * i <= 1500; i++) {
        if (check[i]) {
            for (int j = i * i; j <= 1500; j += i) {
                check[j] = 0;
            }
        }
    }
}

void process(vector <int>& v, vector <int> tmp1, int index, int n, int sum1) {
    for (int i = index; i >= 0; i--) {
        int sum = sum1;
        sum += v[i];
        vector <int> tmp = tmp1;
        tmp.push_back(v[i]);
        if (check[sum]) {
            Data.push_back(tmp);
        }
        if (n == 1) return;
        process(v, tmp, i - 1, n - 1, sum);
    }
}

int main() {
    int t;
    cin >> t;
    eratos();
    while (t--) {
        Data.clear();
        int n, ans = 0;
        cin >> n;
        vector <int> v(n);
        for (auto& i : v) cin >> i;
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            vector <int> tmp;
            int sum = v[i];
            tmp.push_back(v[i]);
            if (check[v[i]]) Data.push_back(tmp);
            process(v, tmp, i - 1, n - 1, sum);
        }

        sort(Data.begin(), Data.end(), cmp);
        for (int i = 0; i < Data.size(); i++) {
            for (auto j : Data[i]) cout << j << " ";
            cout << endl;
        }
    }
}