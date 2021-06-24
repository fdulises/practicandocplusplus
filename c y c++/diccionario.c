#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void verPalabras();
int editarpalabra();
int buscarPalabra();


char *diccionario[9][2] = {
    {
        "c","C es un lenguaje de programación originalmente desarrollado por Dennis M. Ritchie entre 1969 y 1972 en los Laboratorios Bell,"
    },
    {
        "php","PHP es un lenguaje de programación de uso general de código del lado del servidor originalmente diseñado para el desarrollo web de contenido dinámico."
    },
    {
        "java","Java es un lenguaje de programación de propósito general, concurrente, orientado a objetos que fue diseñado específicamente para tener tan pocas dependencias de implementación como fuera posible."
    },
    {
        "javaScript","JavaScriptes un lenguaje de programación interpretado, dialecto del estándar ECMAScript. Se define como orientado a objetos,3 basado en prototipos, imperativo, débilmente tipado y dinámico."
    },
    {
        "c++","C++ es un lenguaje de programación diseñado a mediados de los años 1980 por Bjarne Stroustrup. La intención de su creación fue el extender al lenguaje de programación C mecanismos que permiten la manipulación de objetos."
    },
    {
        "c#"," c# es un lenguaje de programación orientado a objetos desarrollado y estandarizado por Microsoft como parte de su plataforma .NET, que después fue aprobado como un estándar por la ECMA"
    },
    {
        "ruby"," Ruby es un lenguaje de programación interpretado, reflexivo y orientado a objetos, creado por el programador japonés Yukihiro  Matsumoto, quien comenzó a trabajar en Ruby en 1993, y lo presentó públicamente en 1995. "
    },
    {
        "python","Python es un lenguaje de programación interpretado cuya filosofía hace hincapié en una sintaxis que favorezca un código legible"
    },
    {
        ".net","NET es un framework de Microsoft que hace un énfasis en la transparencia de redes, con independencia de plataforma de hardware y que permita un rápido desarrollo de aplicaciones."
    }

};
char pal[20];
char edit[30];
int main(int argc, const char * argv[]) {
    char palabra;
    int n;
    do{
        printf("1.- Ver todas las palabras \n");
        printf("2.- Buscar palabra \n");
        printf("3.- Sustituir palabra \n");
        scanf("%d",&n);
        switch(n) {
            case 1:
                verPalabras();
                break;
            case 2:
                buscarPalabra();
                break;
            case 3:
                editarpalabra();
                break;
            default :
                printf("Opcion no valida \n" );
        }
        getchar();
        printf(" Desea seguir en este programa (s/n): ");
        palabra = getchar();
        getchar();
    }while(palabra == 's');
    return 0;
}
void verPalabras(){
    int i;
    for(i=0; diccionario[i][0]; i++)
        printf("%d.- %s \n",i+1,diccionario[i][0] );

}
int editarpalabra(){
    int i;
    getchar();
    printf("Que palabra quieres cambiar:  ");
    scanf("%s",pal);
    printf("Por que palabra quiere sustituirla:  ");
    scanf("%s",edit);
    for(i= 0; diccionario[i][0];i++)
        if(!strcmp(diccionario[i][0],pal)){
            diccionario[i][0] = edit;
            return 1;
        }
    printf("Palabra no encontrada. \n ");
    return 0;

}
int buscarPalabra(){
    int i;
    getchar();
    printf("Que palabra quieres buscar:  ");
    scanf("%s",pal);
    for(i= 0; diccionario[i][0];i++)
        if(!strcmp(diccionario[i][0],pal)){
            printf("%s \n",diccionario[i][1]);
            return 1;
        }
    printf("Palabra no encontrada. \n ");
    return 0;
}
