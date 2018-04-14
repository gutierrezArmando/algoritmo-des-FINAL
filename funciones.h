//
// Created by Armando on 4/2/2018.
//

#ifndef ALGORITMO_DES_FUNCIONES_H
#define ALGORITMO_DES_FUNCIONES_H

// Obtiene el valor del bit de la posicion, del registro
#define GETBITVAL_REG(registro, posicion)((registro&(0x80>>(posicion-1)))?1:0)

// Espera un valor (1:64) y lo divide entre 8, para localizar la posicion
// del byte con el que se debe trabajar
#define FIND_M_INDEX(numBit)((numBit-1)/8)

// Obtiene el valor de la tabla pc, correspondiente a la fila y columa
#define GET_PC_VALOR(matriz, fila, columna)(matriz[fila][columna])

// Obtiene el valor del numero de bit del total de los bits necesarios por M
#define GETBITVAL_M(m, numBit)(GETBITVAL_REG(m[FIND_M_INDEX(numBit)],(numBit-(FIND_M_INDEX(numBit)*8))))

void println();

void putBitOnReg(unsigned char *registro, int valor, int numBit);

void printBin(unsigned char registro);

/** Imprime una arreglo de bits
 * @arreglo: el arreglo de bytes (unsigned char) a imprimir
 * @cantidadRegistros: la cantidad de elemetos totales del arreglo
 */
void printArray(unsigned char *arreglo, int cantidadRegistros);

/** Rota un byte
 * @param: byte, es es byte a rotar*/
void rol(unsigned char *byte);

/** Funcion que rota un byte la cantidad de veces requeridas
 * @param: direccion del byte a rotar
 * @param: cantidad de veces que se tiene que rotar*/
void rolN(unsigned char *arrayByte, int cantidad);

void divideK56b(unsigned char C0[], unsigned char D0[], unsigned char llavePermutada[]);

/*Desplaza a la derecha N veces*/
void shrN(unsigned char array[], int cantidadDesplazamientos, int cantidadElementos);

/*La funcion desplaza a la derecha una vez*/
void shr(unsigned char array[], int cantidadElementos);

void rol28b(unsigned char C[], int cantidadVeces );

/** Desplaza a la izquierda una vez*/
void shl(unsigned char array[], int cantidadElementos);

/**Desplaca a la izquierda N veces*/
void shlN(unsigned char array[], int cantidadDesplazamientos, int cantidadElementos);

void inicializaMatriz(unsigned char* m[], int filas, int columnas);

void copiarAToB(unsigned char *arreDestino, unsigned char *arreOrigen, int cantidadElementos);

/**
* @param: arregloPermutado arreglo en el que se almacenará la permutación
* @param: arregloAPermutar es la llave que se permutara
* @param: tblPermutacion es la tabla de permitación
 * @param: filas, cantidad de filas de la tabla de permutacion
 * @param: columnas, la cantidad de columnas de la tabla de permutación
*/
void permutar(unsigned char *arregloPermutado, unsigned char *arregloAPermutar, unsigned char tblPermutacion[][8], int filas, int columna);

/**
 * @details: crear y almacena los desplazaminetos de cada Ci y Di
 * @param: El arreglo de bytes que contiene la llave original
 * @param: La matriz que almacenará las 16 Ci o Di (dependiendo el caso), que dan como resultado de los
 * desplazamientos
 * */
void getCiDiSh(unsigned char* llaveOriginal, unsigned char* listaDeLlaves[]);

/**
 * @details: espera dos grupos de bits, cada uno de 28 bits y los une formando uno de 56 bits
 * @param: parte alta del nuevo grupo de bits
 * @param: parte baja del nuevo grupo de bits
 * @param: Donde se almacenará el resultado de la union de los dos grupos anteriores
 * */
void unirCiDi(unsigned char* Ci, unsigned char* Di, unsigned char* CiDi);

/**
 * @details: une dos listas de grupos de bits 28 bits cada uno, y lo almacena en otra lista que contiene grupos de 56 bits
 * @param: matriz de elementos que contiene todos los grupos que formarán la parte alta de los grupos de 56 bits.
 * @param: matriz de elementos que contiene todos los grupos que formarán la parte baja de los grupos de 56 bits.
 * @param: matriz en donde se almacenarán los grupos de 56 bits
 * */
void unirAllCiDi(unsigned char* matrizCi[], unsigned char* matrizDi[], unsigned  char* matrizCiDi[]);


/**
 * @details: Permuta todos los grupos de bits almacenados en una matriz
 * @param: Matriz destino, donde se almacenaran los resultados de las permutaciones de cada elemento
 * @param: Matriz que contiene todos los grupos que se quieren permutar
 * @param: Tabla de permutacion que se utilizará
 * @param: Filas de la tabla de permutación a utilizar
 * @param: Columnas de la tabla de permutación a utilizar
 */
void permutarMatrizBytes(unsigned char* matrizDestino[], unsigned char* matrizOrigen[], unsigned char tablaPermutacion[][8], int filas,
                         int columnas);
/**
 * Divide un arreglo de 8 elementos en dos parte, cada parte de 4 elementos
 * */
void getL0R0(unsigned char* l0, unsigned char* r0, unsigned char* Mpermutada);
#endif //ALGORITMO_DES_FUNCIONES_H
