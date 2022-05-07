/*
Cho mảng A[] gồm n phần tử. Hãy đưa ra các phần tử nhỏ hơn tiếp theo của phần tử lớn hơn đầu tiên phần tử hiện tại. Nếu phần tử hiện tại không có phần tử lớn hơn tiếp theo ta xem là -1. Nếu phần tử không có phần tử nhỏ hơn tiếp theo ta cũng xem là -1. Ví dụ với mảng A[] = {5, 1, 9, 2, 5, 1, 7} ta có kết quả là ans = {2, 2, -1, 1, -1, -1, -1} vì:

Next Greater                         Right Smaller

5          ->  9                        9  ->  2

1          ->  9                      9  ->  2

9          -> -1                       -1 -> -1

2          -> 5                       5   -> 1

5          -> 7                       7  -> -1

1          ->  7                       7 -> -1

7          -> -1                       7 -> -1

Input:

Dòng đầu tiên đưa vào số lượng bộ test T;
Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào n là số phần tử của mảng A[], dòng tiếp theo đưa vào n số A[i].
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ràng buộc:

T, n, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤n, A[i] ≤106.
Ví dụ:

Input
2
7
5 1 9 2 5 1 7
8
4 8 2 1 9 5 6 3

Output
2 2 1 1 -1 -1 -1
2 5 5 5 -1 3 -1 -1
*/
#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> v;
deque <int> big, small;

void bigger_right() {
    stack <pair <int, int>> st; // fi: value, se: index
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top().first <= v[i]) {
            st.pop();
        }
        if (!st.empty())
            big.push_front(st.top().second);
        else
            big.push_front(-1);
        st.push({ v[i], i });
    }
}

void smaller_right() {
    stack <pair <int, int>> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top().first >= v[i]) {
            st.pop();
        }
        if (!st.empty())
            small.push_front(st.top().second);
        else
            small.push_front(-1);
        st.push({ v[i], i });
    }
}

void solution() {
    cin >> n;
    v = vector <int>(n);
    big.clear();
    small.clear();
    for (auto& i : v) cin >> i;
    bigger_right();
    smaller_right();
    for (int i = 0; i < n; i++) {
        if (big[i] != -1 && small[big[i]] != -1) cout << v[small[big[i]]] << " ";
        else cout << -1 << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}