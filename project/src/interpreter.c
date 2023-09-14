// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "../include/variable.h"
// #include "../include/condition.h"


// void execute_c_minus_minus(char* input_code) {
//     char* token = strtok(input_code, "\n");

//     while (token != NULL) {
//         printf("%s\n",token);
//         // if (strstr(token, "=")) {
//         //     printf("Declaring variable\n");
//         // }
//         // else if (strstr(token, "print")) {
//         //     printf("Printing variable\n");
//         // }
//         // else{
//         //     printf("Error\n");
//         // }
//         if (strstr(token, ">")) {
            
//             printf("Detected the '>' symbol\n");
//         }

//         token = strtok(NULL, "\n");
//     }
// }


// int main() {
//     char code[] =
//         "int x = 10;\n"
//         "int y = 5;\n"
//         "int z = x + y;\n"
//         "print z;\n"
//         "if (z > 10) {\n";
//             "int w = 20;\n"
//             "print w;\n"
//         "};\n";

//     execute_c_minus_minus(code);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute_c_minus_minus(char* input_code){
    char* code_copy = strdup(input_code); // Make a copy of input_code
    char* token = strtok(code_copy, ";\n");

    while (token != NULL) {
        printf("%s\n", token);

        // Tokenize token by space and print each part
        char* code = strtok(token, " ");
        while (code != NULL) {
            printf("%s ", code);
            code = strtok(NULL, " ");
        }

        token = strtok(NULL, ";\n");
    }

    free(code_copy); // Free the memory allocated for code_copy
}

int main(){
    char code[] =
        "int x = 10;\n"
        "int y = 5;\n"
        "int z = x + y;\n"
        "print z;\n"
        "if (z > 10) {\n"
        "    int w = 20;\n"
        "    print w;\n"
        "};\n";

    execute_c_minus_minus(code);
    return 0;
}
