/*
Đi chợ về, mẹ mua một gói kẹo cho anh em Tèo.
Mẹ bảo Tèo rằng đợi các em đi học về thì hãy chia, nhưng Tèo không nghe,
cứ đòi ăn trước. Tèo chia đều kẹo cho tất cả anh em, nếu như chia không 
đều thì các phần nhiều hơn (nhiều hơn các phần còn lại 1 cái) sẽ dành cho những đứa bé hơn. Là anh cả nên Tèo chỉ lấy phần nhỏ nhất.

Khi lũ trẻ đi học về, chúng nhận phần của mình, nhưng nghi ngờ anh Tèo là
người lấy phần nhiều nhất, vì vậy chúng đem đi hỏi mẹ xem gói kẹo ban đầu
có tất cả bao nhiêu cái?

Các bạn hãy tính toán xem số lượng kẹo có thể có ban đầu nhỏ nhất và
lớn nhất là bao nhiêu?

Input
Gồm 2 số nguyên n (2 <= n <= 15) và k (n <= k <= 100) lần lượt là những
đứa trẻ trong gia đình của Tèo và số kẹo còn lại sau khi Tèo đã ăn hết phần của mình.

Output
In ra 2 giá trị số kẹo nhỏ nhất và lớn nhất có thể có ban đầu.
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int mem, candy;
    cin >> mem >> candy;
    int resbro, res1child, resfull, resless;
    if(candy % (mem-1) == 0){
        res1child = candy / (mem-1);
        resfull = res1child * mem;
        resless = resfull - 1;
    }
    else{
        resbro = candy / (mem-1);
        resfull = candy + resbro;
        resless = resfull;
    }
    cout << resless << " " << resfull;
}