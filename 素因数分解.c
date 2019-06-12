#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int a,b,c;
	scanf("%d",&a);
	scanf("%d",&b);
	while(1){
		c=a%b;
		if(c==0)break;
		a=b;
		b=c;
		}
	printf("%d",b);
	system("pause");
}