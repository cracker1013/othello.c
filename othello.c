#include<stdio.h>
#include <stdlib.h>
#include <time.h>
     int ban[64]={};
     int change=0;
     int senkou[2]={1,2};
     int swich=0;
     int saiki=0;
int irekae(){
    int tmp=senkou[0];
    senkou[0]=senkou[1];
    senkou[1]=tmp;
}
int function(int by,int ad,int *ban,int size){
    //printf("%d=%d=%d\n",by+ad,ad,ban[by+ad]);
    if((size==1)&&((by+ad)%8==0)){
        return 0;
    }
    if((size==-1)&&((by+ad)%8==7)){
        return 0;
    }
    if((size==7)&&((by+ad)%8==7)){
        return 0;
    }if((size==-7)&&((by+ad)%8==0)){
        return 0;
    }
    if((size==9)&&((by+ad)%8==0)){
        return 0;
    }if((size==-9)&&((by+ad)%8==7)){
        return 0;
    }
    
    if(ban[by+ad]==senkou[1]){
        //puts("saiki");
        saiki=1;
        function(by,size+ad,ban,size);
        if(change==1){
           ban[by+ad]=senkou[0];
        }
    }
    //printf("%d",by);
    if(saiki==1&&ban[by+ad]==senkou[0]){
        ban[by]=senkou[0];
        //printf("変換%d\n",ban[by]);
        change=1;
        swich=1;
        
    }
   
    return 0;
}
int checkban(int by,int a,int *ban,int b){
    int tmp=8;
    function(by,tmp,ban,tmp);
    change=0;
    saiki=0;
    function(by,-tmp,ban,-tmp);
    change=0;
    saiki=0;
    tmp=1;
    function(by,tmp,ban,tmp);
    change=0;
    saiki=0;
    function(by,-tmp,ban,-tmp);
    change=0;
    saiki=0;
    
    tmp=7;
    function(by,tmp,ban,tmp);
    change=0;
    saiki=0;
    function(by,-tmp,ban,-tmp);
    change=0;
    saiki=0;
    tmp=9;
    function(by,tmp,ban,tmp);
    change=0;
    saiki=0;
    function(by,-tmp,ban,-tmp);
    change=0;
    saiki=0;


    return 0;
}


int main(void){
    //CPづくり
    unsigned int seed; seed = (unsigned int)time(NULL); 
    srand(seed);
    //ここまで
    int by=0,a=0,num1=0,num2=0,num=0;
    ban[27]=1;
    ban[28]=2;
    ban[35]=2;
    ban[36]=1;

    /*ban[7]=2;
    ban[14]=2;
    ban[21]=2;
    ban[28]=2;
    ban[35]=1;*/
    for(int j=0;j==0;){
        printf("%d,%dに置いた\n",by/8,by%8);
        if(senkou[0]==1){
            puts("白の番");
            }else{
                puts("黒の番");
            }
        puts("   0 1 2 3 4 5 6 7");
        for(int i=0;i<8;i++){
            printf("%d ",i);
            for(int k=0;k<8;k++){
                if(ban[num]==0){printf("  ");}
                if(ban[num]==1){printf(" ●");}
                if(ban[num]==2){printf(" ○");}
            num+=1;
            }
            printf("\n");
    }
    num=0;
    printf("\n");
     if(senkou[0]==2){
           do{
          by=rand();
          by=by%64;
          //printf("kokoka%d\n",by);
          if(ban[by]==0){
                 checkban(by,8,ban,8);
          }
           }while(swich==0);
           //printf("%d,%dにおいた",by/8,by%8);
        }else{
    do{
        do{
    puts("行列");scanf("%d",&num1);
        }while(num1<0||num1>77);
        by=(num1/10)*8;
        by=by+num1%10;
        /*do{
    puts("列"); scanf("%d",&num2);
        }while(num2<0||num2>7);
    by=num1*8+num2;*///もし分けて入力する場合
    if(ban[by]!=0){
        puts("retry again");
    }
    }while(ban[by]!=0);
        }
    checkban(by,8,ban,8);
    if(swich==1){
        irekae();
        swich=0;
    }
   

    }
    return 0;
}
