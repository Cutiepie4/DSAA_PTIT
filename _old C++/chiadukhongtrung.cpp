#include <iostream>
#include <vector>
using namespace std;
int nt(long long n){
    if(n<2) return 0;
    for(long long i=2; i*i<=n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}
int main(){
    long long n,k;
    cin >> n >> k;
    if(k==1){
        cout << "Yes"; return 0;
    }
    long long x;
    if(nt(n)==1){
        if(n>k){
            cout << "Yes"; return 0;
        }
    }
    else{
        for(long long i=2; i*i<=n; i++){
            if(n % i == 0){
                x = i;
                break;
            }
        }
        if(k < x){
            cout << "Yes"; return 0;
        }
    }
    cout << "No"; return 0;
}