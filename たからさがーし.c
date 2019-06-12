#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int a[100][100],AA,BB,CC;

void output(){
    int n,m;
    printf("çs:");
    scanf("%d",&n);
    printf("óÒ:");
    scanf("%d",&m);
    if(a[n-1][m-1]==1){
        a[n-1][m-1]=2;
        printf("ìñÇΩÇËÇ‹ÇµÇΩ\n");
    }
	else if(a[n-1][m-1]==0) printf("ÇÕÇ∏ÇÍÇ‹ÇµÇΩ\n");
}
void input(){
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(a[i][j]==0||a[i][j]==1) printf("Å†");
            else if(a[i][j]==2) printf("Å°");
        }
        printf("\n");
    }
}
int main(){
    int i,j,s,t,u,w,f,g,x,z,k,n,m,p,q,r;
    int S;
	p=q=r=0;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++) a[i][j]=0;
	}
    srand(time(NULL)*12345);
	s=7*rand()/(RAND_MAX+1);
	t=7*rand()/(RAND_MAX+1);
	a[s][t]=1;
	a[s][t+1]=1;
	a[s+1][t]=1;
	a[s+1][t+1]=1;

	f=2*rand()/(RAND_MAX+1)+1;
	if(f==1){
		do{
		u=6*rand()/(RAND_MAX+1);
		w=8*rand()/(RAND_MAX+1);
		}while(a[u][w]==1||a[u+1][w]==1||a[u+2][w]==1);
		a[u][w]=a[u+1][w]=a[u+2][w]=1;
	}
	else if(f==2){
		do{
		u=8*rand()/(RAND_MAX+1);
		w=6*rand()/(RAND_MAX+1);
		}while(a[u][w]==1||a[u][w+1]==1||a[u][w+2]==1);
		a[u][w]=a[u][w+1]=a[u][w+2]=1;
	}
	g=2*rand()/(RAND_MAX+1)+1;
	if(f==1){
		if(g==1){
			do{
				x=8*rand()/(RAND_MAX+1);
				z=5*rand()/(RAND_MAX+1);
			}while(a[x][z]==1||a[x][z+1]==1||a[x][z+2]==1||a[x][z+3]==1);
			a[x][z]=a[x][z+1]=a[x][z+2]=a[x][z+3]=1;
		}
		else if(g==2){
			do{
				x=5*rand()/(RAND_MAX+1);
				z=8*rand()/(RAND_MAX+1);
			}while(a[x][z]==1||a[x+1][z]==1||a[x+2][z]==1||a[x+3][z]==1);
			a[x][z]=a[x+1][z]=a[x+2][z]=a[x+3][z]=1;
		}
	}
	else if(f==2){
		if(g==1){
			do{
				x=8*rand()/(RAND_MAX+1);
				z=5*rand()/(RAND_MAX+1);
			}while(a[x][z]==1||a[x][z+1]==1||a[x][z+2]==1||a[x][z+3]==1);
			a[x][z]=a[x][z+1]=a[x][z+2]=a[x][z+3]=1;
		}
		else if(g==2){
			do{
				x=5*rand()/(RAND_MAX+1);
				z=8*rand()/(RAND_MAX+1);
			}while(a[x][z]==1||a[x+1][z]==1||a[x+2][z]==1||a[x+3][z]==1);
			a[x][z]=a[x+1][z]=a[x+2][z]=a[x+3][z]=1;
		}
	}
	printf("âÒêî:");
    scanf("%d",&n);
    m=0;
	input();
    while(m<n&&(AA==0||BB==0||CC==0)){
		printf("écÇË%dâÒ\n",n-m);
		output();
		input();
		if(a[s][t]==2&&a[s][t+1]==2&&a[s+1][t]==2&&a[s+1][t+1]==2){
			AA=1;
			if(p==0){
					printf("Ç®ïÛAÇî≠å©ÇµÇ‹ÇµÇΩ\n");
					p++;
				}
		}
		if(f==1){
			if(a[u][w]==2&&a[u+1][w]==2&&a[u+2][w]==2){
				BB=1;
				if(q==0){
					printf("Ç®ïÛBÇî≠å©ÇµÇ‹ÇµÇΩ\n");
					q++;
				}
			}
		}
		else if(f==2){
			if(a[u][w]==2&&a[u][w+1]==2&&a[u][w+2]==2){
				BB=1;
				if(q==0){
					printf("Ç®ïÛBÇî≠å©ÇµÇ‹ÇµÇΩ\n");
					q++;
				}
			}
		}
		if(g==2){
			if(a[x][z]==2&&a[x+1][z]==2&&a[x+2][z]==2&&a[x+3][z]==2){
				CC=1;
				if(r==0){
					printf("Ç®ïÛCÇî≠å©ÇµÇ‹ÇµÇΩ\n");
					r++;
				}
			}
		}
		else if(g==1){
			if(a[x][z]==2&&a[x][z+1]==2&&a[x][z+2]==2&&a[x][z+3]==2){
				CC=1;
				if(r==0){
					printf("Ç®ïÛCÇî≠å©ÇµÇ‹ÇµÇΩ\n");
					r++;
				}
			}
		}
		m++;
    }
	if(AA==1&&BB==1&&CC==1) printf("ëSÇƒÇÃÇ®ïÛÇî≠å©ÇµÇ‹ÇµÇΩ\n");
    system("pause");
}