/*
Cho số tự nhiên N và thực hiện trừ N ln lượt N đi 
chữ số đầu tiên của N để N trở về . Ví dụ với N=13 
ta thực hiện các phép dịch chuyển N về 0 như sau:

Bước 1: N=N-1 = 13-1=12
Bước 2: N=N-1 = 12-1=11
Bước 3: N=N-1 = 11-1=10
Bước 4: N=N-1 = 10-1=9
Bước 5: N=N-1 = 9-9=0
Cho K là số các phép dịch chuyển N về 0 theo nguyên tắc kể trên. Nhiệm vụ của bạn là tìm số N lớn nhất từ xuất phát điểm ban đầu.
*/
#include <bits/stdc++.h>
using namespace std;

int countd(int m) {
    if (m == 0)return 0;
    return 1 + countd(m / 10);
}

int countSteps(int x) {
    int c = 0;
    int last = x;
    while (last) {
        int digits = countd(last);
        digits -= 1;
        int divisor = pow(10, digits);
        int first = last / divisor;
        int lastnumber = first * divisor;
        int skipped = (last - lastnumber) / first;
        skipped += 1;
        c += skipped;
        last = last - (first * skipped);
    }
    return c;
}

unordered_map <int, int> mp;
vector <int> v(1000001, 0);
void init() {
    for (int i = 1000000; i >= 10; i--) {
        int x = countSteps(i);
        if (mp.find(x) == mp.end()) mp.insert({ x,i });
    }
}

int main() {
    int t;
    cin >> t;
    init();
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "9" << endl;
            continue;
        }
        cout << mp[n] << endl;
    }
}