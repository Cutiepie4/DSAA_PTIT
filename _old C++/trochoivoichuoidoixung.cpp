#include <iostream>
#include <vector>
using namespace std;
/*Có 1 chuỗi kí tự s gồm các chữ cái thường, mỗi lượt chơi,
người chơi sẽ loại bỏ bất kì một chữ cái nào đó trong chuỗi s.
Nếu đến lượt của người chơi, trước khi loại bỏ kí tự mà người
đó có thể sắp xếp chuỗi s thành một chuỗi đối xứng, thì người
đó sẽ là người giành chiến thắng.
Tí là người đi trước.
Cả Tí và Tèo đều chơi tối ưu, hãy xác định ai là người chiến thắng.
*/
struct data
{
    char kitu;
    int dem;
} a[26];

main()
{
    string s;
    char x = 'a';
    for (int i = 0; i < 26; i++)
    {
        a[i].kitu = x;
        if (x == 'z')
            break;
        x++;
    }
    while (cin >> s)
    {
        for (int i = 0; i < 26; i++)
            a[i].dem = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (a[j].kitu == s[i])
                {
                    a[j].dem++;
                    break;
                }
            }
        }
        int kt = 0;
        for (int i = 0; i < 26; i++)
        {
            if (a[i].dem % 2 == 1)
            {
                kt++;
            }
        }
        if (kt <= 1)
        {
            cout << "First" << endl;
            continue;
        }
        if (kt % 2 == 1)
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }
}