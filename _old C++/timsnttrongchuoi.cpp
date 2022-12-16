/* 
Cho một xâu các chữ số, nhiệm vụ của bạn là tìm số nguyên tố lớn nhất
(gồm các chữ số liên tiếp nhau) xuất hiện trong xâu. Các số nguyên tố trong đoạn 2 đến 100 000.

Input
Mỗi dòng chứa 1 xâu (tối đa 255 số).

Kết thúc bởi dòng chứa số 0 (không cần xử lý)

Output
Với mỗi xâu, in ra trên 1 dòng kết quả
*/
#include <bits/stdc++.h>
using namespace std;
int main (){
    vector<int> check(100000, 1);
    vector<string> snt;
    check[0] = check[1] = 0;
    for(int i=2; i*i<=100000; i++){
        if(check[i]){
            for(int j=i*i; j<=100000; j+=i){
                check[j]=0;
            }
        }
    }
    for(int i=2; i<check.size(); i++){
        if(check[i]) snt.push_back(to_string(i));
    }
    while(1){
        string s;
        cin >> s;
        if(s=="0") break;
        for(int i=snt.size()-1; i>=0; i--){
            if(s.find(snt[i])!=-1){
                cout << snt[i] << endl; break;
            }
        }
    }
}