#include <iostream>
#include <string>

using namespace std;

int LeerCodigo(){

	int codigo;
	
	do{
		cout << "Introduce un codigo de equipo (10000-99999): ";
		cin >> codigo;
	}while(codigo<10000 || codigo>99999);

return codigo;
}

int LeerDatos(string TEXTO){

	int dato;
	
	do{
		cout << TEXTO;
		cin >> dato;
	}while(dato<0);

return dato;
}

int CalcularPuntos(int ganados, int empatados, int perdidos){

	int puntos=ganados*3+empatados*1+perdidos*0;

return puntos;
}

bool NuevoCampeon(int pcampeon, int pactuales){

	bool campeon=false;

	if(pactuales>pcampeon)
		campeon=true;
		
return campeon;
}

bool NuevoPerdedor(int pperdedor, int pactuales){

	bool perdedor=false;
	
	if(pactuales<pperdedor)
		perdedor=true;

return perdedor;
}

int main(){

	const string TEXT_GANADOS="Introduce los partidos ganados: ", TEXT_EMPATADOS="Introduce los partidos empatados: ", TEXT_PERDIDOS="Introduce los partidos perdidos: "; 
	int cequipo, ganados, empatados, perdidos, i, puntos, pcampeon, pperdedor, ccampeon, cperdedor;
	bool nuevocampeon, nuevoperdedor;
	
	cequipo=LeerCodigo();
	ganados=LeerDatos(TEXT_GANADOS);
	empatados=LeerDatos(TEXT_EMPATADOS);
	perdidos=LeerDatos(TEXT_PERDIDOS);
	
	puntos=CalcularPuntos(ganados,empatados,perdidos);
	cout << "\nEl equipo tiene " << puntos << " puntos.\n\n";
	
	pperdedor=puntos;
	cperdedor=cequipo;
	ccampeon=cequipo;
	pcampeon=puntos;
	
	for(i=0;i<9;i++){
		
		cequipo=LeerCodigo();
		ganados=LeerDatos(TEXT_GANADOS);
		empatados=LeerDatos(TEXT_EMPATADOS);
		perdidos=LeerDatos(TEXT_PERDIDOS);
		
		puntos=CalcularPuntos(ganados,empatados,perdidos);
		cout << "\nEl equipo tiene " << puntos << " puntos.\n\n";
		
		nuevocampeon=NuevoCampeon(pcampeon, puntos);
		nuevoperdedor=NuevoPerdedor(pperdedor, puntos);
		
		if(nuevocampeon){
			pcampeon=puntos;
			ccampeon=cequipo;
		}
		if(nuevoperdedor){
			pperdedor=puntos;
			cperdedor=cequipo;
		}
	}
	
	cout << "\n\nEl equipo campeon es " << ccampeon << " con " << pcampeon << " puntos.\n";
	cout << "El equipo perdedor es " << cperdedor << " con " << pperdedor << " puntos\n\n";
	
system("pause");
}
