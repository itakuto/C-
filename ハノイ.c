#include<stdio.h>
#include<stdlib.h>
void hanoi(int m,int i,int j){
	if(m==1){
		printf("%d->%d, ",i,j);
		return;
	}
	hanoi(m-1,i,6-i-j);
	printf("%d->%d, ",i,j);
	hanoi(m-1,6-i-j,j);
}
int main(){
	int m,i,j;
	scanf("%d\n%d\n%d",&m,&i,&j);
	hanoi(m,i,j);
	system("pause");
}