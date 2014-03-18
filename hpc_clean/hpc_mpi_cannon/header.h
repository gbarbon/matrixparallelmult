/* 
 * File:   functions.h
 * Author: jian
 *
 * Created on 13 marzo 2014, 11.42
 */

#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

//includes
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//define constants
#define TAG 13

//function definition:
int* coordinate(int procNum, int totalProc) {
    int* coord = (int*) calloc(2, sizeof (int)); //aggiunto (int*)
    int var;
    var = sqrt(totalProc);
    coord[0] = procNum / var;
    coord[1] = procNum % var;
    return coord;
}

void printmatrix(int N, double** C) {
    // print matrix

    int i, j; //matrix indexes

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%f ", C[i][j]);
        printf("\n");

    }
}

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* FUNCTIONS_H */
