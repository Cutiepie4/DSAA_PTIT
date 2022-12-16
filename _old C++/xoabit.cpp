/*
Cho số a viết ở hệ cơ số 2. Nhiệm vụ của bạn là phải xóa một chữ số để số còn
lại xóa khi xóa là lớn nhất !!!

Input
Một dòng chứa số a viết ở hệ nhị phân.

Output
Số lớn nhất sau khi xóa 1 chữ số từ a.*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin >> a;
    int kt = 1;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '0')
        {
            a.erase(a.begin() + i);
            kt = 0;
            break;
        }
    }
    if (kt)
        a.erase(a.begin() + 1);
    cout << a;
}