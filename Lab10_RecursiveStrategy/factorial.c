// gcc factorial.c -o factorial
// ./factorial

#include <stdio.h>

// TODO: Implement iterative solution here
int factorial(int n){
    int i = 0;
    int fac = 1;    
    for(i = 1; i <= n; i++){
        fac = fac *  i;
    }
    return fac;
}
// TODO:Implement recursive solution here
int factorial_rec(int n){
  if (n == 0){
            return 1;
  }
    
  return factorial_rec(n-1) * n;
 
}

int main(){

  // Both of these should print the same result!
  printf("factorial(10) = %d\n",factorial(10));
  printf("factorial_rec(10) = %d\n",factorial_rec(10));



  return 0;
}
