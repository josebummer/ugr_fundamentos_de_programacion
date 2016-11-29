////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////


/*
	Cread una función que calcule el máximo entre tres double
*/

#include <iostream>
#include <string>
using namespace std;

/*
	Dentro de una función que realiza cómputos, JAMÁS leeremos los datos dentro de ella.
	Si ejecutamos cin dentro de la función, ésta ya no puede usarse en un entorno (Windows por ejemplo) en
	el que no funcione cin.
	Además, la función SÓLO sirve para calcular el máximo de tres valores 
	que vengan de la entrada por defecto y no de otros tres valores cualesquiera.
*/

double MaxSuspenso(){   // Suspenso garantizado :-(
	double max;
	double un_valor, otro_valor, el_tercero;
	const string MENSAJE_ENTRADA = "\nIntroduzca un valor entero ";

	cout << MENSAJE_ENTRADA;
	cin >> un_valor;
	cout << MENSAJE_ENTRADA;
	cin >> otro_valor;
	cout << MENSAJE_ENTRADA;
	cin >> el_tercero;

	if (un_valor >= otro_valor)
		max = un_valor;
	else
		max = otro_valor;

	if (el_tercero >= max)
		max = el_tercero;

	return max;
}


/*
int main(){
	double maximo_de_los_tres;
	
	maximo_de_los_tres = MaxSuspenso();

	cout << "\nEl máximo es " << maximo_de_los_tres;

	cout << "\n\n";
	system("pause");
}
*/


double Max3(double un_valor, double otro_valor, double el_tercero){   // :-)
	double max;

	if (un_valor >= otro_valor)
		max = un_valor;
	else
		max = otro_valor;

	if (el_tercero > max)
		max = el_tercero;

	return max;
}



/*
int main(){ 
	const string MENSAJE_ENTRADA = "\nIntroduzca un valor entero ";
	double uno, dos, tres;
	double maximo_de_los_tres;

	cout << MENSAJE_ENTRADA;
	cin >> uno;
	cout << MENSAJE_ENTRADA;
	cin >> dos;
	cout << MENSAJE_ENTRADA;
	cin >> tres;

	maximo_de_los_tres = Max3(uno, dos, tres);

	cout << "\nEl máximo es " << maximo_de_los_tres;

	cout << "\n\n";
	system("pause");
}
*/

// Y si queremos, también podemos crear una función para leer un entero

double LeeEntero(string mensaje){
	int entero;
	
	cout << mensaje;
	cin >> entero;
	
	return entero;
}

/*
int main(){
	const string MENSAJE_ENTRADA = "\nIntroduzca un valor entero ";
	double uno, dos, tres;
	double maximo_de_los_tres;

	uno  = LeeEntero(MENSAJE_ENTRADA);
	dos  = LeeEntero(MENSAJE_ENTRADA);
	tres = LeeEntero(MENSAJE_ENTRADA);

	maximo_de_los_tres = Max(uno, dos, tres);

	cout << "\nEl máximo es " << maximo_de_los_tres;

	cout << "\n\n";
	system("pause");
}
*/

/*
   ¿Y si queremos calcular el máximo de 4 valores?
   ¿Tendríamos que crear la función Max con 4 parámetros?
   Este ejemplo pone de manifiesto que deberíamos intentar diseñar las funciones
   para que sean lo más reutilizables en el futuro.
   En el caso que nos ocupa, tal vez sería mejor construir una única función
   que calcule el máximo de DOS valores, y si necesitamos calcular
   el máximo de tres, lo haríamos llamando dos veces a la función.
*/

double Max2(double un_valor, double otro_valor){   // :-)
	double max;

	if (un_valor >= otro_valor)
		max = un_valor;
	else
		max = otro_valor;

	return max;
}


int main(){
	const string MENSAJE_ENTRADA = "\nIntroduzca un valor entero ";
	double uno, dos, tres;
	double maximo_de_los_tres;

	uno  = LeeEntero(MENSAJE_ENTRADA);
	dos  = LeeEntero(MENSAJE_ENTRADA);
	tres = LeeEntero(MENSAJE_ENTRADA);

	maximo_de_los_tres = Max2( Max2(uno, dos), tres);

	cout << "\nEl máximo es " << maximo_de_los_tres;

	cout << "\n\n";
	system("pause");
}

/*
   Finalmente, indicar que podemos llamar a Max3 y Max2 de la misma forma, Max.
   Esto es posible porque en C++ las funciones se pueden "sobrecargar"
   Pueden llamarse igual pero deben diferenciarse o bien en el número de parámetros
   o bien en el tipo de éstos.
*/



