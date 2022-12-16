#include <bits/stdc++.h>
using namespace std;

long long greatDivisor(long long a, long long b) {
    if (b == 0) return a;
    return greatDivisor(b, a % b);
}

class Fraction {
public:
    long long num, deno;
    Fraction() {
        num = 1;
        deno = 1;
    }
    
    Fraction(long long a, long long b) {
        num = a;
        deno = b;
    }

    double getval() {
        return (double)num / deno;
    }

    void display() {
        cout << num << "/" << deno;
    }

    void resize() {
        long long x = greatDivisor(num, deno);
        num /= x;
        deno /= x;
    }

    friend Fraction operator-(Fraction& a, Fraction& b) {
        Fraction c;
        c.deno = a.deno * b.deno;
        c.num = a.num * b.deno - b.num * a.deno;
        c.resize();
        return c;
    }
};

long long x = 2;

void process(Fraction a) {
    if (a.num == 1) {
        a.display();
        return;
    }
    for (long long i = x; i <= INT64_MAX; i++) {
        if (a.getval() > (double)1 / i) {
            Fraction tmp(1, i);
            x = i + 1;
            tmp.display();
            cout << " + ";
            a = a - tmp;
            break;
        }
    }
    return process(a);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Fraction a;
        x = 2;
        cin >> a.num >> a.deno;
        a.resize();
        process(a);
        cout << endl;
    }
}

// code 2

#include <bits/stdc++.h>
using namespace std;
void printEgyptian(long long nr, long long dr) {
    // If numerator divides denominator, then simple division
    // makes the fraction in 1/n form
    if (dr % nr == 0) {
        cout << "1/" << dr / nr;
        return;
    }
    // We reach here dr > nr and dr%nr is non-zero
    // Find ceiling of dr/nr and print it as first
    // fraction
    int n = dr / nr + 1;
    cout << "1/" << n << " + ";
    // Recur for remaining part
    printEgyptian(nr * n - dr, dr * n);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        printEgyptian(a, b);
        cout << endl;
    }
}