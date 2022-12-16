#include<stdio.h>
 
main(){
	int n;
	scanf("%d", &n);
	int a[100], dem=1;
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[j]<a[i]){
				int d=a[j];
				a[j]=a[i];
				a[i]=d;
			}
		}
		printf("Buoc %d: ", dem); dem++;
		for(int k=0; k<n; k++) printf("%d ", a[k]);
		printf("\n");
	}	
}
