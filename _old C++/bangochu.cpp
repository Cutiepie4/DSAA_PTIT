/*
Cho một bảng các ô kích thước R * C.
Mỗi ô có thể là chữ cái in thường hoặc ô trống (kí hiệu là "#").
Một từ là một chuỗi các chữ cái liên tiếp theo chiều dọc hoặc ngang dài nhất có thể.
Tìm từ có ít nhất 2 chữ cái trở lên và có thứ tự từ điển bé nhất.
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    string s[a], res[400];
    int x = 0;
    for (int i = 0; i < a; i++)
        cin >> s[i];
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (s[i][j] != '#')
                res[x].push_back(s[i][j]);
            else
                x++;
        }
        x++;
    }
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (s[j][i] != '#')
                res[x].push_back(s[j][i]);
            else
                x++;
        }
        x++;
    }
    string tmp[400];
    int y = 0;
    for (int i = 0; i < x; i++)
    {
        if (res[i].size() >= 2)
            tmp[y++] = res[i];
    }
    for (int i = 0; i < y - 1; i++)
    {
        for (int j = i + 1; j < y; j++)
        {
            if (tmp[i] > tmp[j])
                swap(tmp[i], tmp[j]);
        }
    }
    cout << tmp[0];
}