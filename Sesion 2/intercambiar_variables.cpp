#include <iostream>

//Intercambiar variables.

using namespace std;

int main() {

	int edad_Pedro, edad_Juan, a;
	
	cout << "Introduce la edad de Pedro: ";
	cin >> edad_Pedro;
	
	cout << "Introduce la edad de Juan: ";
	cin >> edad_Juan;

	cout << "A indicado que Pedro tiene " << edad_Pedro << " años, y Juan tiene " << edad_Juan << " años. Vamos a intercambiar los valores.\n";
	
	a = edad_Pedro;
	edad_Pedro = edad_Juan;
	edad_Juan = a;

	cout << "Ahora Pedro tiene " << edad_Pedro << " años, y Juan tiene " << edad_Juan << " años.\n\n";
	
	system("pause");
}
