
#ifndef ALGORITMO_DES_TABLAS_H
#define ALGORITMO_DES_TABLAS_H

#define FILAS_PC1 7
#define COLUMNAS_PC1 8

#define FILAS_PC2 6
#define COLUMNAS_PC2 8

#define FILAS_IP 8
#define COLUMNAS_IP 8

#define FILAS_E 6
#define COLUMNAS_E 8

typedef struct {
    unsigned char pc1[FILAS_PC1][COLUMNAS_PC1];
    unsigned char pc2[FILAS_PC2][COLUMNAS_PC2];
    unsigned char ip[FILAS_IP][COLUMNAS_IP];
    unsigned char E[FILAS_E][COLUMNAS_E];
}TablasPermutacion;

TablasPermutacion newTablas();


#endif //ALGORITMO_DES_TABLAS_H
