/*Se pide leer un carácter desde teclado, obligando al usuario a que sea una letra ma-yúscula. Para ello, habrá que usar una estructura repetitiva do while,
 de forma que si el usuario introduce un carácter que no sea una letra mayúscula, se le volverá a pedir otro carácter. Calculad la minúscula correspondiente
e imprimidla en pantalla. No pueden usarse las funciones tolower ni toupperde la biblioteca cctype.*/

#include <iostream>

using namespace std;

int main(){
	
	char mayuscula,minuscula;

	do{
	
	cout << "\nIntroduce una letra mayuscula: ";
	cin >> mayuscula;
	
	
	}while ((mayuscula < 'A') || (mayuscula > 'Z'));

	minuscula = mayuscula + ('a'-'A');

	cout << "La letra en minuscula es: " << minuscula << "\n\n";
	
	system("pause");
}
