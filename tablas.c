#include "tablas.h"

TablasPermutacion newTablas()
{
    TablasPermutacion t;
    /*
     * Se inicializa pc1
     */
    t.pc1[0][0] = 57;
    t.pc1[0][1] = 49;
    t.pc1[0][2] = 41;
    t.pc1[0][3] = 33;
    t.pc1[0][4] = 25;
    t.pc1[0][5] = 17;
    t.pc1[0][6] = 9;
    t.pc1[0][7] = 1;

    t.pc1[1][0] = 58;
    t.pc1[1][1] = 50;
    t.pc1[1][2] = 42;
    t.pc1[1][3] = 34;
    t.pc1[1][4] = 26;
    t.pc1[1][5] = 18;
    t.pc1[1][6] = 10;
    t.pc1[1][7] = 2;

    t.pc1[2][0] = 59;
    t.pc1[2][1] = 51;
    t.pc1[2][2] = 43;
    t.pc1[2][3] = 35;
    t.pc1[2][4] = 27;
    t.pc1[2][5] = 19;
    t.pc1[2][6] = 11;
    t.pc1[2][7] = 3;

    t.pc1[3][0] = 60;
    t.pc1[3][1] = 52;
    t.pc1[3][2] = 44;
    t.pc1[3][3] = 36;
    t.pc1[3][4] = 63;
    t.pc1[3][5] = 55;
    t.pc1[3][6] = 47;
    t.pc1[3][7] = 39;

    t.pc1[4][0] = 31;
    t.pc1[4][1] = 23;
    t.pc1[4][2] = 15;
    t.pc1[4][3] = 7;
    t.pc1[4][4] = 62;
    t.pc1[4][5] = 54;
    t.pc1[4][6] = 46;
    t.pc1[4][7] = 38;

    t.pc1[5][0] = 30;
    t.pc1[5][1] = 22;
    t.pc1[5][2] = 14;
    t.pc1[5][3] = 6;
    t.pc1[5][4] = 61;
    t.pc1[5][5] = 53;
    t.pc1[5][6] = 45;
    t.pc1[5][7] = 37;

    t.pc1[6][0] = 29;
    t.pc1[6][1] = 21;
    t.pc1[6][2] = 13;
    t.pc1[6][3] = 5;
    t.pc1[6][4] = 28;
    t.pc1[6][5] = 20;
    t.pc1[6][6] = 12;
    t.pc1[6][7] = 4;

    /*
     * Inicializa PC2
     */

    t.pc2[0][0] = 14;
    t.pc2[0][1] = 17;
    t.pc2[0][2] = 11;
    t.pc2[0][3] = 24;
    t.pc2[0][4] = 1;
    t.pc2[0][5] = 5;
    t.pc2[0][6] = 3;
    t.pc2[0][7] = 28;

    t.pc2[1][0] = 15;
    t.pc2[1][1] = 6;
    t.pc2[1][2] = 21;
    t.pc2[1][3] = 10;
    t.pc2[1][4] = 23;
    t.pc2[1][5] = 19;
    t.pc2[1][6] = 12;
    t.pc2[1][7] = 4;

    t.pc2[2][0] = 26;
    t.pc2[2][1] = 8;
    t.pc2[2][2] = 16;
    t.pc2[2][3] = 7;
    t.pc2[2][4] = 27;
    t.pc2[2][5] = 20;
    t.pc2[2][6] = 13;
    t.pc2[2][7] = 2;

    t.pc2[3][0] = 41;
    t.pc2[3][1] = 52;
    t.pc2[3][2] = 31;
    t.pc2[3][3] = 37;
    t.pc2[3][4] = 47;
    t.pc2[3][5] = 55;
    t.pc2[3][6] = 30;
    t.pc2[3][7] = 40;

    t.pc2[4][0] = 51;
    t.pc2[4][1] = 45;
    t.pc2[4][2] = 33;
    t.pc2[4][3] = 48;
    t.pc2[4][4] = 44;
    t.pc2[4][5] = 49;
    t.pc2[4][6] = 39;
    t.pc2[4][7] = 56;

    t.pc2[5][0] = 34;
    t.pc2[5][1] = 53;
    t.pc2[5][2] = 46;
    t.pc2[5][3] = 42;
    t.pc2[5][4] = 50;
    t.pc2[5][5] = 36;
    t.pc2[5][6] = 29;
    t.pc2[5][7] = 32;

    /*
     * Se inicializacio IP
     */

    t.ip[0][0]=58;
    t.ip[0][1]=50;
    t.ip[0][2]=42;
    t.ip[0][3]=34;
    t.ip[0][4]=26;
    t.ip[0][5]=18;
    t.ip[0][6]=10;
    t.ip[0][7]=2;

    t.ip[1][0]=60;
    t.ip[1][1]=52;
    t.ip[1][2]=44;
    t.ip[1][3]=36;
    t.ip[1][4]=28;
    t.ip[1][5]=20;
    t.ip[1][6]=12;
    t.ip[1][7]=4;

    t.ip[2][0]=62;
    t.ip[2][1]=54;
    t.ip[2][2]=46;
    t.ip[2][3]=38;
    t.ip[2][4]=30;
    t.ip[2][5]=22;
    t.ip[2][6]=14;
    t.ip[2][7]=6;

    t.ip[3][0]=64;
    t.ip[3][1]=56;
    t.ip[3][2]=48;
    t.ip[3][3]=40;
    t.ip[3][4]=32;
    t.ip[3][5]=24;
    t.ip[3][6]=16;
    t.ip[3][7]=8;

    t.ip[4][0]=57;
    t.ip[4][1]=49;
    t.ip[4][2]=41;
    t.ip[4][3]=33;
    t.ip[4][4]=25;
    t.ip[4][5]=17;
    t.ip[4][6]=9;
    t.ip[4][7]=1;

    t.ip[5][0]=59;
    t.ip[5][1]=51;
    t.ip[5][2]=43;
    t.ip[5][3]=35;
    t.ip[5][4]=27;
    t.ip[5][5]=19;
    t.ip[5][6]=11;
    t.ip[5][7]=3;

    t.ip[6][0]=61;
    t.ip[6][1]=53;
    t.ip[6][2]=45;
    t.ip[6][3]=37;
    t.ip[6][4]=29;
    t.ip[6][5]=21;
    t.ip[6][6]=13;
    t.ip[6][7]=5;

    t.ip[7][0]=63;
    t.ip[7][1]=55;
    t.ip[7][2]=47;
    t.ip[7][3]=39;
    t.ip[7][4]=31;
    t.ip[7][5]=23;
    t.ip[7][6]=15;
    t.ip[7][7]=7;


    t.E[0][0]=32;
    t.E[0][1]=1;
    t.E[0][2]=2;
    t.E[0][3]=3;
    t.E[0][4]=4;
    t.E[0][5]=5;
    t.E[0][6]=4;
    t.E[0][7]=5;

    t.E[1][0]=6;
    t.E[1][1]=7;
    t.E[1][2]=8;
    t.E[1][3]=9;
    t.E[1][4]=8;
    t.E[1][5]=9;
    t.E[1][6]=10;
    t.E[1][7]=11;

    t.E[2][0]=12;
    t.E[2][1]=13;
    t.E[2][2]=12;
    t.E[2][3]=13;
    t.E[2][4]=14;
    t.E[2][5]=15;
    t.E[2][6]=16;
    t.E[2][7]=17;

    t.E[3][0]=16;
    t.E[3][1]=17;
    t.E[3][2]=18;
    t.E[3][3]=19;
    t.E[3][4]=20;
    t.E[3][5]=21;
    t.E[3][6]=20;
    t.E[3][7]=21;

    t.E[4][0]=22;
    t.E[4][1]=23;
    t.E[4][2]=24;
    t.E[4][3]=25;
    t.E[4][4]=24;
    t.E[4][5]=25;
    t.E[4][6]=26;
    t.E[4][7]=27;

    t.E[5][0]=28;
    t.E[5][1]=29;
    t.E[5][2]=28;
    t.E[5][3]=29;
    t.E[5][4]=30;
    t.E[5][5]=31;
    t.E[5][6]=32;
    t.E[5][7]=1;


/*    t.E[0][0]=32;
    t.E[0][1]=1;
    t.E[0][2]=2;
    t.E[0][3]=3;
    t.E[0][4]=4;
    t.E[0][5]=5;

    t.E[1][0]=4;
    t.E[1][1]=5;
    t.E[1][2]=6;
    t.E[1][3]=7;
    t.E[1][4]=8;
    t.E[1][5]=9;

    t.E[2][0]=8;
    t.E[2][1]=9;
    t.E[2][2]=10;
    t.E[2][3]=11;
    t.E[2][4]=12;
    t.E[2][5]=13;

    t.E[3][0]=12;
    t.E[3][1]=13;
    t.E[3][2]=14;
    t.E[3][3]=15;
    t.E[3][4]=16;
    t.E[3][5]=17;

    t.E[4][0]=16;
    t.E[4][1]=17;
    t.E[4][2]=18;
    t.E[4][3]=19;
    t.E[4][4]=20;
    t.E[4][5]=21;

    t.E[5][0]=20;
    t.E[5][1]=21;
    t.E[5][2]=22;
    t.E[5][3]=23;
    t.E[5][4]=24;
    t.E[5][5]=25;

    t.E[6][0]=24;
    t.E[6][1]=25;
    t.E[6][2]=26;
    t.E[6][3]=27;
    t.E[6][4]=28;
    t.E[6][5]=29;

    t.E[7][0]=28;
    t.E[7][1]=29;
    t.E[7][2]=30;
    t.E[7][3]=31;
    t.E[7][4]=32;
    t.E[7][5]=1;*/


    return t;
}