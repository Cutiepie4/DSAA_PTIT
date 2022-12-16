#include <iostream>
#include <vector>
using namespace std;
main(){
    int n;
    while(1){
        cin >> n;
        if(n==0) break;
        vector<int>v(1,n);
        while(v.back() != 1){
            if(n % 2 ==0){
                n = n/2;
                v.push_back(n);
            }
            else{
                n = n * 3 + 1;
                v.push_back(n);
            }
        }
        cout << v.size() << endl;
    }
}