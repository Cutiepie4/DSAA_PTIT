/*
Cho một hình chữ nhật kích thước 2xN (1<=N<=100)
Hãy đếm số cách lát các viên gạch nhỏ kích thước 1x2 và 2x1
vào hình trên sao cho không có phần nào của các viên gạch nhỏ thừa ra ngoài,
Scũng không có vùng diện tích nào của hình chữ nhật không được lát.

Input
Gồm nhiều test, dòng đầu ghi số lượng test T ( T<=100 ).
T dòng sau mỗi dòng ghi một số N.

Output
Ghi ra T dòng là số cách lát tương ứng.
*/
#include <iostream>
#include <string>
using namespace std;
int n;
string a[101];
string cong(string a,string b)
{
    string c="";
    int tong, nho=0;
    while(a.length()>b.length()) b='0'+b;
    while(a.length()<b.length()) a='0'+a;
    for(int i=a.length()-1; i>=0; i--)
    {
        tong=a[i]+b[i]-96+nho;
        nho=tong/10;
        c=char(tong%10+48)+c;
    }
    if(nho==1) c='1'+c;
    return c;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        a[1]='1';
        a[2]='2';
        for(int i=3; i<=n; i++)
        {
            a[i]=cong(a[i-1],a[i-2]);
        }
        cout<<a[n]<<endl;
    }
}