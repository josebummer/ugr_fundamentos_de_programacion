#include <iostream>

//Pasar una letra mayuscula a una minuscula.

using namespace std;

int main() {
	
	char letra;
	
	cout << "Introduce la letra mayuscula: ";
	cin >> letra;
	
	letra = letra + 32;
	
	cout << "La letra en minuscula es " << letra << "\n\n";

	system("pause");

}
