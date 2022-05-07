/*
Số Ugly là các số chỉ có ước số là 2, 3, 5. Theo qui ước số 1 cũng là 1 số Ugly. Dưới đây là 11 số Ugly đầu tiên: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15. Cho số tự nhiên N, nhiệm vụ của bạn là tìm số Ugly thứ N.

Input:  Dòng đầu tiên đưa vào số lượng bộ test T.  Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng. T, N thỏa mãn ràng buộc: 1 ≤ T ≤ 100;  1 ≤ N ≤ 104.

Output: Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:
Input
2
10
4

Output
12
4
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector <ll> Data;

void init(int Max) {
    Data = vector <ll>(Max, 1);
    vector <ll> v(3, 0);
    ll next, next2 = 2, next3 = 3, next5 = 5;

    for (int i = 1; i < Max; i++) {
        next = min(next2, min(next3, next5));
        Data[i] = next;
        if (next2 == next) {
            v[0]++;
            next2 = Data[v[0]] * 2;
        }
        if (next3 == next) {
            v[1]++;
            next3 = Data[v[1]] * 3;
        }
        if (next5 == next) {
            v[2]++;
            next5 = Data[v[2]] * 5;
        }
    }
}

int main() {
    int t, Max = 0;
    cin >> t;
    vector <int> v(t);
    for (auto& i : v) {
        cin >> i;
        Max = max(Max, i);
    }
    init(Max);
    for (auto i : v) {
        cout << Data[i - 1] << endl;
    }
}