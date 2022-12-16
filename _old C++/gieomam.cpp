/*
Trên một giá có kích thước R x C (R hàng, C cột),
một số hạt mầm đã được tra vào các ô. Một số hạt mầm 
được bón thêm chất dinh dưỡng, nên đã nảy mầm sớm thành cây non.

Mỗi ngày, các cây non sẽ lan truyền chấdinh dưỡng 
của nó cho các mầm ở ô xung quanh (trái, trên, ải, dưới), 
làm cho các hạt mầm này phát triển thành cây non. 
Tuy nhiên, có thể có một số hạt mầm được gieo ở vị trí lẻ loi, 
do không nhận được chất dinh dưỡng nên không thể nảy mầm.

Các bạn hãy xác định xem cần ít nhất bao nhiêu ngày để tất 
cả các hạt đều mầm?

Input:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vt vector <int>
#define vtl vector <ll>
#define matrix vector <vector <int>>
#define matrixl vector <vector <ll>>
const ll MOD = 1e9 + 7;

int time(matrix mt, int r, int c, int cnt, queue <pair <int, int>> Seed) {
    for (int i = 0; i < 10000; i++) {
        queue <pair <int, int>> tmp;
        while (!Seed.empty()) {
            int x = Seed.front().first, y = Seed.front().second;
            if (y + 1 < c && mt[x][y + 1] == 1) {
                mt[x][y + 1] = 2;
                cnt--;
                tmp.push({ x,y + 1 });
            }
            if (y > 0 && mt[x][y - 1] == 1) {
                mt[x][y - 1] = 2;
                cnt--;
                tmp.push({ x,y - 1 });
            }
            if (x + 1 < r && mt[x + 1][y] == 1) {
                mt[x + 1][y] = 2;
                cnt--;
                tmp.push({ x + 1,y });
            }
            if (x > 0 && mt[x - 1][y] == 1) {
                mt[x - 1][y] = 2;
                cnt--;
                tmp.push({ x - 1,y });
            }
            Seed.pop();
        }
        if (tmp.empty()) {
            if (cnt == 0) return i;
            return -1;
        }
        else Seed = tmp;
    }
}

void solution() {
    queue <pair <int, int>> Seed;
    int r, c, cnt = 0;
    cin >> r >> c;
    matrix mt(r, vt(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mt[i][j];
            if (mt[i][j] == 2) Seed.push({ i,j });
            else if (mt[i][j] == 1) cnt++;
        }
    }
    cout << time(mt, r, c, cnt, Seed) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}
