#include <bits/stdc++.h>
using namespace std;

string reverse(string s) {
    string tmp = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        tmp.push_back(s[i]);
    }
    return tmp;
}
string x(string s, int len) {
    while (s.size() != len) s = "0" + s;
    return s;
}
string cong(string a, string b) {
    int len = max(a.size(), b.size());
    if (a.size() < len) a = x(a, len);
    if (b.size() < len) b = x(b, len);
    string tmp; int mem = 0;
    for (int i = len - 1; i >= 0; i--) {
        a[i] -= '0'; b[i] -= '0';
        tmp.push_back(((a[i] + b[i]) % 10 + mem) % 10 + '0');
        mem = (a[i] + b[i] + mem) / 10;
        if (i == 0 && mem) tmp.push_back('1');
    }
    return reverse(tmp);
}
string tru(string a, string b) {
    int len = max(a.size(), b.size()), kt = 0;
    if (a.size() < len) a = x(a, len);
    if (b.size() < len) b = x(b, len);
    if (a < b) {
        swap(a, b); kt = 1;
    }
    if (a == b) return "0";
    string tmp; int mem = 0;
    for (int i = len - 1; i >= 0; i--) {
        a[i] -= '0'; b[i] -= '0';
        if (a[i] - b[i] - mem < 0) {
            tmp.push_back(a[i] - b[i] - mem + 10 + '0'); mem = 1;
        }
        else {
            tmp.push_back(a[i] - b[i] - mem + '0'); mem = 0;
        }
    }
    while (tmp.back() == '0') tmp.pop_back();
    if (kt) tmp.push_back('-');
    return reverse(tmp);
}
string nhan(string a, string b) {
    string tmp = "0";
    if (a == "0" || b == "0") return "0";
    for (int i = b.size() - 1; i >= 0; i--) {
        if (b[i] == '0') continue;
        string res = "0";
        for (char j = '1'; j <= b[i]; j++) {
            res = cong(res, a);
        }
        for (int j = b.size() - 1; j > i; j--) {
            res = res + "0";
        }
        tmp = cong(tmp, res);
    }
    return tmp;
}
void nhan(string &str, string a, string b){
    int *res, i, j, n = a.size(), m = b.size();
    res = new int[n + m + 1];
    for(i = 0; i <= n+m; i++) res[i] = 0;
    for(i = n-1; i >= 0; i--){
        for(j = m-1; j >= 0; j--){
            res[i+j+1] += (a[i]-'0') * (b[j]-'0');
        }
    }
    for(i = n+m; i >= 0; i--){
        if(res[i] > 9){
            res[i-1] += res[i]/10;
            res[i] %= 10;
        }
    }
    for(i = 0; i < n+m; i++) str += (res[i] + '0');
    while(str[0] == '0') str.erase(str.begin());
}
main() {
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        cout << tru(a,b) << endl;
    }
}