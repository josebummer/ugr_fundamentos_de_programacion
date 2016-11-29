// Juan Carlos Ruiz Garcia			26510953-A

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Funcion que se encarga de comprobar que equipo desciende
int Desciende(int desciende,int id_equipo,int puntos,int min_puntos){
	
	/* Esta funcion obtiene los puntos del que va en descenso y los compara con el
		equipo introducido la ultima vez. Si sus puntos son menores devuelve dicho 
		equipo como el que esta en descenso.
	*/
	
	int perdedor;
	
	if(puntos<min_puntos)
		perdedor=id_equipo;
	else
		perdedor=desciende;
		
	return perdedor;
	
}

//Funcion que se encarga de comprobar que equipo va lider.
int Campeon(int asciende, int id_equipo, int puntos, int max_puntos){
	
	/* Esta funcion obtiene los puntos del que va en cabeza y los compara con el
		equipo introducido la ultima vez. Si sus puntos son mayores devuelve dicho equipo
		como el que esta en el liderato.
	*/
	
	int campeon;
	
	if(puntos>max_puntos)
		campeon=id_equipo;
	else
		campeon=asciende;
		
	return campeon;
	
}

// Funcion que se encarga de mostrar los puntos de cada equipo
void Mostrar_equipo(int id_equipo, int puntos){
	
	cout << "El equipo " << id_equipo << " a conseguido: " << puntos << " puntos\n\n";
	
}

// Funcion encargada de calcular los puntos de cada equipo
int Calcular_puntos(int p_ganados, int p_empatados){
	
	/* Esta funcion recibe los partidos ganados y los empatados de un equipo
		y calcula el numero de puntos obtenidos, teniendo en cuenta que cada partido
		ganado son 3 puntos y cada empatado 1.
	*/
	
	int total;
	total=p_ganados*3+p_empatados;
	
	return total;
	
}

// Funcion encargada de pedir los partidos ganados, perdidos y empatados
int Leer_datos(string MENSAJE){
	
	/* Esta funcion recibe un mensaje personalizado y lo muestra en pantalla para
		que el usuario introduzca los datos correspondientes.
	*/
	
	int dato;
	
	do{
	
		cout << MENSAJE;
		cin >> dato;
	
	}while(dato<0);
	
	return dato;
	
}

// Funcion encargada de pedir el identificador de cada equipo
int Leer_equipo(string MENSAJE){
	
	/* Esta funcion recibe un mensaje personalizado y lo muestra en pantalla para
		que el usuario introduzca el id de cada equipo.
	*/
	
	int id_equipo;
	
	do{
	
		cout << MENSAJE;
		cin >> id_equipo;
	
	}while(id_equipo<10000 || id_equipo>99999);
	
	return id_equipo;
	
}

int main(){

	const string MENSAJE_1="Introduce el ID del equipo (5 digitos Ej. 11123): ",MENSAJE_2="Introduce los partidos ganados: ", MENSAJE_3="Introduce los partidos empatados: ",MENSAJE_4="Introduce los partidos perdidos: ";
	int id_equipo,ganados,empatados,perdidos,asciende=0,desciende,c,puntos,max_puntos,min_puntos;
	
	for(c=1;c<=3;c++){
		
		id_equipo=Leer_equipo(MENSAJE_1);
		ganados=Leer_datos(MENSAJE_2);
		empatados=Leer_datos(MENSAJE_3);
		perdidos=Leer_datos(MENSAJE_4);
		
		puntos=Calcular_puntos(ganados,empatados);
		
		Mostrar_equipo(id_equipo,puntos);
		
		//La primera vez el primer equipo toma los valores tanto del que asciende como el que desciende
		if(asciende==0)
		{
			asciende=id_equipo;
			max_puntos=puntos;
			desciende=id_equipo;
			min_puntos=puntos;	
		}
		else{
			
			asciende=Campeon(asciende,id_equipo,puntos,max_puntos);
			desciende=Desciende(desciende,id_equipo,puntos,min_puntos);
			
			//Comparo si el id de asciende es el mismo que el del equipo para cambiar el max_puntos 
			//a comparar con el siguiente equipo que se introduzca
			if(asciende==id_equipo)
				max_puntos=puntos;
				
			//Comparo si el id de desciende es el mismo que el del equipo para cambiar el min_puntos 
			//a comparar con el siguiente equipo que se introduzca
			if(desciende==id_equipo)
				min_puntos=puntos;
			
		}
		
	}
	
	cout << "\n\n";
	cout << "El equipo que asciende es el " << asciende << " con " << max_puntos << " puntos.\n";
	cout << "El equipo que desciende es el " << desciende << " con " << min_puntos << " puntos.\n";
	
}
