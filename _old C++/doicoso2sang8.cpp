#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
char xxx(string n) {
    int x = 0;
    for (int i = 0; i < n.size(); i++) {
        x += pow(2, n.size() - i - 1) * (n[i] - '0');
    }
    return x + '0';
}
int main() {
    string n, res = "";
    cin >> n;
    while (n.size() % 3 != 0) n = "0" + n;
    for (int i = 0; i < n.size(); i += 3) {
        string s = "";
        for (int j = i; j < i + 3; j++) {
            s.push_back(n[j]);
        }
        res.push_back(xxx(s));
    }
    cout << res;
}