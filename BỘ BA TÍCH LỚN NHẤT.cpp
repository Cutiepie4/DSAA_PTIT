/*
Cho mảng A chứa n (n>=3) số nguyên.

Gọi F(C) là  tích lớn nhất mà bạn có thể tạo ra bằng cách nhân 3 phần tử của mảng C.

Hay nói cách khác F(C) = max(C[i]*C[j]*C[k]) với i < j < k

Gọi A[i..j] là mảng con của A từ vị trí i đến vị trí j, ví dụ A={10,80,30,50,90} thì A[2..4] = {80,30,50}

Hãy tính mảng B với

i ≤ 2 thì B[i] =0
3 ≤ i ≤ n thì B[i] = F(A[1..i])
Input:

Dòng đầu chứa n ( 3 ≤ n ≤ 105)

Dòng thứ hai chứa n phần tử của mảng A  (-106 ≤  A[i] ≤ 106)



Output:

Ghi ra n phần tử của mảng B

 Ví dụ:

Input

Output

5

10 -10 20 -2 3
0 0 -2000 400 600
*/

#include <bits/stdc++.h>
using namespace std;

long long tich_lon_nhat(long long min1, long long min2, long long min3, long long max1, long long max2, long long max3) {
    long long nega = min1 * min2;
    long long inte = max1 * max2;
    long long temp1 = max(nega * min3, nega * max1);
    long long temp2 = max(inte * min1, inte * max3);
    return max(temp1, temp2);
}

int main() {
    long long t;
    cin >> t;
    vector<long long> a(t), subArr;
    for (long long& i : a) cin >> i;

    cout << 0 << " " << 0;
    for (long long i = 0; i < 3; i++)
        subArr.push_back(a[i]);
    sort(subArr.begin(), subArr.end());

    long long max1 = subArr[2], max2 = subArr[1], max3 = subArr[0];
    long long min1 = subArr[0], min2 = subArr[1], min3 = subArr[2];
    cout << " " << tich_lon_nhat(min1, min2, min3, max1, max2, max3);

    for (long long i = 3; i < t; i++) {
        if (a[i] > max1) {
            max3 = max2, max2 = max1, max1 = a[i];
        }
        else if (a[i] > max2) {
            max3 = max2, max2 = a[i];
        }
        else if (a[i] > max3) {
            max3 = a[i];
        }

        if (a[i] < min1) {
            min3 = min2, min2 = min1, min1 = a[i];
        }
        else if (a[i] < min2) {
            min3 = min2, min2 = a[i];
        }
        else if (a[i] < min3) {
            min3 = a[i];
        }
        cout << " " << tich_lon_nhat(min1, min2, min3, max1, max2, max3);
    }
}