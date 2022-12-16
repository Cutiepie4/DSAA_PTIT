#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[1205], posmax, posmin;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            if(a[i]==1) posmin = i;
            if(a[i]==n) posmax = i;
        }
        int x = max(posmax, posmin);
        int y = min(posmin, posmax);
        int res = min(min(n-y+1, x), n-(x-y-1));
        cout << res << endl;
    }
}