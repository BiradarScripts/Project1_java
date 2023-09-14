#include<stdio.h>
#include "../include/arithmetic.h";

int perform_arithmetic(int x, char *op, int y){
    if (op == "+"){
        return x + y;
    } else if (op == "-"){
        return x - y;
    } else if (op == "*"){
        return x * y;
    } else if (op == "/"){
        return x / y;
    } else {
        printf("Invalid operator: %s\n", op);
        return 0;
    }
} 