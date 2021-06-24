/*
* Programa que muestra una linea del metro con sus estaciones y permite calcular el tiempo del recorrido
*/
//Librerias a usar
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Variables globales
int origen;
int destino;
int *punteroOrigen;
int *punteroDestino;
//prototipo de mis funciones
void verLineasMetroA();
void verLineasMetroB();
void metroA();
void metroB();
void tiempoLineaA(int a, int b);
void tiempoLineaB(int a, int b);


// linea A
char *lineaA[10][2] = {
    {
        //Nombre    Tiempo en min
        "pantitlan","3"
    },
    {
        "agricola oriental","3"
    },
    {
        "canal de san jaun","3"
    },
    {
        "tepalcates","3"
    },
    {
        "guelatao","3"
    },
    {
        "peñon viejo","3"
    },
    {
        "acatitla","3"
    },
    {
        "santa marta","3"
    },
    {
        "los reyes","3"
    },
    {
        "la paz","3"
    }

};
char *lineaB[21][2] = {
    {
        "ciudad azteca","3"
    },
    {
        "plaza aragon","3"
    },
    {
        "olimpica","3"
    },
    {
        "Ecatepec","3"
    },
    {
        "Muzquiz","3"
    },
    {
        "Rio de los remedios","3"
    },
    {
        "impulsora","3"
    },
    {
        "Nezahualcoyotl","3"
    },
    {
        "villa de aragon","3"
    },
    {
        "bosques de aragon","3"
    },
    {
        "deportivo oceania","3"
    },
    {
        "oceania","3"
    },
    {
        "romero rubio","3"
    },
    {
        "R.Flores magon","3"
    },
    {
        "san lazaro","3"
    },
    {
        "Morelos","3"
    },
    {
        "tepito","3"
    },
    {
        "lagunilla","3"
    },
    {
        "garibaldi","3"
    },
    {
        "guerrero","3"
    },
    {
        "Buena vista","3"
    }

};

int main(void) {
    //variable local
    char metrodf;
    //Mensaje de bienvenida
    printf("Bienvenido a mi software \n");

    printf("Que linea del metro desea ver la A o la B:  ");
    scanf("%c",&metrodf);
    switch(metrodf) {
        case 'A':
        case 'a':
            metroA();
            break;
        case 'B' :
        case 'b' :
            metroB();
            break;
        default :
            printf("Opcion no valida \n" );
    }

    return 0;
}
//funciones para ver las lineas del metro
void verLineasMetroA(){
    register int t;
    for(t= 0; t<10; t++)
        printf("%d.- %s \n",t+1,lineaA[t][0] );
}
void verLineasMetroB(){
    register int t;
    for(t= 0; lineaB[t][0]; t++)
        printf("%d.- %s \n",t+1,lineaB[t][0] );
}
//funciones para calcular el tiempo
void tiempoLineaA(int a, int b){
    register int t;
    int resultado = 0;
    if(a < b){
        for(t = a; t!=b; t++)
            resultado += atoi(lineaA[t][1]);
    }else{
        for(t = b; t!=a; t++)
            resultado += atoi(lineaA[t][1]);

    }
    printf("Te tardaras en llegar %d min \n",resultado);

}
void tiempoLineaB(int a, int b){
    register int t;
    int resultado = 0;
    if(a < b){
        for(t = a; t!=b; t++)
            resultado += atoi(lineaB[t][1]);
    }else{
        for(t = b; t!=a; t++)
            resultado += atoi(lineaB[t][1]);

    }
    printf("Te tardaras en llegar %d min \n",resultado);

}
//funciones principales
void metroA(){
    do{
        verLineasMetroA();
        printf("Coloca tu origen: ");
        scanf("%d",&origen);
    }while(!origen);
    punteroOrigen=&origen;
    punteroOrigen--;
    do{
        //metroLineaA();
        printf("Coloca tu destino: ");
        scanf("%d",&destino);
    }while(!destino);
    punteroDestino=&destino;
    punteroDestino--;
    tiempoLineaA(origen, destino);

}
void metroB(){
    do{
        verLineasMetroB();
        printf("Coloca tu origen: ");
        scanf("%d",&origen);
    }while(!origen);
    punteroOrigen=&origen;
    punteroOrigen--;
    do{
        printf("Coloca tu destino: ");
        scanf("%d",&destino);
    }while(!destino);
    punteroDestino=&destino;
    punteroDestino--;
    tiempoLineaB(origen, destino);
}
