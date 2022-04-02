#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void memu(){
printf("CPU Says: pick a number 1-10\n");
}
    
int main(){  
    int n,i,k,I;
    int c = 5;
    char M[c];
    srand(time(NULL));
    while(c--){
     n=rand()%10; 

     printf("===========================\n");
     printf("CPU Says:pick a number 1-10\n");
     printf("===========================\n");  
     for(i = 1;i < 10; i++)
     {
       printf("make a guess:\n");
       scanf("%d",&k);

       if(k == n){
                 printf("you got it!\n");
                 M[c]= i;         
                 
                 break;
                                  }
       else 
        if(k > n)
               printf("no guess higher!\n");
        else
               printf("no guess lower!\n");
       }
      
     }
    printf("================================================\n");
    printf("here are the results of your guessing abilities!\n");
    printf("================================================\n");
    for(i = 0; i < 5; i++){
        printf("game %d  took you %d guesses\n",i,M[4-i]);
    }
    return 0;
}
