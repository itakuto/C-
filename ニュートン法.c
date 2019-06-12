#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double dF(double (*F)(double),double x){
	return 2*x+sin(x);
}
double F3(double x){
	return x*x-cos(x);
}
double newton(double (*F)(double),double x){
	double y,EPS=1e-8;
	do{
		y=x-(*F)(x)/dF(F,x);
		printf("%lf,%le\n",y,fabs(y-x));
		if(EPS>y-x&&y-x>-EPS) break;
		x=y;
	} while(1);
	return y;
}
int main(){
	double z;
	z=newton(F3,-1);
	printf("%lf",z);
	system("pause");
}
	