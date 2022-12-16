#include <bits/stdc++.h>
using namespace std;
int main(){
	int r,c;
	cin >> r >> c;
	string a[r];
	for(int i=0; i<r; i++) cin >> a[i];
	int res=0;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			int kt=1;
			if(i<r-1 && a[i][j]=='#' && a[i+1][j]=='#'){
				res++; kt=0;
			}
			if(j<c-1 && a[i][j]=='#' && a[i][j+1]=='#'){
				res++; kt=0;
			}
		}
	}
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++) if(a[i][j]=='#'&&a[i+1][j]=='.'&&a[i][j+1]=='.') res++;
	cout << res;
}