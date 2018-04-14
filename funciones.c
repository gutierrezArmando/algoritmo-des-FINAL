#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
//
// Created by Armando on 4/2/2018.
//

void println(){
    printf("\n");
}

/**
 * @registro: la direccion de un byte
 * @valor: valor de 0 ó 1 a escribir
 * @numBit: En el numero de bit del registro de izquierda a derecha
 * */
void putBitOnReg(unsigned char *registro, int valor, int numBit) {
    if(valor)
        *registro|=(0x80>>(numBit-1));
}

/** imprime un byte en binario*/
void printBin(unsigned char registro)
{
    int i = 1;
    while(i < 9) {
        printf("%d", GETBITVAL_REG(registro, i++));
        if(i==5)
            printf("-");
    }
}

/** Imprime una arreglo de bits
 * @arreglo: el arreglo de bytes (unsigned char) a imprimir
 * @cantidadRegistros: la cantidad de elementos totales del arreglo
 */
void printArray(unsigned char *arreglo, int cantidadRegistros)
{
    unsigned char index=0;
    while (index < cantidadRegistros) {
        printBin(arreglo[index++]);
        printf(" ");
    }
}

/** Rota un byte
 * @param: byte, es es byte a rotar una vez*/
void rol(unsigned char *byte) {
    unsigned char index=0, acarreoFinal=0;
    acarreoFinal = byte[0]>>7;
    while(index<6)
    {
        byte[index]<<=1;
        byte[index]|=(byte[index+1]>>7);
        index++;
    }
    byte[index]<<=1;
    byte[index]|=acarreoFinal;
}

/** Funcion que rota un byte la cantidad de veces requeridas
 * @param: direccion del byte a rotar
 * @param: cantidad de veces que se tiene que rotar*/
void rolN(unsigned char *arrayByte, int cantidad)
{
    while(cantidad--)
        rol(arrayByte);
}

void divideK56b(unsigned char C0[], unsigned char D0[], unsigned char llavePermutada[]) {
    int i=0;
    while (i < 4) {
        C0[i] = llavePermutada[i];
        D0[i] = llavePermutada[i+3];
        i++;
    }
    shrN(C0, 4, 4);
    D0[0]&=0x0F;
}

void shrN(unsigned char array[], int cantidadDesplazamientos, int cantidadElementos) {
    while (cantidadDesplazamientos--)
        shr(array, cantidadElementos);
}

void shr(unsigned char array[], int cantidadElementos) {
    while (--cantidadElementos)
        array[cantidadElementos]=((array[cantidadElementos]>>1)|(array[cantidadElementos-1]<<7));
    array[cantidadElementos]>>=1;
}

void rol28b(unsigned char C[], int cantidadVeces ) {
    shlN(C,cantidadVeces,4);
    C[3]|=( C[0] >> 4 );
    C[0]&=0x0F;
}


void shl(unsigned char array[], int cantidadElementos) {
    int i = 0;

    while ( i < (cantidadElementos-1)) {
        array[i] = ((array[i]<<1)|(array[i+1]>>7));
        i++;
    }
    array[i]<<=1;
}

void shlN(unsigned char array[], int cantidadDesplazamientos, int cantidadElementos) {
    while (cantidadDesplazamientos--)
        shl(array, cantidadElementos);
}

void inicializaMatriz(unsigned char* m[], int filas, int columnas) {
    int i=0;
    while (i<filas)
        m[i++] = (unsigned char *) malloc(columnas* sizeof(unsigned char));
}

void copiarAToB(unsigned char *arreDestino, unsigned char *arreOrigen, int cantidadElementos) {
    while (cantidadElementos--)
        *arreDestino++=*arreOrigen++;
}

void permutar(unsigned char *arregloPermutado, unsigned char *arregloAPermutar, unsigned char tblPermutacion[][8], int filas, int columnas)
{
    int i=0, j=0;
    unsigned char registroConteo = 0;
    while(i<filas)
    {
        j=0;
        while (j<columnas) {
            putBitOnReg(&arregloPermutado[(registroConteo>>3)], GETBITVAL_M(arregloAPermutar, GET_PC_VALOR(tblPermutacion,i,j)), (registroConteo&0x07) + 1);
            registroConteo++;
            j++;
        }
        i++;
    }
}

void getCiDiSh(unsigned char* llaveOriginal, unsigned char* listaDeLlaves[]) {
    int i = 0;
    copiarAToB(listaDeLlaves[i],llaveOriginal,4);
    while (i < 15) {
        rol28b(listaDeLlaves[i],((i==0)||(i==1)||(i==8))? 1 : 2 );
        copiarAToB(listaDeLlaves[i+1],listaDeLlaves[i],4);
        i++;
    }
    rol28b(listaDeLlaves[i],1);
}

void unirCiDi(unsigned char* Ci, unsigned char* Di, unsigned char* CiDi) {
    int i=0;
    shlN(Ci,4,4);
    CiDi[0] = Ci[0];
    CiDi[1] = Ci[1];
    CiDi[2] = Ci[2];

    CiDi[4] = Di[1];
    CiDi[5] = Di[2];
    CiDi[6] = Di[3];
    CiDi[3] = (Ci[3] | Di[0]);
}

void unirAllCiDi(unsigned char* matrizCi[], unsigned char* matrizDi[], unsigned  char* matrizCiDi[]) {
    int filas = 16;
    while (filas--)
        unirCiDi(matrizCi[filas],matrizDi[filas],matrizCiDi[filas]);
}

void permutarMatrizBytes(unsigned char* matrizDestino[], unsigned char* matrizOrigen[], unsigned char tablaPermutacion[][8], int filas,
                         int columnas) {
    int totalLlaves = 16;
    while (totalLlaves--) {
//        printf("%d-", totalLlaves);
        permutar(matrizDestino[totalLlaves], matrizOrigen[totalLlaves], tablaPermutacion, filas, columnas);
    }
}

void getL0R0(unsigned char* l0, unsigned char* r0, unsigned char* Mpermutada){
    int i=0;
    while (i<4){
        l0[i] = Mpermutada[i];
        r0[i] = Mpermutada[i+4];
        i++;
    }
}