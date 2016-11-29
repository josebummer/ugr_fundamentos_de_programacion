#include <iostream>
using namespace std;

//Calcular el area del circulo

int main() {
	
	double radio,area, longitud;
	const double PI=3.1416;
	
	cout << "Introduce el radio de circulo: ";
	cin >> radio;
	
	longitud = 2*PI*radio;
	
	area = PI * (radio*radio);
	
	cout << "La longitud del circulo es: " << longitud << "\n";
	cout << "El area del circulo es: " << area << "\n\n";
	
	system("pause");
	
}
