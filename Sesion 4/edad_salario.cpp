/*Cread un programa que lea el valor de la edad (dato de tipo entero) y salario (dato de
tipo real) de una persona. Subid el salario un 5% si éste es menor de 300 euros y la
persona es mayor de 65 años. Imprimid el resultado por pantalla. En caso contrario imprimid el mensaje
"No es aplicable la subida". En ambos casos imprimid el salario resultante.*/

#include <iostream>

using namespace std;

int main(){

	int edad;											// Declaramos las variables.
	double salario;
	
	cout << "Introduce la edad: ";					// Pedimos los datos de entrada
	cin >> edad;
	cout << "Introduce el salario: ";
	cin >> salario;
	
	if ((salario < 300) && (edad > 65)) {
		salario = salario*1.05;
		cout << "\nEl salario final es " << salario << "\n\n";
	}
	else
		cout << "\nNo es aplicable la subida.\n\n";

	system("pause");

}
