#include <iostream>

//Transformar las horas minutos y segundos mayores, a hora real.

using namespace std;

int main() {
	
	int horas, minutos, segundos,s,m,dias;
	
	cout << "Introduce las horas: ";
	cin >> horas;
	
	cout << "Introduce los minutos: ";
	cin >> minutos;
	
	cout << "Introduce los segundos: ";
	cin >> segundos;
	
	s = segundos/60;											// Segundos que sumamos a los minutos.
	segundos = segundos%60;									// Segundos restantes.
	minutos = minutos + s;
	m = minutos/60;
	minutos = minutos%60; 
	horas = horas + m;
	dias = horas/24;
	horas = horas%24;
	
	cout << "La hora real es " << dias << " dias -- "<< horas << ":" << minutos << ":" << segundos << "\n\n";

	system("pause");

}
