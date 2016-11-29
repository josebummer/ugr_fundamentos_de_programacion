#include <iostream>

//Segundos entre 2 instantes.

using namespace std;

int main () {
	
	double hora_inicial, minuto_inicial, segundo_inicial, hora_final, minuto_final, segundo_final, segundos_finales;
	
	cout << "Introduce la hora inicial: ";
	cin >> hora_inicial;
	
	cout << "Introduce el minuto inicial: ";
	cin >> minuto_inicial;
	
	cout << "Introduce el segundo inicial: ";
	cin >> segundo_inicial;
	
	cout << "Introduce la hora final: ";
	cin >> hora_final;
	
	cout << "Introduce el minuto final: ";
	cin >> minuto_final;
	
	cout << "Introduce el segundo final: ";
	cin >> segundo_final;
	
	segundos_finales = (((hora_final*60*60) + (minuto_final*60) + segundo_final) - ((hora_inicial*60*60) + (minuto_inicial*60) + segundo_inicial));

	cout << "Los segundos que hay entre las " << hora_final << ":" << minuto_final << ":" << segundo_final << " y las " << hora_inicial << ":" << minuto_inicial << ":" << segundo_inicial << " son:\n" << segundos_finales << "\n\n";
	
	system("pause");


}
