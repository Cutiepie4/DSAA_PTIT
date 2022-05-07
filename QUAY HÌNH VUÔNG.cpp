/*
Có một chiếc bảng hình chữ nhật với 6 miếng ghép, trên mỗi miếng ghép được điền một số nguyên trong khoảng từ 1 đến 6. Tại mỗi bước, chọn một hình vuông (bên trái hoặc bên phải), rồi quay theo chiều kim đồng hồ.



 

 

 

Yêu cầu: Cho một trạng thái của bảng, hãy tính số phép biến đổi ít nhất để đưa bảng đến trạng thái đích.

Input:

Dòng đầu ghi số bộ test (không quá 10). Mỗi bộ test gồm hai dòng:
Dòng đầu tiên chứa 6 số là trạng thái bảng ban đầu (thứ tự từ trái qua phải, dòng 1 tới dòng 2).
Dòng thứ hai chứa 6 số là trạng thái bảng đích (thứ tự từ trái qua phải, dòng 1 tới dòng 2).
Output: 

Với mỗi test, in ra một số nguyên là đáp số của bài toán.
Ví dụ:

Input
1
1 2 3 4 5 6
4 1 2 6 5 3
 
Output
2
*/
#include <bits/stdc++.h>
using namespace std;
#define vt vector <int>
#define mt vector <vt>

mt M, D;
// 0: left, 1: right
void rotate(int i, mt& M) {
    int x = M[0][i], y = M[0][1 + i], z = M[1][i], t = M[1][1 + i];
    M[0][i] = z, M[0][1 + i] = x, M[1][i] = t, M[1][1 + i] = y;
}

int count_rotate() {
    if (M == D) return 0;
    queue <pair <int, pair <mt, int>>> Q;
    Q.push({ 0,{M,0} });
    Q.push({ 1,{M,0} });
    while (!Q.empty()) {
        mt tmp = Q.front().second.first;
        int x = Q.front().first, cnt = Q.front().second.second;
        Q.pop();

        rotate(x, tmp);
        if (tmp == D) return cnt + 1;
        Q.push({ 0,{tmp, cnt + 1} });
        Q.push({ 1,{tmp, cnt + 1} });
    }
}

void solution() {
    M = mt(2, vt(3));
    D = mt(2, vt(3));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> M[i][j];
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> D[i][j];
        }
    }
    cout << count_rotate();
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