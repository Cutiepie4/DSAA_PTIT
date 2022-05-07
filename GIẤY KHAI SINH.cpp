/*
Một buổi họp mặt đại gia đình nhân dịp cụ già Ted tròn 100 tuổi, người ta muốn sắp xếp con cháu của cụ theo thứ tự từ tuổi cao xuống thấp. Giả sử ta có thông tin về giấy khai sinh của từng người đó. Mỗi giấy khai sinh chỉ viết ba thông tin đơn giản gồm: Tên người cha, Tên người con, Tuổi của người cha lúc sinh con.

Hãy giúp đại gia đình trên tính ra tuổi của từng người con cháu cụ Ted và viết ra danh sách theo thứ tự từ tuổi cao xuống thấp.

Input

Dòng đầu ghi số bộ test (không quá 100). Với mỗi bộ test:

Dòng đầu tiên ghi số X (0<X<100) là số người con cháu cần sắp xếp.
Tiếp theo là X dòng, mỗi dòng ghi thông tin về một giấy khai sinh của từng người (thứ tự ngẫu nhiên) gồm 3 thành phần, mỗi thành phần cách nhau một khoảng trống:
Tên người cha: không quá 20 ký tự và không chứa khoảng trống
Tên người con: không quá 20 ký tự và không chứa khoảng trống
Tuổi của người cha khi sinh con: 1 số nguyên dương, không quá 100.
Output

Với mỗi bộ test, in ra màn hình thứ tự bộ test (xem thêm trong bộ test ví dụ), sau đó lần lượt là từng người trong danh sách tuổi từ cao xuống thấp (không tính cụ Ted). Mỗi người viết ra hai thông tin: tên, một khoảng trống rồi đến tuổi của người đó.
Nếu hai người có cùng tuổi thì xếp theo thứ tự từ điển.
Ví dụ

INPUT:
2
1
Ted Bill 25
4
Ray James 40
James Beelzebub 17
Ray Mark 75
Ted Ray 20

OUTPUT:
DATASET 1
Bill 75
DATASET 2
Ray 80
James 40
Beelzebub 23
Mark 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vt vector <int>
#define vtl vector <ll>
#define matrix vector <vector <int>>
#define matrixl vector <vector <ll>>
const ll MOD = 1e9 + 7;

int cmp(pair <string, int> a, pair <string, int> b) {
    if (a.second > b.second) return 1;
    else if (a.second == b.second && a.first < b.first) return 1;
    return 0;
}

struct f {
    vector <pair <string, int>> son;
    int age;
};

unordered_map <string, f> mp;

void init(string s) {
    stringstream ss;
    string a1, a2, a3;
    ss << s;
    ss >> a1, ss >> a2, ss >> a3;
    int kt = 1;
    if (mp.find(a1) == mp.end()) {
        f tmp;
        tmp.age = 0;
        tmp.son.push_back({ a2, stoi(a3,0,10) });
        mp[a1] = tmp;
    }
    else mp[a1].son.push_back({ a2, stoi(a3,0,10) });
}

void process() {
    queue <string> q;
    vector <pair <string, int>> Data;
    q.push("Ted");
    mp["Ted"].age = 100;
    while (!q.empty()) {
        for (int i = 0; i < mp[q.front()].son.size(); i++) {
            mp[mp[q.front()].son[i].first].age = mp[q.front()].age - mp[q.front()].son[i].second;
            q.push(mp[q.front()].son[i].first);
            Data.push_back({ mp[q.front()].son[i].first,mp[mp[q.front()].son[i].first].age });
        }
        q.pop();
    }
    sort(Data.begin(), Data.end(), cmp);
    for (int i = 0; i < Data.size(); i++) {
        cout << Data[i].first << " " << Data[i].second << endl;
    }
}

void solution(int t) {
    mp.clear();
    int n;
    cin >> n;
    cin.ignore();
    string s;
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        init(s);
    }
    cout << "DATASET " << t << endl;
    process();
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solution(i);
    }
}