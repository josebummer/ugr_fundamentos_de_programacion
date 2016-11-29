#include <iostream>
#include <cmath>

// Sacar media y desviaion tipica de 3 alturas de personas

using namespace std;

int main() {

	double altura_uno, altura_dos, altura_tres, media, desviacion_final, desviacion1, desviacion2, desviacion3;
	const double n = 3;
	
	cout << "Introduce la altura de la primera persona: ";
	cin >> altura_uno;
	
	cout << "Introduce la altura de la segunda persona: ";
	cin >> altura_dos;
	
	cout << "Introduce la altura de la tercera persona: ";
	cin >> altura_tres;
	
	media = 1/n * (altura_uno + altura_dos + altura_tres);
	desviacion1 = pow(altura_uno - media,2);
	desviacion2 = pow(altura_dos - media,2);
	desviacion3 = pow(altura_tres - media,2);
	desviacion_final = sqrt(1/n * (desviacion1 + desviacion2 + desviacion3));

	cout << "La media aritmetica de las alturas de estas tres persona es: " << media << ".\nLa desviacion tipica es: " << desviacion_final << "\n\n";
	
	system("pause");

}
