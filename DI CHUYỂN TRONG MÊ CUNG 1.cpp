/*
Cho một mê cung bao gồm các khối được biểu diễn như một ma trận nhị phân A[N][N]. Một con chuột đi từ ô đầu tiên góc trái (A[0][0]) đến ô cuối cùng góc phải (A[N-1][N-1]) theo nguyên tắc:

Down (D): Chuột được phép xuống dưới nếu ô dưới nó có giá trị 1.
Right (R): Chuột được phép sang phải dưới nếu ô bên phải nó có giá trị 1.
Hãy đưa ra một hành trình của con chuột trên mê cung. Đưa ra -1 nếu chuột không thể đi đến đích.

                        

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N là kích cỡ của mê cung; dòng tiếp theo đưa vào ma trận nhị phân A[N][N].
T, N, A[i][j] thỏa mãn ràng buộc: 1≤T ≤10; 2≤N≤10; 0≤A[i][j] ≤1.
Output:

Đưa ra tất cả đường đi của con chuột trong mê cung theo thứ tự từ điển. Đưa ra -1 nếu chuột không đi được đến đích.
Input
2
4
1  0  0  0
1  1  0  1 
0  1  0  0 
1  1  1  1
5
1 0 0 0 0
1 1 1 1 1
1 1 0 0 1
0 1 1 1 1
0 0 0 1 1

OUTPUT
DRDDRR
DDRDRRDR DDRDRRRD DRDDRRDR DRDDRRRD DRRRRDDD
*/
#include <bits/stdc++.h>
using namespace std;

void find_path(vector <vector <int>>& v, vector <vector <vector <string>>>& data, int row, int col, vector <vector <int>>& mark) {
    queue <pair <int, int>> q;
    q.push({ 0,0 });
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (v[x][y + 1] == 1) {
            if (mark[x][y + 1]) q.push({ x, y + 1 });
            mark[x][y + 1] = 0;
            if (data[x][y].empty()) data[x][y + 1].push_back("R");
            else for (int i = 0; i < data[x][y].size(); i++) {
                string tmp = data[x][y][i];
                tmp.push_back('R');
                data[x][y + 1].push_back(tmp);
            }
        }
        if (v[x + 1][y] == 1) {
            if (mark[x + 1][y]) q.push({ x + 1, y });
            mark[x + 1][y] = 0;
            if (data[x][y].empty()) data[x + 1][y].push_back("D");
            else for (int i = 0; i < data[x][y].size(); i++) {
                string tmp = data[x][y][i];
                tmp.push_back('D');
                data[x + 1][y].push_back(tmp);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <vector <int>> v(n + 1, vector <int>(n + 1, 0));
        vector <vector <int>> mark(n + 1, vector <int>(n + 1, 1));
        vector <vector <vector <string>>> data(n, vector<vector <string>>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
        if (v[0][0] == 0) {
            cout << "-1" << endl;
            continue;
        }
        find_path(v, data, n - 1, n - 1, mark);
        if (!data[n - 1][n - 1].empty()) {
            sort(data[n - 1][n - 1].begin(), data[n - 1][n - 1].end());
            for (auto i : data[n - 1][n - 1]) cout << i << " ";
            cout << endl;
        }
        else cout << "-1" << endl;
    }
}