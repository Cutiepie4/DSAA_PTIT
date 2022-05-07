/*
Cho hai xâu ký tự str1, str2 bao gồm các ký tự in thường và các thao tác dưới đây:

Insert: chèn một ký tự bất kỳ vào str1.
Delete: loại bỏ một ký tự bất kỳ trong str1.
Replace: thay một ký tự bất kỳ trong str1.
Nhiệm vụ của bạn là đếm số các phép Insert, Delete, Replace ít nhất thực hiện trên str1 để trở thành str2.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ đôi hai xâu str1 và str2.
T, str1, str2 thỏa mãn ràng buộc: 1≤T≤100;  1≤length(str1),length(str2) ≤100.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:
Input
1
geek gesek
Output
1
*/

#include <bits/stdc++.h>
using namespace std;

// https://riptutorial.com/algorithm/example/31568/minimum-edits-required-to-convert-string-1-to-string-2

int transf(string a, string b) {
    vector <vector <int>> mt(a.size() + 1, vector <int>(b.size() + 1));

    for (int i = 0; i < a.size() + 1; i++) {
        for (int j = 0; j < b.size() + 1; j++) {
            if (i == 0) mt[i][j] = j;
            else if (j == 0) mt[i][j] = i;
            else if (a[i - 1] == b[j - 1]) mt[i][j] = mt[i - 1][j - 1];
            else mt[i][j] = 1 + min(mt[i - 1][j - 1], min(mt[i][j - 1], mt[i - 1][j]));
        }
    }
    return mt[a.size()][b.size()];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << transf(a, b) << endl;
    }
}