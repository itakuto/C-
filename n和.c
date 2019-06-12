#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int k,n,S;
	scanf("%d",&n);
	S=0;
	k=1;
	while(k<=n){
		S+=k;
		k+=1;
	}
	printf("%d",S);
	system("pause");
}