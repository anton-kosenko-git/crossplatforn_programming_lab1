/******************************************************************************

                            Cross-platform programming
                                Laboratory work 1
                            Little endian to big endian
                              Anton Kosenko IT-ZP01

*******************************************************************************/

#include <stdio.h>
#include <time.h>
#include <inttypes.h>
#include "ltb.h"

#define N 10

int main() {
    
    uint32_t l[N] = {0x2F112B74, 0x1CDD60E2, 0x2BDA60A2, 0x1ADA73E1, 0x2CAC6061,
    0x3BDC03D2, 0x0CAD20A2, 0x2FDB20B2, 0x2CBA23A2, 0x1CAA20B5};
    uint32_t b[N] = {0};
    
    printf("\nLittle endians: \n");
    for(int i = 0; i < N; i++){
        printf("\n{%d} %x", i+1, l[i]);
    }
    clock_t start, end; // create two variables for start and end points of programm  
    double cpu_time_used; // create variable for cpu_time_used

    //converting with functions
    // little to big endian
    start = clock();// save the start point
    for(int i = 0; i < N; i++){
        b[i] = __builtin_bswap32(l[i]);
    }
    end = clock(); // save the end point
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // compute the working time of program in seconds
    
    printf("\n\nBig endians convertion with function: \n");
    for(int i = 0; i < N; i++){
        printf("\n{%d} %x", i+1, b[i]);
    }

    printf(" \nTime used=%f\n", cpu_time_used); // time the program has worked
    
    // big to little endian
    start = clock();// save the start point
    for(int i = 0; i < N; i++){
        l[i] = __builtin_bswap32(b[i]);
    }
    end = clock(); // save the end point
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // compute the working time of program in seconds
    
    // print result of convertion
    printf("\nlittle endians convertion with function: \n");
    for(int i = 0; i < N; i++){
        printf("\n{%d} %x", i+1, l[i]);
    }
    printf(" \nTime used=%f\n", cpu_time_used); // time the program has worked

    //little to big endian
    start = clock();// save the start point
    for(int i = 0; i < N; i++){
        b[i] = littleToBigEndian(l[i]);
    }
    end = clock(); // save the end point
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // compute the working time of program in seconds
    
    printf("\nBig endians manual convertion: \n");
    for(int i = 0; i < N; i++){
        printf("\n{%d} %x", i+1, b[i]);
    }
    printf(" \nTime used=%f\n", cpu_time_used); // time the program has worked
    
    //big to little endian
    start = clock();// save the start point
    for(int i = 0; i < N; i++){
        l[i] = littleToBigEndian(b[i]);
    }
    end = clock(); // save the end point
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // compute the working time of program in seconds
    
    printf("\nlittle endians manual convertion: \n");
    for(int i = 0; i < N; i++){
        printf("\n{%d} %x", i+1, l[i]);
    }
    printf(" \nTime used=%f\n", cpu_time_used); // time the program has worked
    
    return 0;
}

