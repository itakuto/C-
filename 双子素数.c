#include<stdio.h>
#include<stdlib.h>
int main(){
	int num,a,i=2,num2,num3;
	printf("���肷�鐔�l����͂��Ă��������B\n");
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
	printf("%d,%d�͑f���ł��B\n",num2,num3);
	system("pause");
}