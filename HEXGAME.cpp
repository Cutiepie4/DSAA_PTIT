#include <bits/stdc++.h>
using namespace std;

string T;
string O = "1238004765";

// 0: left, 1: right
void Forward(int i, string& M) {
    string tmp = M;
    M[i] = tmp[3 + i], M[1 + i] = tmp[i], M[3 + i] = tmp[7 + i], M[5 + i] = tmp[1 + i], M[7 + i] = tmp[8 + i], M[8 + i] = tmp[5 + i];
}

void Backward(int i, string& M) {
    string tmp = M;
    M[i] = tmp[1 + i], M[1 + i] = tmp[5 + i], M[3 + i] = tmp[i], M[5 + i] = tmp[8 + i], M[7 + i] = tmp[3 + i], M[8 + i] = tmp[7 + i];
}

int count_rotate() {
    int ans = 100;
    if (T == O) return 0;
    map <string, int> Data;
    queue <pair <string, int>> QN, QX;

    // O xuôi lên T, hỏi T xuôi lên O ?
    // => bfs(T xuôi lên O) + bfs(O ngược về T)
    QX.push({ T, 0 }); // từ T quay xuôi lên O
    QN.push({ O, 0 }); // từ O quay ngược về T

    while (QX.size()) {
        string T1 = QX.front().first, T2 = T1;
        int cnt = QX.front().second;
        QX.pop();

        Forward(0, T1);
        Forward(1, T2);
        if (Data[T1] == 0) Data[T1] = cnt + 1;
        if (Data[T2] == 0) Data[T2] = cnt + 1;
        QX.push({ T1, cnt + 1 }), QX.push({ T2, cnt + 1 });
        if (cnt + 1 == 14) break;
    }

    while (QN.size()) {
        string O1 = QN.front().first, O2 = O1;
        int cnt = QN.front().second;
        QN.pop();

        if (Data[O1] > 0) ans = min(ans, Data[O1] + cnt);
        Backward(0, O1);
        Backward(1, O2);
        if (cnt + 1 == 14) break;
        QN.push({ O1, cnt + 1 }), QN.push({ O2, cnt + 1 });
    }
    
    return ans;
}

void solution() {
    T.clear();
    for (int i = 0, a; i < 10; i++) {
        cin >> a;
        T += to_string(a);
    }
    cout << count_rotate();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}