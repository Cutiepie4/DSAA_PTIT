/*
Cho số tự nhiên K và xâu ký tự các chữ số S.  Nhiệm vụ của bạn là đưa ra số lớn nhất bằng cách thực hiện nhiều nhất K lần đổi chỗ các ký tự trong S. Ví dụ K =3 và S = “1234567” ta được “7654321”.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là số K; dòng tiếp theo là xâu ký tự S.
T, K, S thỏa mãn ràng buộc: 1≤T ≤100; 1≤K≤10; 1≤.lenght(S)≤7.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input
3
4
1234567
3
3435335
2
1034

Output
7654321
5543333
4301
*/
#include <bits/stdc++.h>
using namespace std;


string process(string& s, int k) {
    vector <int> v(10, 0);
    int x = 0;
    for (auto i : s) v[i - '0']++;
    for (int i = 9; i >= 0; i--) {
        if (v[i]) {
            vector <int> it;
            vector <int> val;
            int index = -1;
            for (int j = s.size() - 1; j > 0; j--) {
                if (s[j] == i + '0') {
                    for (int z = index + 1; z < j; z++) {
                        if (s[z] < s[j]) {
                            k--;
                            if (k < 0) break;
                            it.push_back(j);
                            index = z;
                            val.push_back(s[z] - '0');
                            swap(s[z], s[j]);
                            break;
                        }
                    }
                }
            }
            sort(it.begin(), it.end());
            sort(val.begin(), val.end(), greater <int>());
            for (int i = 0; i < it.size(); i++) {
                s[it[i]] = val[i] + '0';
            }
        }
    }
    return s;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        string s;
        cin >> k >> s;
        cout << process(s, k) << endl;
    }
}