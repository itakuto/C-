#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int n,f0=0,f1=1,f2,k=2;
	scanf("%d",&n);
	printf("%d\n",f0);
	while(k<=n){
		printf("%d\n",f1);
		f2=f1+f0;
		f0=f1;
		f1=f2;
		k+=1;
	}
	system("pause");
}
