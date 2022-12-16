/*
Bạn có 2 mảng số nguyên a và b có độ dài n
và một số nguyên k. Hai mảng được coi là bằng 
nhau nếu chúng là hoán vị của nhau. Hãy xác định 
bạn có thể làm cho 2 mảng ban đầu bằng nhau hay
không nếu bạn được chọn đúng 1 số thuộc mảng a
và cộng thêm vào đó 1 giá trị bất kỳ trong khoảng [-k, k]?

Input
Dòng đầu tiên chứa 2 số nguyên dương n và k
(1 ≤ n ≤ 105, 1 ≤ k ≤ 109).

Dòng thứ 2 chứa n số nguyên dương a1, a2, …, an
(1 ≤ ai ≤ 109).

Dòng thứ 3 chứa n số nguyên dương b1, b2, …, bn
(1 ≤ bi ≤ 109).

Output
In ra “YES” nếu có thể làm 2 mảng bằng nhau, ngược lại in ra “NO”.
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;
    cin >> n >> k;
    int a[n+1], b[n+1];
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+n);
    int z = 0, vt[n]={0}, x=0;
    for(int i=0; i<n; i++){
        int ck=1;
        for(int j=z; j<n; j++){
            if(a[i]==b[j]){
                b[j] = -1;
                z = j+1; ck=0; break;
            }
        }
        if(ck){
            vt[x++] = i;
            if(x==2){
                cout << "NO"; return 0;
            }
        }
    }
    if(x==0){
        cout << "YES"; return 0;
    }
    int vtb = 0;
    for(int i=0; i<n; i++) if(b[i] != -1) vtb = i;
    if(abs(a[vt[0]]-b[vtb]) <= k) cout << "YES"; 
    else cout << "NO";
}