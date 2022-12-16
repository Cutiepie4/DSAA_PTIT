/*
Có một số đứa trẻ đang ăn trưa ở bàn ăn. Chúng luân phiên nhau lấy thức ăn từ bàn. Một số đứa trẻ ko được dạy dỗ nên nhảy vào lấy mà ko cho người khác cơ hội. Nếu ở 1 thời điểm 1 đứa trẻ lấy 1 miếng thức ăn mà trong khi nó có nhiều thức ăn hơn tất cả những đứa trẻ khác cộng lại,
nó sẽ bị cô giáo cảnh báo về cách cư xử.
Cho thứ tự lấy thức ăn của bọn trẻ,
tính số lần cô giáo phải cảnh báo.
Input
Dòng đầu chứa N (1<=N<=100) số lượt lấy thức ăn
N dòng sau, mỗi dòng chứa tên 1 đứa trẻ 
(không quá 20 kí tự tiếng ANh in thường)
Output
Số lần cảnh báo
*/
#include <iostream>
#include <vector>
using namespace std;
struct data
{
    string name;
    int cake = 0;
} x[100];
int main()
{
    int n, t = 0;
    cin >> n;
    string s[100];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        int kt = 1;
        for (int j = 0; j < t; j++)
        {
            if (x[j].name == s[i])
            {
                kt = 0;
                break;
            }
        }
        if (kt)
            x[t++].name = s[i];
    }
    int alert = 0, total = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < t; j++)
        {
            if (s[i] == x[j].name)
            {
                if (x[j].cake > total - x[j].cake)
                    alert++;
                total++;
                x[j].cake++;
            }
        }
    }
    cout << alert;
}