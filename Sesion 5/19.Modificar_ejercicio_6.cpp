/*Modifiquemos el ejercicio 6 del capital y los intereses de la primera relaci�n. Supongamos
ahora que se quiere reinvertir todo el dinero obtenido (el original C m�s los
intereses producidos) en otro plazo fijo a un a�o y as�, sucesivamente. Construid un
programa para que lea el capital, el inter�s y un n�mero de a�os N, y calcule e imprima
todo el dinero obtenido durante cada uno de los N a�os, suponiendo que todo
lo ganado (incluido el capital original C) se reinvierte a plazo fijo durante el siguiente
a�o. El programa debe mostrar una salida del tipo:*/

#include <iostream>

using namespace std;

int main(){

	double capital, interes;										//Declaramos las variables
	int anios,i=1;
	
	cout << "Introduce el capital: ";							//Pedimos los datos de entrada
	cin >> capital;
	cout << "Introduce el interes: ";
	cin >> interes;
	cout << "Introduce los a�os: ";
	cin >> anios;
	
	while (i<=anios){																				//Realizamos el condicional
	
		cout << "Total en el a�o numero " << i << ": " << capital << ".\n";		//Mostramos por pantalla a�o por a�o
		capital += capital * (interes/100);													//Realizamos la operacion
		i++;	
	
	}
	
	system("pause");
}
