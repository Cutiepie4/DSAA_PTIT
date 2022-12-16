/*
Taliyah được cho 1 mảng số nguyên không âm a1, a2, ..., an.
Đầu tiên, cô chọn một số nguyên x và cộng x vào một số phần tử của mảng (có thể không cộng vào phần tử nào),
tiếp theo trừ x vào một số phần tử khác của mảng (có thể không trừ vào phần tử nào), và không làm gì các phẩn tử còn lại.
Yasuo muốn cô làm cho tất cả phần tử của mảng bằng nhau.

Có cách chọn ra số x nào thỏa mãn yêu cầu của Yasuo không?
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n], b[3],x=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        int ck=1;
        for(int j=0; j<x; j++){
            if(a[i]==b[j]){
                ck=0; break;
            }
        }
        if(ck) b[x++] = a[i];
        if(x>3){
            cout << "NO"; return 0;
        }
    }
    if(x==1 || x==2){
        cout << "YES"; return 0;
    }
    sort(b, b+3);
    if(b[1]-b[0] != b[2]-b[1]) cout << "NO";
    else cout << "YES";
}