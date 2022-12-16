/*
Mirko vừa tìm thấy 1 trò chơi điện tử cũ.
Màn hình của game chia thành N cột.
Ở dưới của màn hình , có 1 con thuyền chứa trong M cột (M<N).
Người chơi có thể di chuyển thuyền sang trái hoặc phải, nhưng phải
trong phạm vi của màn hình.
Ban đầu, thuyền ở M cột bên trái nhất của màn hình.
Những quả táo sẽ rơi từ phía trên của màn hình.
Mỗi quả bắt đầu rơi ở đầu trên của một cột, và rơi xuống phía dưới của màn hình.
Quả tiếp theo rơi sau khi quả trước đó chạm đáy.
Nhiệm vụ của bạn là tìm cách di chuyển ngắn nhất để có thể lấy tất cả trái táo.
Dữ liệu:
Dòng đầu chứa 2 số nguyên N và M (1<=M<=N<=10).
Dòng 2 chứa số nguyên J (1<=J<=20), số trái táo rơi.
J dòng sau là thứ tự các cột của các quả táo sẽ rơi.
*/
#include <bits/stdc++.h>
using namespace std;
struct ship
{
    int x = 1, y;
} xxx;
int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    xxx.y = m;
    int a[x + 1], res = 0;
    for (int i = 1; i <= x; i++)
        cin >> a[i];
    for (int i = 1; i <= x; i++)
    {
        if (a[i] < xxx.x)
        {
            res += xxx.x - a[i];
            xxx.x = a[i];
            xxx.y = xxx.x + m - 1;
        }
        if (a[i] > xxx.y)
        {
            res += a[i] - xxx.y;
            xxx.y = a[i];
            xxx.x = xxx.y - m + 1;
        }
    }
    cout << res;
}