#include <iostream>
using namespace std;

//Calcular el interes bancario

int main() {
	
	double capital, interes, total;
	
	cout << "Introduce el capital: ";
	cin >> capital;
	
	cout << "Introduce el interes: ";
	cin >> interes;
	
	total = capital + capital * (interes/100);
	
	cout << "El interes es: " << total << "\n\n";
	
	system("pause");
	
}

