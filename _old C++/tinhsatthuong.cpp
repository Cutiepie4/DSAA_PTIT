#include <iostream>
#include <vector>
using namespace std;
/*
Ursa là một hero rất bá đạo trong DotA
anh có kỹ năng gia tăng sức mạnh sau mỗi cú đánh theo công thức:
Di = Di-1 + i với i là số thứ tự cú đánh và Di là lượng sát thương gây ra sau cú đánh đó
với i = 1 thi Di = 1.
Sơn mới tập chơi DotA và chơi một hero có lượng máu cơ bản là X.
Hero của Sơn không chịu được đòn đánh có sát thương lớn hơn X.
Bạn hãy giúp Sơn tính xem có thể chịu được tối đa bao nhiêu cú đánh của Ursa.
*/
int a[10000];
int process(int x)
{
    int total = 0;
    a[0] = 0;
    for (int i = 1; i < 10000; i++)
    {
        a[i] = a[i - 1] + i;
        x -= a[i];
        if (x < 0)
            break;
        total++;
    }
    return total;
}
main()
{
    int x;
    cin >> x;
    cout << process(x);
}