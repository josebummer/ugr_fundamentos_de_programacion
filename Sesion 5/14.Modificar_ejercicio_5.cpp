/*Modificad el ejercicio 5 para que el programa nos diga si los tres valores leídos están
ordenados de forma ascendente, ordenados de forma descendente o no están
ordenados. Para resolver este problema, se recomienda usar una variable de tipo
enumerado.*/

#include <iostream>

using namespace std;

int main() {

	int entero1,entero2,entero3;								//Declaramos las varialbles
	bool ascendente=false,descendente=false;
	cout << "Introduce el primer entero: ";					// Obtenemos el valor de las variables
	cin >> entero1;
	cout << "Introduce el segundo entero: ";
	cin >> entero2;
	cout << "Introduce el tercer entero: ";
	cin >>  entero3;
	
	if (entero1 > entero2 && entero2 > entero3)				//Hacemos las comparaciones
		descendente=true;
	else
		if (entero1 < entero2 && entero2 < entero3)
		ascendente=true;	

	if (descendente)
		cout << "\nLos numero estan ordenados de mayor a menor.\n\n";		//Mostramos los resultados
	else
		if (ascendente)
			cout << "\nLos numeros estan ordenados de menor a mayor\n\n";
		else
			cout << "\nLos numero no estan ordenados\n\n";
		
	system("pause");

}

