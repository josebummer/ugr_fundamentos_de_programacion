#include <iostream>

//Salario entre dise�ador y fabricantes.

using namespace std;

int main() {

	const int DISENADORES=1, FABRICANTES=3;
	double salario_total, salario_disenadores, salario_fabricantes;
	
	cout << "Introduce el salario total que cobran entre todos: ";
	cin >> salario_total;
	
	salario_fabricantes = salario_total/(FABRICANTES+DISENADORES*2);
	salario_disenadores = salario_fabricantes * 2;

	cout << "El/Los dise�ador/es cobra/n " << salario_disenadores << " y los fabricantes cobran " << salario_fabricantes << " cada uno.\n\n";
	
	system("pause");

}
