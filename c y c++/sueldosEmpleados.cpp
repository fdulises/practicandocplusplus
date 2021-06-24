/*
* Programa que muestra una lista de empleados
* permite consultar sus datos,
* ver su salario con aumento o disminucion dependiendo del tiempo que llevan trabajando
*/

//Incluye librerias a usar
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Define moldes de funcioes a usar
void verEmpleados();
void escojerEmpleado(int num);
void aumetarSueldo(int num);
void disminuirSueldo(int num);

//Define arreglo de punteros con los datos de los empleados
char *empleados[10][3] = {
    {
        //Nombre añostrbajando salario
        "pepe","10","1500"
    },
    {
        "juan","30","1500"
    },
    {
        "oscar","20","3000"
    },
    {
        "lalo","25","1200"
    },
    {
        "pedro","31","4500"
    },
    {
        "toño","12","1000"
    },
    {
       "misael","30","2500"
    },
    {
       "isamel","24","6500"
    },
    {
        "ulises","17","2500"
    },
    {
        "ceron","24","3500"
    }
};

//Funcion principal
int main(int argc, const char * argv[]) {
    //Define variables a usar
    char caracter;
    int numero;
    int *puntero;

    do{
        verEmpleados();
        printf("Escoja el numero del empleado: ");
        scanf("%d",&numero);
        getchar();
        puntero =&numero;
        puntero--;
        char clave;
        do{
            char opcion;
            printf("Que desea hacer con su empleado: \n");
            printf("A.- ver todos sus datos \n");
            printf("B.- ver aumento de sueldo  \n");
            printf("C.- ver disminucion de sueldo \n");
            scanf("%c",&opcion);
            switch(opcion) {
                case 'A':
                case 'a':
                    escojerEmpleado(numero);
                break;
                case 'B' :
                case 'b' :
                    aumetarSueldo(numero);
                break;
                case 'C' :
                case 'c' :
                    disminuirSueldo(numero);
                break;
                default :
                    printf("Opcion no valida \n" );}
            getchar();
            printf(" Desea seguir editando a este empleado (s/n): ");
            clave = getchar();
            getchar();
        }while(clave == 's');

        printf(" Desea seguir editando a sus empleados (s/n): ");
        caracter = getchar();
        getchar();
    }while(caracter == 's');
    return 0;
}
//Funcion que mu
void verEmpleados(){
    int d;
    for(d= 0; empleados[d][0]; d++)
        printf("%d.- %s \n",d+1,empleados[d][0] );
}

//Funcion que selecciona un empleado
void escojerEmpleado(int num){
    int d;
    for(d= 0; empleados[d][0]; d++)
        if(num == d)
            printf("El nombre del empleado es %s, trabaja desde hace %s años y gana un salario de %s pesos  \n",empleados[d][0],empleados[d][1], empleados[d][2] );

}

//Funcion que hace el aumento al sueldo
void aumetarSueldo(int num){
    int d;
    int cantidad;
    int resultado;
    for(d= 0; empleados[d][0]; d++)
        if(num == d){
            cantidad = atoi(empleados[d][2]);
            resultado = cantidad + (cantidad/100);
            printf("El aumento de sueldo con respecto a numero de años en le empresa serian %d pesos \n",resultado);
        }
}

//Funcion que baja el sueldo
void disminuirSueldo(int num){
    int d;
    int cantidad;
    int resultado;
    for(d= 0; empleados[d][0]; d++)
        if(num == d){
            cantidad = atoi(empleados[d][2]);
            resultado = cantidad - (cantidad/100);
            printf("La disminucion  del sueldo con respecto a numero de años en le empresa serian %d pesos \n",resultado);
        }
}
