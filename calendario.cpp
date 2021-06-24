#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <iomanip>
#include <time.h>
using namespace std;

class fechadia{
    int dia, mes, anio;
public:
    fechadia();
    fechadia(int a, int b, int c);
    fechadia(const fechadia &a);
    void setFechadia(int a, int b, int c);
    int calcularFechadia();
    void mostrarDiaFecha();
	int calculaTotalDiasMes();
};
fechadia::fechadia(){
    setFechadia(1, 1, 2016);
}
fechadia::fechadia(int a, int b, int c){
    setFechadia(a, b, c);
}
fechadia::fechadia(const fechadia &a){
    setFechadia(a.dia, a.mes, a.anio);
}
void fechadia::setFechadia(int a, int b, int c){
    dia=a; mes=b; anio=c;
}
/*
	Metodo que determina el numero del dia de la semana de una fecha
*/
int fechadia::calcularFechadia(){
    int cof_a, cof_b, cof_c, cof_d, cof_e;

	//Determinamos el coeficiente del siglo
	if( anio >= 1900 || anio <= 1999 ) cof_a = 1;
    else if( anio >= 2000 || anio <= 2099 ) cof_a = 0;
    else if( anio >= 2100 || anio <= 2100 ) cof_a = -2;

	//Determinamos el coeficiente del anio sumandole un cuarto a los 2 ultimos digit del anio
	cof_b = anio%100;
    cof_b = cof_b+(cof_b/4);

	//Determinamos si el anio es bisiesto
    if(anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0)) cof_c = -1;
    else cof_c = 0;

	//Determinamos el coeficiente del mes
	int opc_mes[12] = {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	cof_d = opc_mes[mes-1];

	//El coeficiente del dia solo es el numero del dia
	cof_e = dia;

	//Determinamos el resultado sumando todos los coeficientes y sacando modulo con 7
    return (cof_a + cof_b + cof_c + cof_d + cof_e)%7;
}
void fechadia::mostrarDiaFecha(){
	string nombredias[7] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
	string resultadoFechadia = nombredias[calcularFechadia()];
    cout<<"La fecha "<<dia<<"/"<<mes<<"/"<<anio<<" cayo en: "<<resultadoFechadia<<endl;
}
int fechadia::calculaTotalDiasMes(){
	int totaldm[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return totaldm[mes-1];
}
int main(){

	//Obtenemos la fecha actual dl sistema
	struct tm *tiempo;
	time_t fecha_sistema;
	time(&fecha_sistema);
	tiempo=localtime(&fecha_sistema);
	int arrfechaActual[3] = {tiempo->tm_mday, tiempo->tm_mon + 1, tiempo->tm_year + 1900};

	//Calculamos el numero de dias y el dia en que comienza el mes de la fecha actual
	fechadia objt(1,4,arrfechaActual[2]);
	int diaSemana = objt.calcularFechadia();
	int totalDias = objt.calculaTotalDiasMes();

	//Generamos matriz con los dias del mes
	int matrizMes[6][7];
	int i,j,aux2,aux3;
	aux2 = 0;
	aux3 = 0;
	for( i=0; i<6; i++ ){
		for( j=0; j<7; j++ ){
			if( (aux2 >= diaSemana) && (aux2<=7*6)) ++aux3;
			else aux3 = 0;
			++aux2;
			if( aux3 <= totalDias ) matrizMes[i][j] = aux3;
			else matrizMes[i][j] = 0;
		}
	}

	//Imprimimos calendario
	cout<<arrfechaActual[1]<<"/"<<arrfechaActual[2]<<endl;
	string iniciald[7] = {"D", "L", "M", "M", "J", "V", "S"};
	for( i=0; i<7; i++ ) cout<<iniciald[i]<<"\t";
	cout<<endl;
	for( i=0; i<6; i++ ){
		for( j=0; j<7; j++ ){
			if( matrizMes[i][j] ) cout<<matrizMes[i][j]<<"\t";
			else cout<<" \t";
		}
		cout<<"\n\n";
	}
	system("pause");
}
