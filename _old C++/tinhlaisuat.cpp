#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        double before, ir, after;
        cin >> before >> ir >> after;
        ir += 100;
        int year=0;
        while(before < after){
            before *= ir; before /= 100;
            year++;
        }
        cout << year << endl; 
    }
}