#include <iostream>

using namespace std;

// Poblacion en China

int main() {
	const double nace=1.87, muere=3.27, emigra=71.9;
	const int poblacion_actual=1375570814, segundos_2anos =63072000;
	int personas_nacen, personas_mueren, personas_emigran, poblacion_final;
	
	personas_nacen = segundos_2anos/nace;
	personas_mueren = segundos_2anos/muere;
	personas_emigran = segundos_2anos/emigra;
	
	poblacion_final = (personas_nacen-personas_mueren-personas_emigran) + poblacion_actual;
	
	cout << "La poblacion de china actual es 1375570814.\nDentro de 2 años la poblacion sera: " << poblacion_final << "\n\n";
	
	system("pause");

}
