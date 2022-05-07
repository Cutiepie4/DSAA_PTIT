/*
Cho một dãy N viên bi gồm 3 màu xanh, trắng, đỏ xếp lẫn lộn. Bằng cách đổi chỗ từng cặp viên bi cho nhau có thể xếp lại dãy bi trên sao cho các viên bi xanh đứng trước, sau đó đến các viên bi trắng và cuối cùng là các viên bi đỏ. Tìm số lượng ít nhất các phép đổi chỗ cần thực hiện

Input

Dòng đầu  tiên ghi N (N≤100)
Dòng thứ hai ghi xâu ký tự mô tả dãy bi (T-trắng, X-xanh, D-đỏ).
Output

Một dòng duy nhất ghi số phép đổi chỗ tối thiểu cần thực hiện

 

Ví dụ

 

Input

Output

9

TTXDDDTDX

4
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, cnt1 = 0, cnt2 = 0, cnt3 = 0;
    string s;
    cin >> n >> s;
    vector <int> v;
    for (auto a : s) {
        if (a == 'X') {
            cnt1++;
        }
        else if (a == 'T') {
            cnt2++;
        }
        else {
            cnt3++;
        }
    }
    cnt2 += cnt1;
    cnt3 += cnt2;
    int ans = 0;
    for (int i = 0; i < cnt1; i++) {
        if (s[i] == 'T') {
            for (int j = cnt1; j < n; j++) {
                if (s[j] == 'X') {
                    ans++;
                    swap(s[i], s[j]);
                    break;
                }
            }
        }
        else if (s[i] == 'D') {
            for (int j = n - 1; j >= cnt1; j--) {
                if (s[j] == 'X') {
                    ans++;
                    swap(s[i], s[j]);
                    break;
                }
            }
        }
    }

    for (int i = cnt1; i < cnt2; i++) {
        if (s[i] == 'D') {
            for (int j = cnt2; j < n; j++) {
                if (s[j] == 'T') {
                    swap(s[i], s[j]);
                    ans++;
                    break;
                }
            }
        }
    }
    // for (auto i : v) cout << i;
    // cout << endl;
    cout << ans;
}