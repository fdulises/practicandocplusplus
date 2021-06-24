/*
* Programa para cotizar productos de telecomunicaciones
*/

//Incluye las librerias a usar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define variables a usar
int i, equipo, veces, total; char continuar[1], palabra, paquete;

//Define arreglo con productos
char *productos[4][3] = {
    { "Telefono Unilinea con Pantalla",    "1000", "0" },
    { "Telefono Multilinea Con Pantalla",  "2500", "1" },
    { "Tarjeta Identificador De Llamadas", "2000", "2" },
    { "Central Telefonica 8 lineas 3 ext", "3000", "3" }
};

int paquetes[4][4] = {
    { 3, 2, 1, 1 },
    { 3, 1, 1, 1 },
    { 6, 1, 1, 1 },
    { 4, 2, 1, 1 }
};

int cantidades[4] = {0, 0, 0, 0};

int total_paquete(int pack){
    int total = 0;
    for( i=0; i<4; i++ ) total += paquetes[pack][i] * atoi(productos[i][1]);
    return total;
}

void mostrar_paquete(int pack){
    printf("\n\tCantidad | Producto \t\t\t| Precio\n");
    for( i=0; i<4; i++ ) printf("\t%i %s \t$%s\n", paquetes[pack][i], productos[i][0], productos[i][1] );
    printf("\tTotal: $%i\n", total_paquete(pack));
}

void mostrar_lista_paquetes(void){
    system("cls");
    printf("A-Ver paquetes de productos\n");

    printf("\n\t1-Paquetes de intercomunicacion 1\n");
    mostrar_paquete(0);

    printf("\n\t2-Paquetes de intercomunicacion 2\n");
    mostrar_paquete(1);

    printf("\n\t3-Paquetes de intercoumicacion 3\n");
    mostrar_paquete(2);

    printf("\n\t4-Paquetes de intercoumicacion 4\n");
    mostrar_paquete(3);
}

void mostrar_equipos(){
    system("cls");
    printf("B-Cotizar Productos\n");
    printf("\n\tProducto \t\t\t| Precio | Cantidad\n");
    for( i=0; i<4; i++ ) printf("\t%i %s \t$%s | %i\n", i, productos[i][0], productos[i][1], cantidades[i]);
    total = 0;
    for( i=0; i<4; i++ ) total += cantidades[i] * atoi(productos[i][1]);
    printf("Total: $%i \n", total);
}

void cotizar_equipos(){
    cantidades[0] = 0;
    cantidades[1] = 0;
    cantidades[2] = 0;
    cantidades[3] = 0;
    do{
        mostrar_equipos();
        printf("Ingresa la clave del producto y la cantidad\n");
        scanf("%d %d", &equipo, &veces);
        if( equipo > 4 ){
            printf("Clave de producto incorrecto, vuelva a intentar  \n");
            scanf("%d %d", &equipo, &veces);
        }
        cantidades[equipo] = veces;
        getchar();
        printf(" Desea agregar mas productos (s/n): ");
        palabra = getchar();
        getchar();
    }while(palabra == 's');
}

void mostrar_menu(){
        printf("A-Ver paquetes de productos\n");
        printf("B-Cotizar productos\n");
        scanf("%c", &paquete);
        switch(paquete){
            case 'A':
            case 'a':
                mostrar_lista_paquetes();
                break;
            case 'B':
            case 'b':
                cotizar_equipos();
                mostrar_equipos();
                break;
        }
}

//Funcion principal
int main(void){
    do{
        system("cls");
        printf("Bienvenido - Equipos de itercomunicacion para su empresa \n\n");
        printf("Que operacion desea realizar? \n");

        mostrar_menu();
        getchar();
        printf(" Desea realizar otra operacion (s/n): ");
        palabra = getchar();
        getchar();
    }while(palabra == 's');
}
