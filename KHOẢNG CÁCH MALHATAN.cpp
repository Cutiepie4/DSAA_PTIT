/*
Trong mặt phẳng tọa độ, khoảng cách Manhattan giữa 2 điểm A, B được định nghĩa là

d(A,B) = |xA – xB| + |yA – yB|

 

Cho hai tập điểm S1 và S2 trong đó:

S1 chứa tập điểm phân biệt nằm trên đường y = c1
S2 chứa tập điểm phân biệt nằm trên đường y = c2
Hãy tính khoảng cách Manhattan ngắn nhất giữa hai điểm p Î S1 và q Î S2 và đếm xem có bao nhiêu cặp điểm phân biệt có khoảng cách bằng khoảng cách ngắn nhất.

 

Input

Dòng đầu tiên ghi hai số N, M (1 ≤ N,M ≤ 5000000) trong đó N là số phần tử trong S1, M là số phần tử trong S2
Dòng thứ 2 ghi hai số c1 và c2 (- 108 ≤ c1,c2 ≤ 108).
Dòng thứ 3 ghi N số của tập S1 (các số có trị tuyệt đối không quá 108)
Dòng thứ 4 ghi M số của tập S2 (các số có trị tuyệt đối không quá 108)
Output

Ghi ra trên một dòng hai số nguyên lần lượt là khoảng cách ngắn nhất và số cặp điểm có khoảng cách ngắn nhất.
Ví dụ
Input
3 4
1 -3
3 0 6
-2 5 4 2
OUTPUT:
5 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ll n, m, c1, c2, cnt = 1;
    cin >> n >> m >> c1 >> c2;
    map <ll, ll> mp;
    c1 = abs(c1 - c2);
    vector <ll> vn(n), vm(m);
    for (auto& i : vn) cin >> i;
    for (auto& i : vm) cin >> i;
    sort(vn.begin(), vn.end());
    sort(vm.begin(), vm.end());
    vector <ll> ::iterator itn, itm;
    itn = vn.begin();
    itm = vm.begin();
    ll dist = INT64_MAX;
    for (itn; itn != vn.end(); itn++) {
        itm = lower_bound(itm, vm.end(), *itn);
        if (itm == vm.end()) advance(itm, -1);
        ll tmp = abs(*itm - *itn);
        if (dist >= tmp) {
            if (dist == tmp) {
                mp.insert({ *itn, *itm });
            }
            else {
                dist = tmp;
                mp.clear();
                mp.insert({ *itn, *itm });
            }
        }
        if (itm != vm.begin()) advance(itm, -1);
        tmp = abs(*itm - *itn);
        if (dist >= tmp) {
            if (dist == tmp) {
                mp.insert({ *itn, *itm });
            }
            else {
                dist = tmp;
                mp.clear();
                mp.insert({ *itn, *itm });
            }
        }
    }
    cout << (long long)dist + c1 << " " << mp.size();
}