/*
* Programa que permite calcular los gastos en transporte al dia, semana, mes y año
*/

//Incluye las librerias a usar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define variables a usar
int i, medio, veces; char continuar[1];

//Define arreglo con transportes
char *transportes[5][3] = {
    { "metro",      "5", },
    { "metrobus",   "6", },
    { "combi",      "8", },
    { "autobus",    "5", },
    { "taxi",       "50", }
};

//Define arreglo con el total de veces usadas por dia
int total[5][2] = {
    {0, 0},
    {1, 0},
    {2, 0},
    {3, 0},
    {4, 0}
};

//Funcion que calcula los gastos totales
void calcula_total(void){

    int total_d = 0, total_s, total_m, total_a, j;
    for(j=0; j<5; j++){
        total_d += (atoi(transportes[j][1]) * total[j][1]);
    }
    total_s = total_d * 7;
    total_m = total_s * 4;
    total_a = total_m * 12;
    printf("\n\tGastos totales por dia: $%d\n", total_d );
    printf("\tGastos totales por semana: $%d\n", total_s );
    printf("\tGastos totales por mes: $%d\n", total_m );
    printf("\tGastos totales por año: $%d\n\n", total_a );
}

//Funcion que muestra la tabla con los datos
void mostrar_datos(void){
    system("cls");
    printf(" Programa que calcula gasto en pasaje \n\n");
    for( i=0; i<5;  i++)
        printf("%d - %s\t | $%s\t | %d \n", i, transportes[i][0], transportes[i][1], total[i][1]);
    calcula_total();
    printf("Ingresa el numero del transporte y las veces que lo usas al dia \n");
}

//Funcion qu recibe los datos del usuario
void calcula_gasto(void){
    for( ; ; ){
        mostrar_datos();

        scanf("%d %d", &medio, &veces);
        if( medio > 4 ){
            printf("Numero de transporte incorrecto, vuelva a intentar  \n");
            scanf("%d %d", &medio, &veces);
        }
        total[medio][1] = veces;

        mostrar_datos();

        printf("\n Desea ingresar mas gastos? y|n \n");
        scanf("%s", &continuar);
        if( !(strcmp(continuar, "y") == 0) ) break;
    }
}

//Funcion principal
int main(void){
    for( ; ; ){
        calcula_gasto();
        printf("\n Salir del programa? y|n \n");
        scanf("%s", &continuar);
        if( !(strcmp(continuar, "n") == 0) ) break;
    };
    return 0;
}
