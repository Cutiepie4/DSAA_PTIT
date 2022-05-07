/*
Có n cuộc họp đánh số từ 1 đến n đăng ký làm việc tại một phòng hội thảo.
Cuộc họp i cần được bắt đầu ngay sau thời điểm si và kết thúc tại thời
điểm f­i.
Hỏi có thể bố trí phòng hội thảo phục vụ đượnhiều nhất bao nhiêu 
cuộc họp, sao cho khoảng thời gian làm việc củcuộc họp bất 
kỳ là không giao nhau.
*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

vector <pair<int, int> > v;
int n;
int cmp(pair <int, int> a, pair <int, int> b) {
    if (a.first < b.first) return 1;
    if (a.first == b.first && a.second < b.second) return 1;
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        v.clear();
        cin >> n;
        for (int i = 0, a, b;i < n;i++) {
            cin >> a >> b;
            v.pb({ a,b });
        }
        sort(v.begin(), v.end(), cmp);
        int res = 1, pos = 0;
        for (int i = 1;i < n;i++) {
            if (v[i].first >= v[pos].second) {
                res++;
                pos = i;
            }
            else if (v[i].second < v[pos].second) pos = i;
        }
        cout << res << endl;
    }
}