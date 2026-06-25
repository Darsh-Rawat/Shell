#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
    while(1){
        char input[20];

        printf("Shell> ");
        fgets(input,sizeof(input),stdin);

        if(strcmp(input,"exit\n") == 0){
            break;
        }
        else if(strcmp(input,"help\n") == 0){
            printf("Commands:\n");
            printf("exit\n");
            printf("help\n");
            continue;
        }
        else {
            char *myargs[10];
            int i = 0;

            char *token = strtok(input," \n");

            while(token != NULL && i < 9){
                myargs[i] = token;
                i++;
                token = strtok(NULL, " \n");
            }
            myargs[i] = NULL;

            int rc = fork();

            if(rc < 0){
                perror("Fork Failed !");

            }
            else if(rc == 0){
                if(execvp(myargs[0],myargs) < 0){
                    perror("Exec Failed !");
                    exit(1);
                }
            }
            else{
                wait(NULL);
            }
        }
    }
    return 0;
}