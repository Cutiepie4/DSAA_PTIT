/*
Sau khi thi trượt môn Cấu trúc dữ liệu và giải thuật, một số sinh viên D19 CNTT - PTIT quyết định bỏ học, đầu tư thuê đất để trồng rau. Mảnh đất thuê là một hình chữ nhật N x M (1≤ N≤ 100; 1≤ M≤ 100) ô đất hình vuông. Nhưng chỉ sau đó vài ngày, trận lụt khủng khiếp đã diễn ra làm một số ô đất bị ngập. Mảnh đất bỗng biến thành các cái ao. Và sinh viên D19 lại dự định chuyển sang nuôi cá. Các bạn ấy muốn biết mảnh đất được chia thành bao nhiêu cái ao để có thể tính toán nuôi cá cho hợp lý. Hãy giúp các bạn ấy nhé. Chú ý: Ao là gồm một số ô đất bị ngập có chung đỉnh. Dễ nhận thấy là một ô đất có thể có tối đa 8 ô chung đỉnh.

Dữ liệu vào: Dòng1: 2 số nguyên cách nhau bởi dấu cách: N và M. Dòng 2..N+1: M kí tự liên tiếp nhau mỗi dòng đại diện cho 1 hàng các ô đất.  Mỗi kí tự là 'W' hoặc '.' tương ứng với ô đất đã bị ngập và ô đất vẫn còn nguyên.

Kết quả:  Một dòng chứa 1 số nguyên duy nhất là số ao tạo thành.

Input
Output
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
3
*/
#include <bits/stdc++.h>
using namespace std;

const int X[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int Y[] = { 1, 0, -1, -1, 1, -1, 0, 1 };
int r, c;
char M[100][100];

void bfs(int x, int y) {
    queue <pair <int, int>> Q;
    Q.push({ x, y });
    while (!Q.empty()) {
        int r1 = Q.front().first, c1 = Q.front().second;
        Q.pop();

        for (int i = 0; i < 8; i++) {
            int x1 = r1 + X[i], y1 = c1 + Y[i];
            if (x1 >= 0 && x1 < r && y1 >= 0 && y1 < c && M[x1][y1] == 'W') {
                M[x1][y1] = '.';
                Q.push({ x1, y1 });
            }
        }
    }
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> M[i][j];

    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (M[i][j] == 'W') {
                bfs(i, j);
                ans++;
            }
        }
    }

    cout << ans;
}