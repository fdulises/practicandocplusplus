#include <iostream>

using namespace std;

class trabajador{
	int numempl;
	string nombre;
	struct ingreso{
		int anio = 2016;
		int mes = 9;
		int dia = 5;
	} fecha;
	float sueldo;
	string sindicato;
public:
	trabajador(string a, int b, string c, float d){
		editar(a, b, c, d);
	}
	void editar(string a, int b, string c, float d){
		nombre = a;
		numempl = b;
		sindicato = c;
		sueldo = d;
	}
	void Aumentarsueldo(int a){
		sueldo += a;
	}
	float Pagosemanal(){
		return sueldo;
	}
	void Mostrar(){
		cout<<"Nombre del trabajador: "<<nombre<<endl;
		cout<<"Numero de trabajador: "<<numempl<<endl;
		cout<<"Sindacato del trabajador: "<<sindicato<<endl;
		cout<<"Sueldo del trabajador: "<<Pagosemanal()<<endl;
		cout<<"Fecha de ingreso: "<<fecha.dia<<"/"<<fecha.mes<<"/"<<fecha.anio<<endl;
	}
};

int main(){
	trabajador juliancito("Juliancito", 1, "Lorem", 15000);
	juliancito.Mostrar();

	return 0;
}
