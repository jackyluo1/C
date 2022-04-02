#include <stdio.h>

int mian(){

//CPU Says: Pick a number 1-10
    int x;
        for(x = 0; x <10; x = x+1){printf("Make a guess:%d\n",x);
    }  
//Game 0
   int guesses[8];
   if (x == 1){printf("No guess higher!",guesses[1]);}
   if (x == 2){printf("No guess higher!",guesses[2]);}
    if (x == 3){printf("No guess higher!",guesses[3]);}
    if (x == 4){printf("No guess higher!",guesses[4]);}
    if (x == 5){printf("No guess higher!",guesses[5]);}
    if (x == 6){printf("No guess higher!",guesses[6]);}
    if (x == 7){printf("No guess higher!",guesses[7]);}
    if (x == 8){printf("You got it!"     ,guesses[8]);}
//Here are the results of your guessing ailities.
    printf("Game 0 took you %d\n guesses",guesses[8]) ;  

//Game 1
   int guesses[3];
    if (x == 5){printf("No guess higher!",guesses[1]);}
    if (x == 7){printf("No guess lower!" ,guesses[2]);}
    if (x == 6){printf("You got it!"     ,guesses[3]);}
//Here are the results of your guessing
     printf("Game 1 took you %d\n guesses");

//Game 2
   int guesses[2];
    if (x == 5){printf("No guess higher!",guesses[1]);}
    if (x == 8){printf("You got it!" ,guesses[2]);}
//Here are the results of your guessing
     printf("Game 2 took you %d\n guesses");

//Game 3
   int guesses[3];
    if (x == 5){printf("No guess higher!",guesses[1]);}
    if (x == 8){printf("No guess higher!",guesses[2]);}
    if (x == 9){printf("You got it!" ,guesses[3]) ;}
//Here are the results of your guessing
     printf("Game 3 took you %d\n guesses",guesses[3]);

//Game 4
   int guesses[4];
    if (x == 5){printf("No guess lower!",guesses[1]);}
    if (x == 3){printf("No guess lower!",guesses[2]);}
    if (x == 1){printf("No guess higher!",guesses[3]);}
    if (x == 2){printf("You got it!" ,guesses[4]);}
//Here are the results of your guessing
     printf("Game 4 took you %d\n guesses",guesses[4]);


    return o;
}



