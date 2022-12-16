#include <bits/stdc++.h>
using namespace std;

long long uscln(long long a, long long b){
    if (b == 0) return a;
    return uscln(b, a % b);
}
long long bscnn(long long a, long long b){
    return (a * b) / uscln(a, b);
}
int main(){
    int t;
    cin >> t;
    long long x[t], y=0;
    for(int i=0; i<t; i++){
        scanf("%lld", &x[i]); y = max(y, x[i]);
    }
    long long a[100000];
    a[1] = 1; a[2] =2; a[3] = 6; a[4] =12; a[5] = 60;
    for(int i=6; i<=y; i++){
        a[i] = i;
        a[i] = bscnn(a[i], a[i-1]);
    }
    for(int i=0; i<t; i++){
        cout << a[x[i]] << endl;
    }
}
