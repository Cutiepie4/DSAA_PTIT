#include <bits/stdc++.h>
using namespace std;

long long ucln(long long a, long long b) {
    if (b == 0) return a;
    return ucln(b, a % b);
}

class PhanSo {
private:
    long long num, deno;
public:
    PhanSo() {
    }
    PhanSo(long long a, long long b) {
        num = a;
        deno = b;
    }
    ~PhanSo() {
        num = 0;
        deno = 0;
    }
    void rutgon() {
        long long x = ucln(num, deno);
        num /= x;
        deno /= x;
    }
    friend istream& operator>>(istream& is, PhanSo& a) {
        is >> a.num >> a.deno;
        return is;
    }
    friend ostream& operator<<(ostream& os, PhanSo a) {
        os << a.num << "/" << a.deno;
        return os;
    }
    friend PhanSo operator+(PhanSo a, PhanSo b) {
        PhanSo c;
        c.deno = a.deno * b.deno;
        c.num = a.num * b.deno + b.num * a.deno;
        c.rutgon();
        return c;
    }
};

int main() {
    PhanSo p(1, 1), q(1, 1);
    cin >> p >> q;
    cout << p + q;
    return 0;
}