#include <iostream>
#include <cstdlib>

using namespace std;

struct materias{
	int clave;
	string nomb;
	string profesor;
	float calificacion;
};

class estudiante{
	long int Matricula;
	string nombre;
	float calificacion;
	string beca;
	materias materia [ 10 ];
	int totalmats = 0;
public:
	estudiante(string a, int b, string c, float d){
		nombre = a;
		Matricula = b;
		beca = c;
		calificacion = d;
	}
	void Buscacalificacion(int nm){
		int i;
		for( i=0; i<totalmats; i++){
			if(nm == materia[i].clave ){
				system("cls");
				cout<<"Materia"<<"\t"<<"Calificacion"<<endl;
				cout<<materia[i].nomb<<"\t"<<materia[i].calificacion<<endl;
			}
		}
	}
	void Materiastomadas(){
		int i;
		cout<<"Clave"<<"\t"<<"Materia"<<"\t"<<"Profesor"<<"\t"<<"Calificacion"<<endl;
		for( i=0; i<totalmats; i++){
			cout<<materia[i].clave<<"\t"<<materia[i].nomb<<"\t"<<materia[i].profesor<<"\t"<<materia[i].calificacion<<endl;
		}
	}
	void Insertarmateria(int numm, string nomm, string profm, int calm){
		materia[totalmats].clave = numm;
		materia[totalmats].nomb = nomm;
		materia[totalmats].profesor = profm;
		materia[totalmats].calificacion = calm;
		totalmats++;
	}
	void Mostrar(){
		cout<<"Matricula del estudiante: "<<Matricula<<endl;
		cout<<"Nombre del estudiante: "<<nombre<<endl;
		cout<<"calificacion del estudiante: "<<calificacion<<endl;
		cout<<"Beca del estudiante: "<<beca<<endl;
	}
};

int main(){
	estudiante objt("Jose", 2016212332, "Telmex", 8.5);
	objt.Insertarmateria(1, "Fisica", "Luis", 9);
	objt.Insertarmateria(2, "Humanidades", "Pepe", 7);
	objt.Insertarmateria(3, "Quimica", "Alberto", 8);

	estudiante obj2("Antonio", 2016267534, "Institucional", 9);
	obj2.Insertarmateria(1, "Calculo", "Enrique", 9);
	obj2.Insertarmateria(2, "Algebra", "Armando", 7);
	obj2.Insertarmateria(3, "Quimica", "Alberto", 8);

	estudiante obj3("Javier", 2016738925, "Telmex", 9.5);
	obj3.Insertarmateria(1, "Calculo", "Enrique", 9);
	obj3.Insertarmateria(2, "Programacion", "Ana", 7);
	obj3.Insertarmateria(3, "Diferencial", "Hugo", 8);

	cout<<"Seleccione un estudiante del 1 al 3"<<endl;
	int numest;
	cin>>numest;
	system("cls");
	cout<<"Seleccione una opcion para el estudiante"<<endl;
	cout<<"1-Buscar calificacion"<<endl;
	cout<<"2-Mostrar materias tomadas"<<endl;
	cout<<"3-Mostrar datos de estudiante"<<endl;
	int opcion;
	cin>>opcion;
	system("cls");
	switch (opcion) {
		case 1:
			cout<<"Ingrese la clave de la materia (1, 2 o 3)"<<endl;
			int opmat;
			cin>>opmat;
			if(numest == 1) objt.Buscacalificacion(opmat);
			if(numest == 2) obj2.Buscacalificacion(opmat);
			if(numest == 3) obj3.Buscacalificacion(opmat);
			break;
		case 2:
			if(numest == 1) objt.Materiastomadas();
			if(numest == 2) obj2.Materiastomadas();
			if(numest == 3) obj3.Materiastomadas();
			break;
		case 3:
			if(numest == 1) objt.Mostrar();
			if(numest == 2) obj2.Mostrar();
			if(numest == 3) obj3.Mostrar();
			break;
	}
	return 0;
}
