#include<stdio.h>
#include<stdlib.h>
int main(){
	int num,a,i=2,num2,num3;
	printf("判定する数値を入力してください。\n");
	scanf("%d",&num);

	while(i<num){
		a = num % i;
		if(a == 0){
			num+=1;
			i+=1;
		}
		else break;
	}
	num2+=2;
	while(i<num){
		a = num % i;
		if(a == 0){
			num+=1;
			i+=1;
		}
		else break;
	}
	num3=num;
	printf("%d,%dは素数です。\n",num2,num3);
	system("pause");
}