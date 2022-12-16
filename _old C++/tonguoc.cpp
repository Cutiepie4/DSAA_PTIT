#include <stdio.h>
#include <math.h>
 
int ktcp (long long n) {
    long long x = sqrt (n);
    if (x*x==n) return 1;
    else return 0;
}
 
long long sumdiv (long long n) {
    long long sum = 0;
    for (long i=1; i<sqrt (n); i++) {
        if (n%i==0) {
            sum+=i;
            sum+=(n/i);
        }
    }
    if (ktcp (n)==1) sum+=sqrt(n);
    return sum;
}
 
int main () {
    int t;
    scanf ("%d", &t);
    long long n;
    for (int i=1; i<=t; i++) {
        scanf ("%lld", &n);
        long long sum = sumdiv (n);
        printf ("%lld\n", sum);
    }
   
    return 0;
}
