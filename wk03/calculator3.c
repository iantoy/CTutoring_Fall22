/**
 * @file calculator3.c
 * @author Ian Toy (iantoy@uab.edu)
 * @brief This implementation of our calculator that takes in operators and
 * arguments from the command line. It also makes use of function pointers.
 * 
 * It is important to note that since we are making use of the math system 
 * library, we need to include the "-lm" flag when we compile with gcc.
 * 
 * To compile: gcc calculator.c -lm -o calculator
 * @version 0.1
 * @date 2023-04-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h> /* Gives us access to exit() */
#include <math.h>   /* Gives us access to pow() */
#include <string.h> /* Gives us access to strcmp() */

/** Here, we make use of typedef, or type definition. typedef maps some new 
 * name for a data type to an existing data type. This can be done with any 
 * data type, but in this program we're using it to define a type of function.
 * This type of function expects two integer arguments and returns a float. */
typedef float OPERATOR(float a, float b); 

/* All of these following functions satisfy the above typedef for OPERATOR */
float add(float a, float b) {
    return a + b;
}
float sub(float a, float b) {
    return a - b;
}
float mult(float a, float b){
    return a * b;
}
float divide(float a, float b){
    return a / b;
}
/* What about this function? How would calculate() handle this funciton? */
float square(float a, float b) {
    return pow(a, 2);
}
/* What about this one? */
float expt(float a, float b) {
    return pow(a, b);
}

/** Using typedef allows us to leverage function pointers. The below function,
 * calculate, is a function handler. It expects arguments like any function, 
 * but one of those arguments is a function pointer, an OPERATOR *op. As far as
 * calculate is concerned, any function that satisfies the typedef of OPERATOR 
 * is a valid input. calculate then takes this function, and calls it on its 
 * other arguments, a and b. */
float calculate(float a, float b, OPERATOR *op){
    return op(a, b); /* Does some work based on the function passed to it */
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("ERROR: Correct usage is %s <operator> <a> <b>\n", argv[0]);
        printf("For example, %s add 1 2 \n", argv[0]);
        exit(-1);
    }

    char* myop = argv[1]; /* localize inputs */
    float a = atoi(argv[2]); /* use atoi() to convert char* args to ints */
    float b = atoi(argv[3]);

    if (strcmp(myop, "add") == 0){ /* If the provided operator is add... */
        printf("%.2f\n", calculate(a, b, add)); /* calculate with add */
    } else if (strcmp(myop, "sub") == 0){ /* If the provided op is sub... */
        printf("%.2f\n", calculate(a, b, sub));
    } else if (strcmp(myop, "mult") == 0){ /* If the provided op is mult... */
        printf("%.2f\n", calculate(a, b, mult));
    } else if (strcmp(myop, "div") == 0){ /* If the provided op is div... */
        printf("%.2f\n", calculate(a, b, divide));
    } /* end if-else block*/
    
    /* Experimental Code */
    if (strcmp(myop, "square") == 0){
        printf("%.2f\n", calculate(a, b, square));
    }
    if (strcmp(myop, "expt") == 0){
        printf("%.2f\n", calculate(a, b, expt));
    }
} /* end main() */