/*
Cho số tự nhiên N (N<10^9) và hai phép biến đổi (a), (b) dưới đây.

Thao tác (a): Trừ N đi 1 (N=N-1). Ví dụ N=17, thao tác (a) biến đổi N = N-1 =16.
Thao tác (b): N = max(u,v) nếu u*v =N (u>1, v>1). Ví dụ N=16, thao tác (b) có thể biến đổi N = max(2, 8)=8 hoặc N=max(4, 4)=4.
Chỉ được phép sử dụng hai thao tác (a) hoặc (b), hãy biến đổi N thành 1 sao số các thao tác (a), (b) được thực hiện ít nhất. Ví dụ với N=17, số các phép (a), (b) nhỏ nhất biến đổi N thành 1 là 4 bước như sau:

                                    Thao tác (a): N = N-1 = 17-1 = 16

                                    Thao tác (b): 16 = max(4,4) = 4

                                    Thao tác (b): 4 = max(2,2) = 2

                                    Thao tác (a): 2 = 2-1 = 1

Input:

Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test;
T dòng kế tiếp mỗi dòng ghi lại một bộ Test. Mỗi test là một số N.
          Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:



Input
3
17
50
100

Output
4
5
5
*/
#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    map <int, int> vs;
    queue <pair <int, int>> Q;
    Q.push({ n,0 });
    while (!Q.empty()) {
        int x = Q.front().first, cnt = Q.front().second;
        Q.pop();

        if (x == 1) return cnt;
        if (x == 2) return cnt + 1;
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0 && !vs[x / i]) {
                Q.push({ x / i, cnt + 1 });
                vs[x / i] = 1;
            }
        }
        Q.push({ x - 1, cnt + 1 });
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solution(n) << endl;
    }
}