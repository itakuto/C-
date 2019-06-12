#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
char Ban[8][8];
int moveBan[8][8],checkBan[8][8];
int rotateB,rotateC,locate1,locate2,countS,openNum;
int locateAi1,locateAi2,locateAj1,locateAj2,locateBi1,locateBi2,locateBi3,locateBj1;
int locateCi1,locateCi2,locateCi3,locateCi4,locateCj1,foundA,foundB,foundC;
void checkTreasure();
int Start(){
	char start;
	printf("宝さがしゲーム\nSでスタート　Eで終了\n");
	start=getch();
	if(start=='s'||start=='S') return 1;
	else return 0;
}
void startBanmen(){
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			printf("□");
			if(j==7) printf("\n");
		}
		if(i==7) printf("\n");
	}
}
int gameLevel(){
	int n;
	while(1){
		printf("開けるマス数：");
		scanf("%d",&n);
		if(n>0) break;
		printf("1以上の数を入力してください\n");
	}
	printf("十字キーで移動　場所決定:Enter\n");
	return n;
}
void putTreasureA(){
	int A1,A2,i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			Ban[i][j]=0;
		}
	}
	A1=7*rand()/(RAND_MAX+1)+1;
	A2=7*rand()/(RAND_MAX+1)+1;
	Ban[A1-1][A2-1]=1;
	Ban[A1-1][A2]=1;
	Ban[A1][A2-1]=1;
	Ban[A1][A2]=1;
	locateAi1=A1-1;
	locateAj1=A2-1;
	locateAi2=A1;
	locateAj2=A2;
}
int putCheck(int k,int i,int j){
	if(k==1){
		if(rotateB==1){
			if(Ban[i-1][j-1]==1||Ban[i][j-1]==1||Ban[i+1][j-1]==1) return 1;
			if(Ban[i-2][j-1]==1||Ban[i+2][j-1]==1) return 1;
			if(Ban[i-1][j-2]==1||Ban[i][j-2]==1||Ban[i+1][j-2]==1) return 1;
			if(Ban[i-1][j]==1||Ban[i][j]==1||Ban[i+1][j]==1) return 1;
		}
		else if(rotateB==2){
			if(Ban[i-1][j-1]==1||Ban[i-1][j]==1||Ban[i-1][j+1]==1) return 1;
			if(Ban[i-1][j-2]==1||Ban[i-1][j+2]==1) return 1;
			if(Ban[i-2][j-1]==1||Ban[i-2][j]==1||Ban[i-2][j+1]==1) return 1;
			if(Ban[i][j-1]==1||Ban[i][j]==1||Ban[i][j+1]==1) return 1;
		}
	}
	else if(k==2){
		if(rotateC==1){
			if(Ban[i-1][j-1]==1||Ban[i][j-1]==1||Ban[i+1][j-1]==1||Ban[i+2][j-1]==1) return 1;
			if(Ban[i-2][j-1]==1||Ban[i+3][j-1]==1) return 1;
			if(Ban[i-1][j-2]==1||Ban[i][j-2]==1||Ban[i+1][j-2]==1||Ban[i+2][j-2]==1) return 1;
			if(Ban[i-1][j]==1||Ban[i][j]==1||Ban[i+1][j]==1||Ban[i+2][j]==1) return 1;
		}
		else if(rotateC==2){
			if(Ban[i-1][j-1]==1||Ban[i-1][j]==1||Ban[i-1][j+1]==1||Ban[i-1][j+2]==1) return 1;
			if(Ban[i-1][j-2]==1||Ban[i-1][j+3]==1) return 1;
			if(Ban[i-2][j-1]==1||Ban[i-2][j]==1||Ban[i-2][j+1]==1||Ban[i-2][j+2]) return 1;
			if(Ban[i][j-1]==1||Ban[i][j]==1||Ban[i][j+1]==1||Ban[i][j+2]==1) return 1;
		}
	}
	return 0;
}
void putTreasureB(){
	int B1,B2;
	rotateB=2*rand()/(RAND_MAX+1)+1;
	if(rotateB==1){
		while(1){
			B1=6*rand()/(RAND_MAX+1)+1;
			B2=8*rand()/(RAND_MAX+1)+1;
			if(putCheck(1,B1,B2)==1) continue;
			else if(putCheck(1,B1,B2)==0){
				Ban[B1-1][B2-1]=1;
				Ban[B1][B2-1]=1;
				Ban[B1+1][B2-1]=1;
				locateBi1=B1-1;
				locateBi2=B1;
				locateBi3=B1+1;
				locateBj1=B2-1;
				break;
			}
		}
	}
	else if(rotateB==2){
		while(1){
			B1=8*rand()/(RAND_MAX+1)+1;
			B2=6*rand()/(RAND_MAX+1)+1;
			if(putCheck(1,B1,B2)==1) continue;
			else if(putCheck(1,B1,B2)==0){
				Ban[B1-1][B2-1]=1;
				Ban[B1-1][B2]=1;
				Ban[B1-1][B2+1]=1;
				locateBj1=B1-1;
				locateBi1=B2-1;
				locateBi2=B2;
				locateBi3=B2+1;
				break;
			}
		}
	}
}
void putTreasureC(){
		int C1,C2;
	rotateC=2*rand()/(RAND_MAX+1)+1;
	if(rotateC==1){
		while(1){
			C1=5*rand()/(RAND_MAX+1)+1;
			C2=8*rand()/(RAND_MAX+1)+1;
			if(putCheck(2,C1,C2)==1) continue;
			else if(putCheck(2,C1,C2)==0){
				Ban[C1-1][C2-1]=1;
				Ban[C1][C2-1]=1;
				Ban[C1+1][C2-1]=1;
				Ban[C1+2][C2-1]=1;
				locateCi1=C1-1;
				locateCi2=C1;
				locateCi3=C1+1;
				locateCi4=C1+2;
				locateCj1=C2-1;
				break;
			}
		}
	}
	else if(rotateC==2){
		while(1){
			C1=8*rand()/(RAND_MAX+1)+1;
			C2=5*rand()/(RAND_MAX+1)+1;
			if(putCheck(2,C1,C2)==1) continue;
			else if(putCheck(2,C1,C2)==0){
				Ban[C1-1][C2-1]=1;
				Ban[C1-1][C2]=1;
				Ban[C1-1][C2+1]=1;
				Ban[C1-1][C2+2]=1;
				locateCj1=C1-1;
				locateCi1=C2-1;
				locateCi2=C2;
				locateCi3=C2+1;
				locateCi4=C2+2;
				break;
			}
		}
	}
}
void resetBanmen(){
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			moveBan[i][j]=0;
			checkBan[i][j]=5;
		}
	}
}
void displayBanmen(){
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(moveBan[i][j]==1) printf("■");
			else if(checkBan[i][j]==0) printf("○");
			else if(checkBan[i][j]==1) printf("×");
			else if(checkBan[i][j]==2) printf("Ａ");
			else if(checkBan[i][j]==3) printf("Ｂ");
			else if(checkBan[i][j]==4) printf("Ｃ"); 
			else if(moveBan[i][j]==0) printf("□");
			if(j==7) printf("\n");
		}
		if(i==7) printf("\n");
	}
}
int checkTreasure1(int locate1,int locate2){
	if(locate1<0||locate2<0||locate1>7||locate2>7) return 0;
	if(Ban[locate1][locate2]==1) return 1;
	else if(Ban[locate1][locate2]==0) return 0;
}
void checkTreasure2(int locate1,int locate2){
	if(locate1<0||locate2<0||locate1>7||locate2>7) return;
	if((countS>openNum)||(foundA==1&&foundB==1&&foundC==1)) return;
	if(Ban[locate1][locate2]==1){
		if(checkBan[locate1][locate2]==2||checkBan[locate1][locate2]==3||checkBan[locate1][locate2]==4){
			return;
		}
		checkBan[locate1][locate2]=0;
		if(checkBan[locateAi1][locateAj1]==0&&checkBan[locateAi1][locateAj2]==0&&checkBan[locateAi2][locateAj1]==0&&checkBan[locateAi2][locateAj2]==0){
			checkBan[locateAi1][locateAj1]=2;
			checkBan[locateAi1][locateAj2]=2;
			checkBan[locateAi2][locateAj1]=2;
			checkBan[locateAi2][locateAj2]=2;
			foundA++;
		}
		if(rotateB==1){
			if(checkBan[locateBi1][locateBj1]==0&&checkBan[locateBi2][locateBj1]==0&&checkBan[locateBi3][locateBj1]==0){
				checkBan[locateBi1][locateBj1]=3;
				checkBan[locateBi2][locateBj1]=3;
				checkBan[locateBi3][locateBj1]=3;
				foundB++;
			}
		}
		else if(rotateB==2){
			if(checkBan[locateBj1][locateBi1]==0&&checkBan[locateBj1][locateBi2]==0&&checkBan[locateBj1][locateBi3]==0){
				checkBan[locateBj1][locateBi1]=3;
				checkBan[locateBj1][locateBi2]=3;
				checkBan[locateBj1][locateBi3]=3;
				foundB++;
			}
		}
		if(rotateC==1){
			if(checkBan[locateCi1][locateCj1]==0&&checkBan[locateCi2][locateCj1]==0&&checkBan[locateCi3][locateCj1]==0&&checkBan[locateCi4][locateCj1]==0){
				checkBan[locateCi1][locateCj1]=4;
				checkBan[locateCi2][locateCj1]=4;
				checkBan[locateCi3][locateCj1]=4;
				checkBan[locateCi4][locateCj1]=4;
				foundC++;
			}
		}
		else if(rotateC==2){
			if(checkBan[locateCj1][locateCi1]==0&&checkBan[locateCj1][locateCi2]==0&&checkBan[locateCj1][locateCi3]==0&&checkBan[locateCj1][locateCi4]==0){
				checkBan[locateCj1][locateCi1]=4;
				checkBan[locateCj1][locateCi2]=4;
				checkBan[locateCj1][locateCi3]=4;
				checkBan[locateCj1][locateCi4]=4;
				foundC++;
			}
		}
	}
	else if(Ban[locate1][locate2]==0){
		checkBan[locate1][locate2]=1;
	}
	countS++;
}
void searchTreasure(){
	int i,j,a,b,c,d;
	a=b=c=d=0;
	while((countS<=openNum)&&(foundA==0||foundB==0||foundC==0)){
		for(i=0;i<8;i+=2){
			for(j=0;j<8;j+=2){
				checkTreasure2(i,j);
			}
		}
		for(i=0;i<8;i+=2){
			for(j=0;j<8;j+=2){
				if(checkTreasure1(i,j)==1&&checkTreasure1(i,j+2)==0&&checkTreasure1(i+2,j)==0){
					a=i;
					b=j;
					checkTreasure2(i,j+1);
					if(checkTreasure1(i,j+1)==1){
						checkTreasure2(i+1,j);
						if(checkTreasure1(i+1,j)==1){
							checkTreasure2(i+1,j+1);
						}
						else if(checkTreasure1(i+1,j)==0){
							checkTreasure2(i,j-1);
							if(checkTreasure1(i,j-1)==1){
								checkTreasure2(i,j+2);
							}
							else if(checkTreasure1(i,j-1)==0){
								checkTreasure2(i-1,j);
								checkTreasure2(i-1,j+1);
							}
						}
					}
					else if(checkTreasure1(i,j+1)==0){
						checkTreasure2(i,j-1);
						checkTreasure2(i+1,j);
						if(checkTreasure1(i+1,j)==1){
							checkTreasure2(i+1,j-1);
						}
						else if(checkTreasure1(i+1,j)==0){
							checkTreasure2(i-1,j);
							if(checkTreasure1(i-1,j)==1){
								checkTreasure2(i+2,j);
							}
							else if(checkTreasure1(i-1,j)==0){
								checkTreasure2(i-1,j);
								checkTreasure2(i-1,j-1);
							}
						}
					}
				}
				else if(checkTreasure1(i,j)==1&&checkTreasure1(i,j+2)==1){
					c=i;
					checkTreasure2(i,j+1);
					if(checkTreasure1(i,j+1)==0) checkTreasure2(i-1,j);
					if(checkBan[i][j]==3) break;
					checkTreasure2(i,j+3);
				}
				else if(checkTreasure1(i,j)==1&&checkTreasure1(i+2,j)==1){
					d=i;
					checkTreasure2(i+1,j);
					if(checkTreasure1(i+1,j)==0) checkTreasure2(i-1,j);
					if(checkBan[i][j]==3) break;
					checkTreasure2(i+3,j);
				}
			}
		}
		for(i=1;i<8;i+=2){
			while(1){
				if(i==a) i+=2;
				else if(i==c) i+=2;
				else break;
			}
			for(j=1;j<8;j+=2){
				while(1){
					if(j==b) j+=2;
					else if(j==d) j+=2;
					else break;
				}
				checkTreasure2(i,j);
				if(checkTreasure1(i,j)==1){
					checkTreasure2(i,j+1);
					if(checkTreasure1(i,j+1)==1){
						checkTreasure2(i,j+2);
						if(checkTreasure1(i,j+2)==0){
							checkTreasure2(i,j-1);
							checkTreasure2(i,j-2);
						}
						else if(checkTreasure1(i,j+2)==1){
							checkTreasure2(i,j+3);
						}
					}
					else if(checkTreasure1(i,j+1)==0){
						checkTreasure2(i+1,j);
						if(checkTreasure1(i+1,j)==1){
							checkTreasure2(i+2,j);
							if(checkTreasure1(i+2,j)==0){
								checkTreasure2(i-1,j);
								checkTreasure2(i-2,j);
							}
							else if(checkTreasure1(i+2,j)==1){
								checkTreasure2(i+3,j);
							}
						}
					}
				}
			}
		}
	}
}
int main(){
	int startkey,i,j=0,k=0,p=0;
	double AVE1,AVE2;
	srand(time(NULL)*12345);
	startkey=Start();
	do{
		switch(startkey){
		case 1: 
			startBanmen();
			startkey++;
			break;
		default: 
			return 0;
		}
	}while(startkey==1);
	openNum=gameLevel();
	for(i=0;i<500;i++){
		putTreasureA();
		putTreasureB();
		putTreasureC();
		resetBanmen();
		countS=0;
		foundA=foundB=foundC=0;
		searchTreasure();
		if(foundA==1||foundB==1||foundC==1) p++;
		if(foundA==1&&foundB==1&&foundC==1){
			printf("全てのお宝を発見しました！\n");
			j++;
		}
		printf("\nお宝A：");
		if(foundA==1) printf("発見成功\n");
		else printf("発見失敗\n");
		printf("お宝B：");
		if(foundB==1) printf("発見成功\n");
		else printf("発見失敗\n");
		printf("お宝C：");
		if(foundC==1) printf("発見成功\n");
		else printf("発見失敗\n");
	}
	AVE1=(double)j/500*100;
	AVE2=(double)p/500*100;
	printf("全て見つける確率＝%lf％\n1つでも見つける確率＝%lf",AVE1,AVE2);
	system("pause");
}