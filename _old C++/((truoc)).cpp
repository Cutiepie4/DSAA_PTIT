/*
Input
Dòng 1: Một chuỗi ngoặc đơn có độ dài là N (1 <= N <= 50,000).
Output
Dòng 1: Số vị trí mà Bessie có thể đứng – Có nghĩa là số cặp (x,y) khác nhau với x < y
sao cho (( được tìm thấy ở x và )) được tìm thấy ở y. */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int t = 0, t1 = 0, x = 0;
    int x1[50001], y1[50001];
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == '(' && s[i + 1] == '(')
        {
            x1[t++] = i;
        }
        else if (s[i] == ')' && s[i + 1] == ')')
        {
            y1[t1++] = i;
        }
    }
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t1; j++)
        {
            if (x1[i] < y1[j])
                x++;
        }
    }
    cout << x;
}