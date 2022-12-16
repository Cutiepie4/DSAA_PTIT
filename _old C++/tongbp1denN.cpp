#include <bits/stdc++.h>
using namespace std;
string reverse(string s){
    string tmp="";
    for(int i=s.size()-1; i>=0; i--){
        tmp.push_back(s[i]);
    }
    return tmp;
}
string x(string s, int len){
    while(s.size() != len) s = "0" + s;
    return s;
}
string cong (string a, string b){
    int len = max (a.size(), b.size());
    if(a.size()<len) a = x(a,len);
    if(b.size()<len) b = x(b,len);
    string tmp; int mem=0;
    for(int i=len-1; i>=0; i--){
        a[i] -= '0'; b[i] -= '0';
        tmp.push_back(((a[i]+b[i])%10 + mem)%10 +'0');
        mem = (a[i] + b[i] + mem) / 10;
        if(i==0 && mem) tmp.push_back('1');
    }
    return reverse(tmp);
}
string nhan(string a, string b){
    string tmp = "0";
    if(a=="0" || b=="0") return "0";
    for(int i=b.size()-1; i>=0; i--){
        if(b[i]=='0') continue;
        string res = "0";
        for(char j='1'; j<=b[i]; j++)
            res = cong(res,a);
        for(int j=b.size()-1; j>i; j--)
            res = res + "0";
        tmp = cong(tmp,res);
    }
    return tmp;
}
string convert(long long x){
    string tmp="";
    while(x>0){
        int t = x % 10;
        tmp.push_back(t+'0');
        x/=10;
    }
    return reverse(tmp);
}
int main(){
    long long n;
    cin >> n;
    long long x,kt=0;
    if(n*(n+1) % 6==0){
        x = n*(n+1)/6;
        kt=1;
    }
    if(n*(2*n+1)%6==0){
        x =(n*(2*n+1))/6;
        kt=2;
    }
    if(((2*n+1)*(n+1)) % 6 ==0){
        x = ((2*n+1)*(n+1)) / 6;
        kt=3;
    }
    string xx,xxx;
    if(kt==1){
        xx = convert(x);
        xxx = convert(2*n+1);
        cout << nhan(xx,xxx);
    }
    if(kt==2){
        xx = convert(x);
        xxx = convert(n+1);
        cout << nhan(xx,xxx);
    }
    if(kt==3){
        xx = convert(x);
        xxx = convert(n);
        cout << nhan(xx,xxx);
    }
}