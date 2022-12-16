/* 
Cho trước một đa giác lồi N cạnh, thỏa mãn không có 3 đường chéo nào đồng quy. 
Hãy đếm số giao điểm tạo bởi các cặp đường chéo trong đa giác.
*/
#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    std::cout << n * (n - 1) * (n - 2) * (n - 3) / 24;
    return 0;
}