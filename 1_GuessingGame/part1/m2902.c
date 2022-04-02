#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void memu(){
printf("CPU Says: pick a number 1-10\n");
}
    
int main(){  
    int n,i,k;
    srand(time(NULL));
    n=rand()%10;    
    for(i = 1;i < 10; i++)
    {
       printf("CPU Says:pick a number 1-10\n");
       printf("make a guess:\n");
       scanf("%d",&k);

       if(k == n){
                 printf("you got it!\n");
                 break;
                                  }
       else 
        if(k > n)
               printf("no guess higher!\n");
        else
               printf("no guess lower!\n");
     }

printf("here are the results of your guessing abilities!");
    printf("game took you %d\n",i);

    return 0;
}
