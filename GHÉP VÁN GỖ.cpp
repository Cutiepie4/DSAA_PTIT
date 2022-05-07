/*
Tí muốn tấm biển quảng cáo của mình thật đặc biệt, nên Tí đã chọn nhất định nó sẽ là hình vuông. Không có eke, thước, dây, … nên Tí phải dựa vào các miếng gỗ ban đầu để căn nhát cưa. Việc cưa theo chiều dọc rất dễ dàng, nhưng theo chiều ngang, Tí chỉ có thể cưa theo một đường thẳng trùng với một cạnh của miếng gỗ nào đó.

Các bạn hãy giúp Tí tính thử xem tấm biển quảng cáo của Tí có kích thước lớn nhất bằng bao nhiêu (kích thước ở đây là độ dài cạnh hình vuông).



Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test bắt đầu bởi số nguyên N (N ≤ 100 000). Dòng tiếp theo gồm N số nguyên A[i] (1 ≤ A[i] ≤ 109).

Output:   Với mỗi test, in ra chiều dài cạnh của tấm biển. Nếu Tí không thể tạo thành tấm biển, in ra 0.

Ví dụ:

Input:
4
5
2 4 3 3 1 4
3
2 2 2
2
6 6
6
5 5 5 5 3 1

Output
4
2
0
3
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector <int> v;

ll max_histogram() {
    int ans = 0;
    stack <int> st; // index, top always bigger than the rest
    int i = 0;
    while (i < v.size()) {
        if (st.empty() || v[st.top()] <= v[i]) {
            st.push(i++);
        }
        else {
            int tmp = v[st.top()];
            st.pop();

            if (st.empty()) {
                if (i >= tmp)
                    ans = max(ans, tmp);
            }
            else {
                if (i - st.top() - 1 >= tmp)
                    ans = max(ans, tmp);
            }
        }
    }
    while (!st.empty()) {
        int tmp = v[st.top()];
        st.pop();

        if (st.empty()) {
            if (i >= tmp)
                ans = max(ans, tmp);
        }
        else {
            if (i - st.top() - 1 >= tmp)
                ans = max(ans, tmp);
        }
    }
    return ans;
}

void solution() {
    cin >> n;
    v = vector <int>(n);
    for (auto& i : v) cin >> i;
    cout << max_histogram();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}