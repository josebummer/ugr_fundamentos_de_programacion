#include <iostream>

using namespace std;

int main(){
	
	int numero;
	char caracter;
	
	caracter = '8';
	numero = caracter - '0'; // 0 = 48 porque es el valor en ASCII del 0
	
	cout << "El valor entero del caracter es: " << numero << "\n\n";
	
	system("pause");

}
