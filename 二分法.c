#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double nibun(double (*F)(double),double xa,double xb){
	double xc=(xa+xb)/2,EPS=1e-8;
	if((*F)(xa)==0) return xa;
	if((*F)(xb)==0) return xb;
	if((*F)(xc)==0) return xc;
	if(xb-xa<EPS) return (xa+xb)/2;
	if((*F)(xa)*(*F)(xc)<0) return nibun(F,xa,xc);
	else return nibun(F,xc,xb);
}
double F(double x){
	double z=cos(x)-x;
	return z;
}
int main(){
	double a,b,z;
	z=nibun(F,0,1000);
	printf("%lf",z);
	system("pause");
}