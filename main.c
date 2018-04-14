#include <stdio.h>
#include "tablas.h"
#include "funciones.h"

/*
 * Falta a partir de permutar IP, invertir L y R y de eso en adelante*/

int main() {

    TablasPermutacion t = newTablas();

    int i=0;
    unsigned char M[8]={0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF};
    unsigned char L0[4]={0};
    unsigned char R0[4]={0};
    unsigned char R0permutado[6]={0};

    unsigned char K[8]={0x13, 0x34, 0x57, 0x79, 0x9B, 0xBC, 0xDF, 0xF1};

    unsigned char Mpermutada[8]={0};

    unsigned char Kpermutada[7]={0};

    unsigned char C0[4]={0};
    unsigned char D0[4]={0};

    unsigned char* Ci[16]={0};
    unsigned char* Di[16]={0};

    unsigned char* CiDi[16]={0};
    unsigned char* subLlaves[16]={0};

    inicializaMatriz(Ci,16, 4);/*Para almacenar 28 bits*/
    inicializaMatriz(Di,16, 4);/*Para almacenar 28 bits*/

    inicializaMatriz(CiDi,16, 7); /*Para almacenar 56 bits, almacena la combinacion CiDi*/
    inicializaMatriz(subLlaves,16,6); /*Para almacenar las llave obtenida de permutar CiDi con PC2 (48bits)*/

    /*Permuta la llave Original*/
    permutar(Kpermutada,K,t.pc1,FILAS_PC1,COLUMNAS_PC1);

//  Divide la llave permutada en Ci (parte izquierda) y Di (parte derecha)
    divideK56b(C0,D0,Kpermutada);

    /** Se obtiene las 16 Ci y Di desplazadas según le corresponda */
    getCiDiSh(C0, Ci);
    getCiDiSh(D0, Di);

    unirAllCiDi(Ci,Di,CiDi);

    permutarMatrizBytes(subLlaves,CiDi,t.pc2,FILAS_PC2, COLUMNAS_PC2);

    permutar(Mpermutada,M,t.ip,FILAS_IP,COLUMNAS_IP);

    getL0R0(L0,R0,Mpermutada);


    printArray(R0,4);
    println();
    permutar(R0permutado,R0,t.E,FILAS_E,COLUMNAS_E);
    printArray(R0permutado,6);


    /*while (i<16) {
        printf("K[%d]:\t",i+1);
        printArray(subLlaves[i],6);
        println();
        i++;
    }*/


    return 0;
}

