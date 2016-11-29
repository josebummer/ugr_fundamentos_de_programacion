/*Cread una función que calcule el máximo entre tres double. La cabecera de la función
será la siguiente:

double Max(double un_valor, double otro_valor, double el_tercero)

Construid un programa principal que llame a dicha función con unos valores leídos
desde teclado. Supongamos que dichos valores los leemos con cin dentro de la propia
función, en vez de hacerlo en el main. El suspenso está garantizado ¿Por qué?*/

#include <iostream>

using namespace std;

double Max(double un_valor, double otro_valor, double el_tercero){			//Creamos la funcion para comprobar el maximo, que nos va a devolver un numero real.

	double mayor;
	
	if (un_valor>otro_valor){																//Comprobamos si el primer valor es el mas grande de los 3.
		if (un_valor>el_tercero)
			mayor=un_valor;
		else																						//Comprobamos a exepcion que el 3 valor es el mayor.
			mayor=el_tercero;
	}
	else{
		if(otro_valor>un_valor){															//Comprobamos si el 2 valor es el mas grande de todos.
			if(otro_valor>el_tercero)
				mayor=otro_valor;
			else																					//Comprobamos a excepcion que el tercero es el mas grande de todos.
				mayor=el_tercero;
			}
	}
	
	return mayor;																				//Devolvemos el resultado con el valor mas grande.
}

int main(){

	double uno,dos,tres,mayor;									//Introducimos las variables
	
	cout << "Introduce el primer numero: ";				//Preguntamos para obtener unos valores para las variables
	cin >> uno;
	cout << "Introduce el segundo numero: ";
	cin >> dos;
	cout << "Introduce el tercer valor: ";
	cin >> tres;

	mayor=Max(uno,dos,tres);									//Hacemos la llamada a la funcion para que nos ejecute los pasos necesarios.

	cout << "\nEl valor mas grande es " << mayor << "\n\n";		//Mostramos el resultado.
	
system("pause");
}
