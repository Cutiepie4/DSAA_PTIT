#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <int>>
#define vt vector <int>
#define matrixl vector <vector <ll>>
#define vtl vector <ll>
const ll MOD = 1e9 + 7;

struct SoPhuc {
    int thuc, ao;
};

SoPhuc add(SoPhuc a, SoPhuc b) {
    SoPhuc c;
    c.thuc = a.thuc + b.thuc;
    c.ao = a.ao + b.ao;
    return c;
}

SoPhuc binh_phuong_tong(SoPhuc a, SoPhuc b) {
    SoPhuc c, d;
    c.thuc = a.thuc + b.thuc;
    c.ao = a.ao + b.ao;
    d.thuc = c.thuc * c.thuc - c.ao * c.ao;
    d.ao = c.thuc * c.ao + c.ao * c.thuc;
    return d;
}

void hien_thi(SoPhuc a) {
    cout << a.thuc << " + " << a.ao << "i";
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        SoPhuc A, B;
        cin >> A.thuc >> A.ao >> B.thuc >> B.ao;
        SoPhuc C = binh_phuong_tong(A, B);
        hien_thi(C);
        cout << endl;
    }
    return 0;
}