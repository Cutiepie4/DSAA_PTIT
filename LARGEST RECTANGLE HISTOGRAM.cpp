// bài này ta tạo 1 stack chứa index và value của dãy số.
// chia ra 2 trường hợp. 

// Nếu giá trị chuẩn bị đưa giá trị vào stack
// ta thấy giá trị đó nhỏ hơn giá trị top(), khi đó top() sẽ ko extended qua bên
// phải được nữa, ta bắt đầu pop() giá trị top() đi, ta đánh dấu index hiện tại,
// mỗi lần pop sẽ check max, độ cao là value top(), độ rộng là từ index top() đến
// index vừa đánh dấu, pop() dần dần cho đến khi top() <= số add.
// Ta lấy index của top() cuối cùng đã pop() và thế cho index của số add.
// Nếu như top() <= value add thì add đúng index và value vào.

// Sau khi duyệt toàn bộ dãy thì ta đc lại stack mới. Khi đó duyệt dần dần cho đến hết stack 
// vì giá trị dưới luôn nhỏ hơn giá trị trên nên ta lấy giá trị đó x index của top() đầu tiên
// lấy max

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll max_histogram(vector <ll> v) {
    ll ans = INT32_MIN, i = 0, top_val, area;
    stack <ll> st;
    while (i < v.size()) {
        if (st.empty() || v[st.top()] <= v[i]) {
            st.push(i++);
        }
        else {
            top_val = v[st.top()];
            st.pop();
            if (st.empty()) area = top_val * i;
            else area = top_val * (i - st.top() - 1);

            ans = max(ans, area);
        }
    }
    while (!st.empty()) {
        top_val = v[st.top()];
        st.pop();
        if (st.empty()) area = top_val * i;
        else area = top_val * (i - st.top() - 1);
        ans = max(ans, area);
    }
    return ans;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector <ll> v(n);
        for (auto& i : v) cin >> i;
        cout << max_histogram(v) << endl;
    }
}