/*
Mỗi câu được Tờ viết trên 1 dòng là 1 chuỗi ký tự với chữ cái đầu tiên được viết hoa,
 các chữ cái còn lại viết thường, các từ cách nhau đúng 1 dấu cách.
 Để mã hóa mỗi chuỗi ký tự này, Tờ di chuyển chữ cái đầu tiên về cuối,
 dịch trái các chữ cái còn lại sao cho vẫn giữ nguyên vị trí dấu cách.
 Để thêm đặc biệt, Tờ muốn them vào cuối mỗi chuối 2 ký tự “ee” – tên viết
 tắt của crush. Và để cho giống một câu như bình thường, Tờ muốn chữ cái đầu
 viết hoa, còn lại thì viết thường. (Xem ví dụ để hiểu rõ hơn cách mã hóa).

Hãy giúp Tờ mã hóa lời tỏ tình của Tờ với crush nhé!

Input
Dòng đầu tiên chứa số nguyên T (0 < T < 1000) là số bộ test.
T dòng tiếp theo, mỗi dòng là 1 xâu ký tự S (bao gồm chữ cái viế hoa, viết thường 
và dấu cách) mà Tờ muốn mã hóa. (0 < |S| < 10000).

Output
Với mỗi bộ test, in ra trên 1 dòng xâu đã được mã hóa.
*/
#include <bits/stdc++.h>

using namespace std;
int main() {
    int t;
    cin >> t;
    scanf("\n");
    while (t--) {
        string s = "";
        getline(cin, s);
        s.push_back(tolower(s[0])); s.erase(s.begin());
        for (int i = 0; i < s.size(); i++) if (s[i] != ' ') {
            s[i] = toupper(s[i]); break;
        }
        string tmp = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                tmp.push_back(s[i + 1]); tmp.push_back(' '); i++;
            }
            else tmp.push_back(s[i]);
        }
        tmp.push_back('e'); tmp.push_back('e');
        cout << tmp << endl;
    }
}