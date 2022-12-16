/*
Trong 1 thao tác, anh có thể tăng hoặc giảm 1 phần tử bất kỳ trong mảng.
Tính số lần biến đổi ít nhất để trung vị của mảng bằng S.
Trung vị của 1 mảng có độ dài lẻ là giá trị của phần tử nằm chính giữa
sau khi được sắp xếp
Ví dụ: trung vị của mảng 3, 2, 3 là 3 vì nếu chúng ta sắp xếp mảng này,
chúng ta sẽ nhận được 2, 3, 3 và 3 là phần tử nằm chính giữa.
Input
Dòng đầu gồm 2 số nguyên N, S (1 ≤ N < 2.105, 1 ≤ S ≤ 109).
Dòng thứ 2 gồm N số nguyên a1, a2 ,…, an (1 ≤ ai ≤ 109).
Dữ liệu đảm bảo N luôn là số lẻ.
Output
Gồm 1 số nguyên duy nhất là kết quả của bài toán.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    int x=n-1;
    for(int i=0; i<n; i++){
        if(a[i] >= k){
            x=i-1;
            break;
        }
    }
    long long res =0;
    if(x>=n/2)
        for(int i=x; i>=n/2; i--) res += abs(k-a[i]);    
    else
        for(int i=x+1; i<=n/2; i++) res += abs(a[i]-k);
    cout << res;
}