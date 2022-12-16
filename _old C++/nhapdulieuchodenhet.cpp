#include<stdio.h>
void nhap(int a[20][20],int n,int m){
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
}
void xuly(int a[20][20],int n,int m){
    int b[20][20],c[20][20],i,j,k;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            b[i][j] = a[j][i];

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            c[i][j]=0;
            for(k=0;k<m;k++)
                c[i][j] = c[i][j] + a[i][k]*b[k][j];
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d ",c[i][j]);
        printf("\n");
    }
}
main(){
    int a[20][20],n,m,i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d",&n,&m);
        nhap(a,n,m);
        printf("Test %d: \n",i);
        xuly(a,n,m);
    }

}
