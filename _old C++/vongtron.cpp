#include<stdio.h>
#include<string.h>
main(){
	char s[52];
	int vt[2];
	int dem=0, dem1=0;
	scanf("%s", &s);
	for(char i='A'; i<='Z'; i++){
		int k=0;
		for(int j=0; j<52; j++){
			if(s[j]==i){
				vt[k++] = j;
				if(k>1) break;
			}
		}
		for(int x=vt[0]+1; x<vt[1]; x++)
		for(int j=0; j<52; j++){
			if(j>=vt[0]&&j<=vt[1]) continue;
			if(s[j]==s[x]) dem++;
		}
	}
	printf("%d", dem/2);
}
