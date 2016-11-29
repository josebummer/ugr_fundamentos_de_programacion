#include <iostream>
#include <cmath>
using namespace std;

//Gaussiana

int main() {
	
	double esperanza, desviacion, abcisa, funcion;
	const double PI=3.1415;
	
	cout << "Introduce el valor de la esperanza: ";
	cin >> esperanza;
	
	cout << "Introduce el valor de la desviacion tipica: ";
	cin >> desviacion;
	
	cout << "Introduce el valor de la abcisa: ";
	cin >> abcisa;
	
	funcion = (1/(desviacion*sqrt(2*PI))) * (exp((-1)/2 * (pow((abcisa-esperanza)/desviacion, 2))));
	
	cout << "La funcion tiene el valor: " << funcion << "\n\n";
	
	system("pause");
	
}
