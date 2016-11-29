/*Ampliad el ejercicio 10 de la relación de problemas I, para que, una vez calculada la
media y la desviación, el programa imprima por cada uno de los valores introducidos
previamente, si está por encima o por debajo de la media.*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {

	double altura_uno, altura_dos, altura_tres, media;							//Introducimos las variables
	double desviacion_final, desviacion1, desviacion2, desviacion3;
	const double n = 3;
	
	cout << "Introduce la altura de la primera persona: "; 					//Pedimos los datos de entrada
	cin >> altura_uno;
	cout << "Introduce la altura de la segunda persona: ";
	cin >> altura_dos;
	cout << "Introduce la altura de la tercera persona: ";
	cin >> altura_tres;
	
	media = 1/n * (altura_uno + altura_dos + altura_tres);					// Realizamos las operaciones
	desviacion1 = pow(altura_uno - media,2);
	desviacion2 = pow(altura_dos - media,2);
	desviacion3 = pow(altura_tres - media,2);
	desviacion_final = sqrt(1/n * (desviacion1 + desviacion2 + desviacion3));

	cout << "La media aritmetica de las alturas de estas tres persona es: " << media << ".\nLa desviacion tipica es: " << desviacion_final << "\n\n";
	
	if (altura_uno > media)													// Sacamos que valor es mayor o menor o igual que la media.
		cout << altura_uno << " es mayor que la media.\n";
	else if (altura_uno < media)
		cout << altura_uno << " es menor que la media.\n";
	else
		cout << altura_uno << " es igual que la media.\n\n";
		
		if (altura_dos > media)
		cout << altura_dos << " es mayor que la media.\n";
	else if (altura_dos < media)
		cout << altura_dos << " es menor que la media.\n";
	else
		cout << altura_dos << " es igual que la media.\n\n";
		
		if (altura_tres > media)
		cout << altura_tres << " es mayor que la media.\n";
	else if (altura_tres < media)
		cout << altura_tres << " es menor que la media.\n";
	else
		cout << altura_tres << " es igual que la media.\n\n";
	
	system("pause");

}
