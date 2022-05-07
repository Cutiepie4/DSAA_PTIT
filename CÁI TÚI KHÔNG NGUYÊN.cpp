/*
Một trong những bài toán kinh điển của lý thuyết tổ hợp là Bài toán cái túi. Bài toán được phát biểu như sau: Một nhà thám hiểm cần đem theo một cái túi trọng lượng không quá W. Có N đồ vật cần đem theo. Đồ vật thứ i có trọng lượng A[i], có giá trị sử dụng C[i]. Nhiệm vụ của bạn là hãy tìm cách đưa đồ vật vào túi cho nhà thám hiểm sao cho tổng giá trị sử dụng các đồ vật trong túi là lớn nhất. Giả thiết với mỗi vật dụng, ta có thể chia nhỏ chúng ra thành nhiều phần khác nhau (Fraction Knapsack).

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào hai số N, W tương ứng với số lượng đồ vật và trọng lượng túi; phần thứ 2 đưa vào 2*N số tương ứng với trọng lượng đồ vật A[i] và giá trị sử dụng C[i] của mỗi đồ vật.
T, N, W, A[i], C[i]  thỏa mãn ràng buộc: 1≤T≤100;  1≤N, W≤100; 1≤A[i], C[i]≤100.
Output:

Đưa ra kết quả mỗi test theo từng dòng, in ra 2 chữ số sau dấu phảy.
Ví dụ:

Input
2
3 50
60 10
100 20
120 30
2 50
60 10
100 20

Output
240.00
160.00
*/
#include <bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>

struct f {
    pair <float, float> p;
    float ratio;
};

int cmp(f& a, f& b) {
    if (a.ratio > b.ratio) return 1;
    return 0;
}

int n;
float W;
vector <f> D;

void prs() {
    sort(D.begin(), D.end(), cmp);
    float ans = 0;
    for (int i = 0; i < n; i++) {
        if (W >= D[i].p.first) {
            W -= D[i].p.first;
            ans += D[i].p.second;
        }
        else {
            ans += W * D[i].p.second / D[i].p.first;
            cout << setprecision(2) << fixed << ans << endl;
            return;
        }
    }
    cout << setprecision(2) << fixed << ans << endl;
}

void solution() {
    cin >> n >> W;
    D = vector <f>(n);
    for (int i = 0; i < n; i++) {
        cin >> D[i].p.second >> D[i].p.first;
        D[i].ratio = D[i].p.second / D[i].p.first;
    }
    prs();
}

int main() {
    faster();
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}