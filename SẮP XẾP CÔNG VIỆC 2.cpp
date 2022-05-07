/*
Cho N công việc. Mỗi công việc được biểu diễn như một bộ 3 số nguyên dương <JobId, Deadline, Profit>, trong đó JobId là mã của việc, Deadline là thời gian kết thúc của việc, Profit là lợi nhuận đem lại nếu hoàn thành việc đó đúng thời gian. Thời gian để hoàn toàn mỗi công việc là 1 đơn vị thời gian. Hãy cho biết lợi nhuận lớn nhất có thể thực hiện các việc với giả thiết mỗi việc được thực hiện đơn lẻ.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là số lượng Job N; phần thứ hai đưa vào 3×N số tương ứng với N job.
T, N, JobId, Deadline, Profit thỏa mãn ràng buộc:1≤T≤100;  1≤N≤1000; 1≤ JobId ≤1000; 1≤ Deadline ≤1000; 1≤ Profit ≤1000.
Output:

Đưa số lượng công việc tương ứng và lợi nhuận lớn nhất có thể đạt được.
Ví dụ:

Input

Output

2
4
1 4 20

2 1 10

3 1 40

4 1 30
5
1 2 100

2 1 19

3 2 27

4 1 25

5 1 15

2 60
2 127
*/

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, d = 0, ans = 0;
        cin >> n;
        int check[n + 1] = {};
        vector<pair<int, int>> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> x >> a[i].second >> a[i].first;
        sort(a.begin() + 1, a.end(), greater<pair<int, int>>());
        for (int i = 1; i <= n; i++)
        {
            for (int j = min(n, a[i].second); j >= 1; j--)
            {
                if (!check[j])
                {
                    ans += a[i].first;
                    d++;
                    check[j] = 1;
                    break;
                }
            }
        }
        cout << d << " " << ans << endl;
    }
}