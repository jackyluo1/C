// Take a look at some of the previous examples to create your own program!
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    int fd[2];
    pipe(fd);
   
    char* myls[3];
    myls[0]="ls";
    myls[1]="./";
    myls[2]=NULL;
     

    char* myecho[3];
    myecho[0]="echo";
    myecho[1]="texting\n";
    myecho[2]=NULL;
 
    char* mynl[3];
    mynl[0]="nl";
    mynl[1]="exmple6.c";
    mynl[2]=NULL;



    int child_status;
    pid_t pid,pid2,pid3;
   

    if(pid = fork() != 0){
        if(pid2 = fork() == 0){
              
         close(STDOUT_FILENO);
         dup2((fd[1]),STDOUT_FILENO);
         dprintf(fd[1],"ls command from child2\n");         

         close(fd[1]);
         close(fd[0]);

	 execvp(myls[0],myls);
                 
         }else{
               wait(NULL);
            }	
      
        if(pid3= fork()==0){
          close(STDOUT_FILENO);
          dup2((fd[1]),STDOUT_FILENO);
          dprintf(fd[1],"nl command from child3\n");

          close(fd[1]);
          close(fd[0]);
          execvp(mynl[0],mynl);
          }else{
             wait(NULL);
          }
    }

    
    if(pid=fork() == 0){
        
        close(STDOUT_FILENO);
        dup2((fd[1]),STDOUT_FILENO);
        dprintf(fd[1],"echo from child1\n");         

        close(fd[1]);
        close(fd[0]);

	execvp(myecho[0],myecho);
            
        
        }else{
        
        
        wait(NULL);
        close(STDIN_FILENO);
        dup2(fd[0],0);
        close(fd[1]); 
        }


     char c;
     while(read(STDIN_FILENO,&c,1)>0){
           write(STDOUT_FILENO,&c,1);
     }  
            
       
     
	
    return 0;
}
