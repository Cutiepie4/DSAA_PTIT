/*
Bạn được cung cấp một mảng gồm n phần tử và một số k .
Bạn cần tìm số nguyên dương x nhỏ nhất sao cho có đúng k phần tử của mảng
nhỏ hơn hoặc bằng x . Nếu không có số x thỏa mãn hãy in ra “-1” .

Input
Dòng đầu tiên chứa một số nguyên n  và k ( 1 ≤  n ≤  2.105 , 0  ≤  k  ≤  n ).

Dòng thứ hai chứa n số nguyên a1 , a2 ,…. an (0  <  ai  ≤ 109 ) là các phần tử của mảng.

Output
In ra số nguyên dương x . Nếu không có số x thỏa mãn hãy in ra “-1”
CHÚ Ý K=0
*/
#include <bits/stdc++.h>
using namespace std;
void quickSort(int a[], int l, int r)
{
    if (l <= r)
    {
        int key = a[(l + r) / 2];
        int i = l;
        int j = r;
        while (i <= j)
        {
            while (a[i] < key)
                i++;
            while (a[j] > key)
                j--;
            if (i <= j)
            {
                swap(a[i], a[j]);
                i++;
                j--;
            }
        }
        if (l < j)
            quickSort(a, l, j);
        if (r > i)
            quickSort(a, i, r);
    }
}
int main()
{
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    if (k == 0)
    {
        if (a[0] > 1)
        {
            cout << "1";
            return 0;
        }
        else
        {
            cout << "-1";
            return 0;
        }
    }
    if (a[k - 1] == a[k])
        cout << "-1";
    else
        cout << a[k - 1];
}