// Ejercicio 13 calcular la renta final de una persona

#include <iostream>
#include <string>

using namespace std;

int main () {

	char autonomo, pensionista;															//Declaramos las variables
	string estado_civil;
	double renta_bruta, renta_final;
	int retencion_inicial;

	cout << "¿Eres autonom@? (S/N): ";													// Preguntamos por los datos de entrada
	cin >> autonomo;
	cout << "Eres pensionista? (S/N): ";
	cin >> pensionista;
	cout << "Cual es tu estado civil (soltero, casado,....): ";
	cin >> estado_civil;
	cout << "Cual es tu renta bruta: ";
	cin >> renta_bruta;
	cout << "Retencion inicial: ";
	cin >> retencion_inicial;
	
	if (autonomo == 'S' || autonomo == 's')											// Empezamos a realizar las comparaciones
		retencion_inicial = retencion_inicial - 3;
	else
		if (pensionista == 'S' || pensionista == 's')
			retencion_inicial = retencion_inicial + 1;
		else{
			retencion_inicial = retencion_inicial + 2;
			if (renta_bruta <= 20000)
				retencion_inicial = retencion_inicial + 2;
			else 
				if ((estado_civil == "casado" || estado_civil == "Casado"))
					retencion_inicial = retencion_inicial + 2.5;
				if ((estado_civil == "soltero" || estado_civil == "Soltero"))
					retencion_inicial = retencion_inicial + 3;
		}
	renta_final = renta_bruta - renta_bruta*retencion_inicial/100;				// Sacamos la renta final
	
	cout << fixed;
	cout << "\nLa renta final es: " << renta_final << "\n\n";					// Mostramos la renta final por pantalla
	
	system("pause");
}
