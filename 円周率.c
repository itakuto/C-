#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int main(){
    double u,v,k,SUM=0,SUMpai,pai,Hensa,S=0,paiave;
    int N=1000,l;
    srand(time(NULL)*12345);
    for(l=0;l<100;l++){
        for(k=0;k<N;k++){
            SUMpai=0;
            S=0;
            pai=0;
        u=rand()/(RAND_MAX+1.0);
        v=rand()/(RAND_MAX+1.0);
        if(u*u+v*v<=1){
            SUM++;
        }
        }
        pai=4*SUM/N;
    SUMpai=SUMpai+pai;
    S=S+pai*pai;
    }
    paiave=SUMpai/100;
    Hensa=pow((S/100-paiave*paiave),0.5);
    printf("%lf %lf",paiave,Hensa);
    system("pause");
}