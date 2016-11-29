/* En este ejercicios vamos a crear 3 expresiones logicas para comprobar si los datos
introducidos son verdad o no.*/

#include <iostream>

using namespace std;

int main () {

	char letra; // Variables de entrarda.
	int edad, anio; //Variables de entrada.
	bool letra_minuscula, menor_mayor_edad, anio_bisiesto; //Nos van a permitir comprobar si son verdaderas o falsas las expresiones.
	
	cout << "Introduce un caracter: ";
	cin >> letra;
	
	letra_minuscula = letra >= 'a'; 		// Nos devolvera true si se cumple la condicion y false si no se cumple.
	
	cout << "Introduce una edad: ";
	cin >> edad;
	
	menor_mayor_edad = edad < 18 || edad > 65;
	
	cout << "Introduce un año: ";
	cin >> anio;

	anio_bisiesto = ((anio%4 == 0) && (anio%100 != 0)) || (anio%400 == 0);
	
	cout << "Vamos a comprobar si la letra introducida es minuscula: " << letra_minuscula << "\n\n";
	cout << "Vamos a comprobar si la edad introducida es menor que 18 o mayor que 65: " << menor_mayor_edad << "\n\n";
	cout << "Vamos a comprobar si el año introducido es año bisiesto: " << anio_bisiesto << "\n\n";
	
	system("pause");
}
