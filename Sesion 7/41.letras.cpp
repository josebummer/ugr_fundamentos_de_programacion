/*Escribid un programa que lea cuatro valores de tipo char
(min_izda, max_dcha, min_dcha, max_dcha) e imprima las parejas que
pueden formarse con un elemento del conjunto {min_izda ... max_izda} y
otro elemento del conjunto {min_dcha ... max_dcha}. Por ejemplo, si
min_izda = b, max_izda = d, min_dcha = j, max_dcha = m, el programa
debe imprimir las parejas que pueden formarse con un elemento de {b c d} y otro
elemento de {j k l m}, es decir:*/

#include <iostream>

using namespace std;

int main(){

	char min_izda, max_izda, min_dcha, max_dcha,aux;					//Creamos las variables
	
	cout <<"Introduce el minimo de la izquierda: ";						//Pedimos los datos para introducirlos en las variables.
	cin >> min_izda;
	cout << "Introduce el maximo de la izquierda: ";
	cin >> max_izda;
	cout << "Introduce el minimo de la derecha: ";
	cin >> min_dcha;
	cout << "Introduec el maximo de la derecha: ";
	cin >> max_dcha;
	
	while(min_izda<=max_izda){													//Creamos un bucle que nos llevara desde el valor minimo hasta el maximo.
		aux=min_dcha;																//Creamos un auxiliar para no perder el valor del minimo.
		cout << "\n";
		while(aux<=max_dcha){													//Creamos este segundo bucle anidado que nos va a mostrar las columnas de cada fila
			cout << min_izda << aux << "	";
			aux++;
		}
		min_izda++;
	}

cout << "\n\n";
system("pause");
}
