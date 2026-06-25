#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    while(1){
        char input[20];
        printf("Shell> ");
        fgets(input,sizeof(input),stdin);
        if(strcmp(input,"exit\n") == 0){
            break;
        }
        char *token = strtok(input," ");
        while(token != NULL){
            printf("%s\n",token);
            token = strtok(NULL, " ");
        }
    }
    return 0;
}