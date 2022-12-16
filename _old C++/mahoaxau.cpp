/*
Xâu mã hóa chỉ lưu lại các kí tự chữ cái xuất hiện đầu tiên.
Nói cách khác, các kí tự nào xuất hiện > 1 lần trở lên, sẽ bị xóa bỏ,
chỉ giữ lại kí tự đầu tiên.
Giá trị mật mã của xâu được tính bằng tổng số lần xuất hiện của các kí
tự có tần suất > 1 lần.
Các bạn hãy cùng Tí giải quyết bài toán này nhé!
Input
Dòng đầu tiên gồm số lượng test T (T <= 100).
T dòng tiếp theo, mỗi dòng gồm nhiều chuỗi các kí tự, có tổng độ dài
không vượt quá 10^5.
Các kí tự là chữ cái in hoa hoặc chữ cái thường.
Output
Với mỗi test, in ra trên dòng số các giá trị mật mã của xâu, 
và xâu đó sau khi được mã hóa.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        char a[100005]="";
        scanf("\n");
        gets(a);
        int xx=0, x[200]={0};
        char res[10005]="";
        for(int i=0; i<strlen(a); i++){
            int ck=1;
            if(a[i]==' ') continue;
            a[i] = tolower(a[i]);
            x[a[i]]++;
            for(int j=0; j<strlen(res); j++){
                if(res[j]==a[i]){
                    ck=0; break;
                }
            }
            if(ck) res[xx++] = a[i];
        }
        res[xx]='\0';
        int result = 0;
        for(char i = 'a'; i<= 'z'; i++){
            if(x[i]>1) result += x[i];
        }
        printf("%d %s\n", result, res);
    }
}
