/*
Luka lái xe trên một đoạn đường thẳng,
có rất nhiều đèn giao thông trên đoạn đường này.
Khi Luka bắt đầu chuyển động từ vị trí xuất phát thì tất cả các đèn giao thông
đều hiện thỉ màu đỏ và bắt đầu chu kì.
Luka đi một đơn vị đường hết 1s. Nhiệm vụ của các bạn là hãy tính xem Luka cần
bao nhiêu thời gian để đi hết quãng đường này?
Input
Dòng đầu tiên gồm 2 số N và L là số đèn giao thông trên đường và chiều dài quãng
đường. (1 <= N <= 100, 1 <= L <= 1000).
N dòng tiếp theo, mỗi dòng gồm 3 số D, R, G là khoảng cách từ điểm xuất phát tới
đèn giao thông đó, số giây đèn đỏ và số giây đèn xanh. (1 <= D < L, 1 <=  R <= 100,
1 <= G <= 100).
Các đèn giao thông sẽ được sắp xếp theo khoảng cách tăng dần, không có 2 đèn nào
ở cùng 1 vị trí.
Output
Thời gian mà Luka cần để hoàn thành hết quãng đường đó.
*/
#include <bits/stdc++.h>
using namespace std;
struct data{
	int distance, red, green;
};
int main(){
	int light, road;
	cin >> light >> road;
	struct data x[1009];
	for(int i=0; i<light; i++) cin >> x[i].distance >> x[i].red >> x[i].green;
	int res = road;
	for(int i=0; i<light; i++){
		while(1){
			if(x[i].distance >= x[i].red) x[i].distance -= x[i].red;
			else{
				int xxx=x[i].red - x[i].distance;
				res += xxx;
				for(int j=i+1; j<light; j++) x[j].distance += xxx;
				break;
			}
			if(x[i].distance < x[i].green) break;
			else x[i].distance -= x[i].green;
		}
	}
	cout << res;
}