/*
Recupere la solución del ejercicio 6 de esta relación de problemas (cómputo del salario
en función de las horas trabajadas) Defina una clase Nomina para gestionar el
cómputo del salario final. Suponga que el porcentaje de incremento en la cuantía de
las horas extras (50 %) y el número de horas que no se tarifan como extra (40) son
valores que podrían cambiar, aunque no de forma continua. El número de horas trabajadas
y la cuantía a la que se paga cada hora extraordinaria, sí son cantidades que
varían de un trabajador a otro.
*/

#include <iostream>

using namespace std;

class Nomina{
	private:
		const int HORASMAX=40;										//Creamos la constante que indica el numero de horas maximas
		const int PORCENTAJE=50;									//Creamos la constante que indica el porcentaje que se aplica a las horas extras
		int horas_trabajadas,precio_hora;						//Creamos las variables de la clase
	public:
		
		Nomina(){												//Creamos el contructor por defecto
			horas_trabajadas=1;
			precio_hora=1;
		}
		Nomina(int valorhoras,int valorprecio){			//Creamos un constructor para indicar los datos iniciales al crear el objeto
			horas_trabajadas=valorhoras;
			precio_hora=valorprecio;
		}
		
		void SetHoras(int valorhoras){							//Este modulo nos va a permitir darle valor a las horas trabajadas
			horas_trabajadas=valorhoras;
		}
		int GetHoras(){											//Nos muestra por pantalla el valor de las horas trabajadas
			return horas_trabajadas;
		}
		
		void SetPrecio(int valorprecio){							//Nos permite darle valor a la variable precio hora
			precio_hora=valorprecio;
		}
		
		double SalarioTrabajador(){								//Con esto calcularemos el salario del trabajador dependiendo de los datos que tenga la nomina
			
			int horas_extras;
			double salario=0;
			
			if(horas_trabajadas>HORASMAX){
				horas_extras=horas_trabajadas-HORASMAX;
				horas_trabajadas-=horas_extras;
		
				salario=horas_extras*(precio_hora+precio_hora*PORCENTAJE/100);
			}
			salario+=horas_trabajadas*precio_hora;
		return salario;
		}

};

int main(){

	int precio_hora,horas;							//Creamos las variables de entrada
	Nomina trabajador;								//Creamos el objeto de la clase Nomina
	
	do{
	cout << "Introduce el precio al que es paga la hora: ";					//Pedimos los datos de entrada
	cin >> precio_hora;
	}while(precio_hora<0);
	trabajador.SetPrecio(precio_hora);												//Insertamos las horas introducidas en la variable de la clase
	do{
	cout << "Introduce el numero de horas trabajadas: ";
	cin >> horas;
	}while(horas<0);
	trabajador.SetHoras(horas);														//Igual que antes pero esta vez introduciendo las horas
	
	cout << "\nEl trabajador ha ganado: " << trabajador.SalarioTrabajador() << " euros.\n\n";			//Mostramos el resultado

system("pause");
}
