// Modify this file for your assignment
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include <signal.h>


#define MAX_LINE_SIZE  80
#define MAX_PATH_LEN 1000

char *cmd_array[MAX_LINE_SIZE];
int cmd_i;
int pipe_fd[2];

void sigint_handler(int sig){
     write(1,"Terminating through signal handler\n",35);
     exit(0);
}
void readcmd(){
	
	int i = 0;
	char string1[MAX_LINE_SIZE];
	char* string2;
	memset(cmd_array,0,MAX_LINE_SIZE);
	fgets(string1,MAX_LINE_SIZE,stdin);
	if(string1[strlen(string1)-1]=='\n'){
		string1[strlen(string1)-1]='\0';
	}
	string2 = strtok(string1," ");
        while(string2 != NULL){
			cmd_array[i]=(char*)malloc(sizeof(*string2));
			strcpy(cmd_array[i++],string2);
			string2 = strtok(NULL," ");
	}
	cmd_i=i;
}

void pwd(){
	char path_name[MAX_PATH_LEN];
	if(getcwd(path_name,MAX_PATH_LEN)){
		printf("%s\n",path_name);
	}
	else{
		perror("myshell: getcwd");
		exit(1);
	}
}

void cd(){
    char s[100];
    printf("%s\n",getcwd(s,100));
    chdir("..");
    printf("%s\n",getcwd(s,100));
}

void echo(){
	for(int i=1;i<cmd_i;i++){
		printf("%s",*(cmd_array+i));
		if(i==cmd_i-1){
			break;
		}
		printf(" ");
	}
	printf("\n");
}

int is_internal_cmd(){
   if(cmd_array[0]==NULL){
           return 0;
   }
   else if(strcmp(cmd_array[0],"exit")==0){
        exit(0); 
   }
   else if(strcmp(cmd_array[0],"clear")==0){   
	printf("\033[2J");
        printf("\033[H");
	return 1;
  }
  else if(strcmp(cmd_array[0],"pwd")==0){
	pwd();
	return 1;
  }
  else if(strcmp(cmd_array[0],"cd")==0){
	cd();
	return 1;
  }
  else if(strcmp(cmd_array[0],"echo")==0){
        echo();
        return 1;  
  }
}

void is_external_cmd(int pos){
	int res;
	res=execvp(cmd_array[pos],cmd_array+pos);
	if(res<0){
		printf("command not found\n");
	}	
}

int is_pipe(){   
	for(int i=1;i<cmd_i;i++){
		if(cmd_array[i]!=NULL&&strcmp(cmd_array[i],"|")==0){
			cmd_array[i]=NULL;
			return i+1;
		}
	}
	return 0; 
}

void do_pipe(int pos){
	int pid;
	if(pos==0){
		return;
	}
	if((pid=fork())==0){
		close(pipe_fd[1]);
		dup2(pipe_fd[0],0);
		is_external_cmd(pos);
	}
	else{
		close(pipe_fd[1]);
		waitpid(pid,NULL,0);
	}	
}


int main(){
    pid_t pid;
    printf("\e[35m welcome to my shell\e[0m\n");
    printf("\e[35m Made by Jing Luo\e[0m\n");
    printf("\e[35m Have a good time with it!\e[0m\n");
    int pos_pipe;   
    while(1){
       printf("mini-shell>");
       readcmd();      
       pid = fork();
              
       if(is_internal_cmd()){
          continue;  
       }
       if(pos_pipe=is_pipe()){
		pipe(pipe_fd);
       }
       if(pid == 0){
             int pid_child = getpid();  
             signal(SIGINT,SIG_DFL);
 	     if(pos_pipe){
		close(pipe_fd[0]);
	        dup2(pipe_fd[1],1);
             }      
             is_external_cmd(0);          
             break;
       }else if(pid > 0){
       
             signal(SIGTSTP,SIG_IGN);
             waitpid(pid,NULL,WUNTRACED);   

       }
       do_pipe(pos_pipe); 

       if(pid < 0){
            printf("Failed");
            exit(1);
       }

     }
 
   return 0;
}
