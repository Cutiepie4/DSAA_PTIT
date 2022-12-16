#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793238
struct canh{
	double c1, c2;
}a[3];
main(){
	int t;
	scanf("%d", &t);
	while(t--){
		for(int i=0; i<3 ; i++){
			scanf("%lf %lf", &a[i].c1, &a[i].c2);
		}
		double a01=sqrt((a[0].c1-a[1].c1)*(a[0].c1-a[1].c1)+(a[0].c2-a[1].c2)*(a[0].c2-a[1].c2));
		double a12=sqrt((a[1].c1-a[2].c1)*(a[1].c1-a[2].c1)+(a[1].c2-a[2].c2)*(a[1].c2-a[2].c2));
		double a20=sqrt((a[2].c1-a[0].c1)*(a[2].c1-a[0].c1)+(a[2].c2-a[0].c2)*(a[2].c2-a[0].c2));
		if(a01+a12<=a20||a01+a20<=a12||a12+a20<=a01){
			printf("INVALID\n"); continue;
		}
		double P=(a01+a12+a20)/2;
		double S=sqrt(P*(P-a01)*(P-a12)*(P-a20));
		double R=(a01*a12*a20)/(4*S);
		double dt=PI*R*R;
		printf("%.3lf\n", dt);
	}
}

