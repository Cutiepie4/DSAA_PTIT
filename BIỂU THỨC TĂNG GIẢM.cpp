/*
Cho dãy ký tự S chỉ bao gồm các ký tự I hoặc D. Ký tự I được hiểu là tăng (Increasing) ký tự D được hiểu là giảm (Decreasing). Sử dụng các số từ 1 đến 9, hãy đưa ra số nhỏ nhất được đoán nhận từ S. Chú ý, các số không được phép lặp lại. Dưới đây là một số ví dụ mẫu:

A[] = “I”               : số tăng nhỏ nhất là 12.
A[] = “D”              : số giảm nhỏ nhất là 21
A[] =”DD”            : số giảm nhỏ nhất là 321
A[] = “DDIDDIID”: số thỏa mãn 321654798
Input: Dòng đầu tiên đưa vào số lượng bộ test T.  Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu S. T, S thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ length(S) ≤8; .

Output: Đưa ra thứ tự bộ test và kết quả mỗi test theo từng dòng.
Ví dụ:
Input:
4
I
D
DD
DDIDDIID

OUTPUT:
Test 1: 12
Test 2: 21
Test 3: 321
Test 4: 321654798
*/
#include <bits/stdc++.h>
using namespace std;

void process(vector <int>& v) {
    int maxx = 1, index = 0;
    for (int i = index; i < v.size(); i++) {
        if (v[i] < v[i + 1] || i == v.size() - 1) {
            int x = maxx - v[i];
            for (int j = i; j >= index; j--) {
                v[j] += x;
                maxx = max(maxx, v[j]);
            }
            maxx++;
            index = i + 1;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        string s;
        cin >> s;
        vector <int> v(1, 0);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'I') {
                v.push_back(v.back());
                v.back()++;
            }
            else {
                v.push_back(v.back());
                v.back()--;
            }
        }
        process(v);
        cout << "Test " << z << ": ";
        for (auto i : v) cout << i;
        cout << endl;
    }
}