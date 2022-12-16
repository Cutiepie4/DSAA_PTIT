/*
Hội trường gồm có R*C vị trí chỗ ngồi (R hàng và C cột).
Mỗi bạn sinh viên sẽ cố gắng làm quen và bắt tay với tất cả những người bạn xung quanh mình.
Như vậy, mỗi bạn sẽ làm quen được tối đa là 8 người bạn mới.
Buổi học đã bắt đầu, nhưng không may, Tèo lại đến muộn (là người muộn nhất).
Tèo sẽ chọn một vị trí trống sao cho có thể làm quen với nhiều bạn mới nhất có thể.
Nếu không có ghế trống nào, Tèo quyết định bùng học. :D
Hãy tính toán số lượng cái bắt tay sẽ được thực hiện trong buổi học đầu tiên này.
Input
Dòng đầu tiên là 2 số nguyên R và C (1 <= R, C <= 50).
R dòng tiếp theo, mỗi dòng chứa C kí tự.
Kí tự ‘.’ thể hiện chỗ ngồi còn trống, và kí tự ‘o’ thể hiện một sinh viên.
Output
In ra một số nguyên duy nhất là số lượng cái bắt tay sẽ được thực hiện.
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int r, c;
    cin >> r >> c;
    string s[r];
    for (int i = 0; i < r; i++) cin >> s[i];
    int kt = 1, res1 = 0;
    for (int z = 0; z < r; z++) {
        for (int t = 0; t < c; t++) {
            if (s[z][t] == '.') {
                kt = 0;
                s[z][t] = 'o';
                int res = 0;
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        if (s[i][j] == 'o') {
                            if (j + 1 < c && s[i][j + 1] == 'o')
                                res++;
                            if (i + 1 < r && s[i + 1][j] == 'o')
                                res++;
                            if (i + 1 < r && j + 1 < c && s[i + 1][j + 1] == 'o')
                                res++;
                            if (j - 1 >= 0 && i + 1 < r && s[i + 1][j - 1] == 'o')
                                res++;
                        }
                    }
                }
                res1 = max(res, res1);
                s[z][t] = '.';
            }
        }
    }
    if (kt) {
        int res = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (s[i][j] == 'o') {
                    if (j + 1 < c && s[i][j + 1] == 'o')
                        res++;
                    if (i + 1 < r && s[i + 1][j] == 'o')
                        res++;
                    if (i + 1 < r && j + 1 < c && s[i + 1][j + 1] == 'o')
                        res++;
                    if (j - 1 >= 0 && i + 1 < r && s[i + 1][j - 1] == 'o')
                        res++;
                }
            }
        }
        cout << res;
        return 0;
    }
    else
        cout << res1;
}