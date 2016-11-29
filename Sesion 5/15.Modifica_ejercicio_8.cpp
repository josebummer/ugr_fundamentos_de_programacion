/*Recupere la soluci�n del ejercicio 8 y resu�lvalo separando entradas y salidas de
los c�mputos. Para ello, utilice una variable de tipo enumerado que represente las
opciones de que un car�cter sea una may�scula, una min�scula o un car�cter no
alfab�tico.*/

// letra convertida = letra original + ('a'-'A')

#include <iostream>

using namespace std;

int main(){

	char letra_original, letra_convertida;								//Creamos las variables
	bool mayuscula=false,minuscula=false;
	
	cout << "Introduce un caracter: ";									//Pedimos los datos de entrada
	cin >> letra_original;
	
	if (letra_original >= 'A' && letra_original <= 'Z')			//Realizamos las comparaciones
		mayuscula=true;
	else 
		if (letra_original >= 'a' && letra_original <= 'z')
			minuscula=true;
	
	if (mayuscula)																//Realizamos los cambios
		letra_convertida = letra_original + ('a'-'A');
	else
		if (minuscula)
			letra_convertida = letra_original - ('a'-'A');
		else
			letra_convertida = letra_original;
			
	cout << "\nEl caracter/letra convertida es: " << letra_convertida << "\n\n";			//Mostramos el resultado

	system("pause");
}
