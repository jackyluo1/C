#include <stdio.h>
#include <string.h>

char *left(char *dst,char *src,int n){
	char *p=src;
	char *q=dst;
	int len=strlen(src);
	if(n>len) n=len;
	while(n--) *(q++)=*(p++);
	*(q++)='\0';
	return dst;
}

int main(int argc , char ** argv)
{
        FILE * input = fopen(argv[1],"r");
        FILE * output = fopen("output.txt", "w");
        char s[100];
        char d[4] = {0};
        if(argc > 1) {
                if(input != NULL) {
                        fgets(s , 100 , input);
                        while(! feof(input)) {
                                s[strlen(s) - 1] = '\0' ; 
                                printf("%s\n" , s);
                                fgets(s , 100 , input);
                                left(d,s,4);                 

                                int count = 0;
                                int count1 = 0;
                                int count2 = 0;
                                for(int i = 0; i < argc; i++){
                                  for(int j = 0; j < 9; j++){
                                  
                                   if(strcmp(d,"addq") == 0){
                                      count++;
                                     printf("ADD %d\n",count);
                                   }

                                   if(strcmp(d,"subq") == 0){
                                      count++;
                                      printf("SUB %d\n",count);
                                   }

                                   if(strcmp(d,"mulq") == 0){
                                      count++;
                                      count1 = count*2;
                                      printf("MUL %d\n",count);
                                   }

                                   if(strcmp(d,"divq") == 0){
                                      count++;
                                      printf("DIV %d\n",count);
                                      count2 = count*4;
                                   }
                                   if(strcmp(d,"movq") == 0){
                                      count++;
                                      printf("MOV %d\n",count);
                                   }
                                   if(strcmp(d,"leaq") == 0){
                                      count++;
                                      printf("LEA %d\n",count);
                                   }
                                   if(strcmp(s,"push") == 0){
                                      count++;
                                      printf("PUSH %d\n",count);
                                   }
                                   if(strcmp(s,"popq") == 0){
                                      count++;
                                      printf("POP  %d\n",count);
                                   }
                                   if(strcmp(s,"setq") == 0){
                                      count++;
                                      printf("SET  %d\n",count);
                                   }

                                 }             
                                }
                                printf("Total Instructions = %d\n",count);
                                printf("Total Cycles = %d\n",count+count1+count2);
                                
                        }



                        fclose(input);
                        fclose(output);
                } else {
                        fprintf(stderr , "\n");
                        fprintf(stderr , "Failed to open %s\n" , argv[1]) ;
                        fprintf(stderr , "\n");
                }
        } else {
                fprintf(stderr , "\n");
                fprintf(stderr , "Usage : %s <file>\n" , argv[0]);
                fprintf(stderr , "\n");
        }
}
