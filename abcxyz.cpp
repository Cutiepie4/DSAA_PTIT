#include <bits/stdc++.h>
using namespace std;

string chuyen2to16(string s) {
    while (s.size() % 4 != 0) s.insert(s.begin(), '0');
}

int main() {
    int n;
    cin >> n;
    int M[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> M[i][j];

}