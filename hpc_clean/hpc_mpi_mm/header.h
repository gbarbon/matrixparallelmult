/* 
 * File:   functions.h
 * Author: jian
 *
 * Created on 13 marzo 2014, 11.42
 */

#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

/*includes*/
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define TAG 13
const int tags[3] = {1, 2, 3};


/*
 * 
 * FUNCTION DEFINITION
 */

/* 
 * Creates axb matrix
 */
double** matrix_creator(int a, int b) {
    double **mat = (double **) malloc(a * sizeof (double*));
    int i;
    for (i = 0; i < a; i++)
        mat[i] = (double *) malloc(b * sizeof (double));
    return mat;
}

int matrix_init(double** mat, int n) {
    int i, j; /*matrix indexes*/

    /* random seed initialization */
    srand(time(NULL));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            mat[i][j] = ((double) rand() / (double) RAND_MAX);
    }
    return 0;
}

/*
 * free a nxn matrix
 */
void freematrix(double** mat) {
    int i;
    for (i = 0; mat[i] != NULL; i++) {
        free(mat[i]);
    }
    free(mat);
}

/*print matrix axb*/
void printmatrix(int a, int b, double** C) {
    int i, j;
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++)
            printf("%f ", C[i][j]);
        printf("\n");
    }
}

/*print vector */
void printmatrix(int a, double* C) {
    int i, j;
    for (i = 0; i < a; i++) 
        printf("%f ", C[i]);
}

double * matrix_vectorizer(int a, int b, double ** mat){
    double * vet = (double *) malloc(a * b * sizeof (double));
    int i, j, offset = 0;
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            vet[j+offset] = mat[i][j];
        }
        offset = offset + a;
    }
    return vet;
}

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* FUNCTIONS_H */

