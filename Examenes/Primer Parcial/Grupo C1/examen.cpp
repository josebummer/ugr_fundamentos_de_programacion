

#include <iostream>
#include <string>

using namespace std;

int LeerDorsal(){

	int dorsal;
	
	do{
		cout << "Introduce el dorsal: ";
		cin >> dorsal;
	}while((dorsal<1 || dorsal>6) && (dorsal!=-1));

return dorsal;
}

int LeerPuntos(){

	int puntos;
	
	do{
		cout << "Introduce los puntos: ";
		cin >> puntos;
	}while(puntos<0);

return puntos;
}

int Suma(int numero1, int numero2){

return numero1+numero2;
}

string Maximo(int sumauno, int sumados){

	string ganador="HA GANADO EL EQUIPO 1";
	
	if(sumados > sumauno)
		ganador="HA GANADO EL EQUIPO 2.";

return ganador;
}

string Ganador(int sumauno, int sumados){

	string ganador;
	
	if(sumados==sumauno)
		ganador="LOS EQUIPOS HAN EMPATADO.";
	else
		ganador=Maximo(sumauno,sumados);

return ganador;
}

int main(){

	int dorsal, puntos=0, equipouno=0, equipodos=0;
	string ganador;
	
	dorsal=LeerDorsal();
	
	while(dorsal!=-1){
	
		puntos=LeerPuntos();
		if(dorsal>=1 && dorsal<=3)
			equipouno=Suma(equipouno,puntos);
		else
			equipodos=Suma(equipodos,puntos);
		
		dorsal=LeerDorsal();
	}

	ganador=Ganador(equipouno,equipodos);

	cout << "\n\n" << ganador << "\n\n";

system("pause");
}
