#include <stdio.h>
#include <stdlib.h>
#include "../include/variable.h"
#include <stdbool.h>
#include <string.h>

struct data{
    char* var_name;
    int* value;
};

struct data s[1000];

void assign_variable(char *token){
    for(int i=0;i<1000;i++){
        if(s[i].var_name && !s[i].value){
            s[i].value=(int*)malloc(sizeof(int));

            char *token_copy = strdup(token); 
            char *var_token = strtok(token_copy, " ");

            for(int j=0;j<4;j++){
                if(j==3){
                    *s[i].value=atoi(var_token);
                    break;
                }
                var_token=strtok(NULL," ");
            }
        }
    }
}

void create_variable(char *token) {
    for (int i = 0; i < 1000; i++) {
        if (!s[i].var_name) {
            s[i].var_name = (char *)malloc(sizeof(char));

            char *token_copy = strdup(token); 
            char *var_token = strtok(token_copy, " ");

            for (int j = 0; j < 2; j++) {
                if (j == 1) {
                    strcpy(s[i].var_name, var_token);
                    break;
                }
                var_token = strtok(NULL, " ");
            }
            if(s[i].var_name){
                assign_variable(token);
                break;
            }
            
        }
        
    }
}

int get_variable_value(char *var_name) {
    for (int i = 0; i < 1000; i++) {
        if (s[i].var_name && strcmp(s[i].var_name, var_name) == 0) { 
            return *s[i].value;
        }
    }
    return -1; 
}

int main() {
    char* code = "int x = 22";
    char* codes="int y = 23";

    create_variable(code);
    create_variable(codes);

    char* var_name1="x";
    char* var_name2="y";

    printf("%d",get_variable_value(var_name1));
    printf("%d",get_variable_value(var_name2));

    return 0;
}
