#include<stdio.h>
int a[100][100],fb[100];
void taomang(int n){
	int x=0, k=0, hang = n-1, cot = n-1;
	while(x<=n/2){
		for(int i=x; i<=cot-x; i++){
			 a[x][i] = fb[k]; k++;
		}
		for(int i=1+x; i<=hang-x; i++){
			a[i][cot-x] = fb[k]; k++;
		}
		for(int i=cot-1-x; i>=x; i--){
			a[hang-x][i] = fb[k]; k++;
		}
		for(int i=hang-1-x; i>x; i--){
			a[i][x] = fb[k]; k++;
		}
		x++;
	}
}
main(){
	int n;
	scanf("%d", &n);
	fb[0]=0; fb[1]=1;
	for(int i=2; i<82; i++){
		fb[i] = fb[i-1] + fb[i-2];
	}
	taomang(n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}	
}
