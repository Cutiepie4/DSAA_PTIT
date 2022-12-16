/*
anh phải xếp hàng để chờ tới lượt mua.
Có n người xếp hàng. Nhưng anh không biết chính xác vị trí mình
đang đứng là thứ bao nhiêu. Chỉ biết có không ít hơn a người đứng
trước và không nhiều hơn b người đứng sau anh.
Bạn hãy giúp anh ấy xác định xem anh ấy có thể đứng ở những vị trí nào trong hàng.
*/
#include <iostream>
#include <vector>
using namespace std;
main()
{
    int a, b, n;
    cin >> n >> a >> b;
    if (a + b + 1 <= n)
        cout << b + 1;
    else
        cout << n - a;
}