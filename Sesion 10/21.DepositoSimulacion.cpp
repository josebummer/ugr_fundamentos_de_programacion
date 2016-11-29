/*
Se quiere construir una clase DepositoSimulacion para simular préstamos, ofreciendo
la funcionalidad descrita en los ejercicios 19 (reinvierte capital e interés un
número de años) y 20 (reinvierte capital e interés hasta obtener el doble de la cantidad
inicial) de la relación de problemas II (página RP-II.7). Por tanto, la clase debe
proporcionar, para un capital y unos intereses dados, métodos para:
a) Calcular el capital que se obtendrá al cabo de un número de años,
b) Calcular el número de años que deben pasar hasta obtener el doble de la cantidad
inicial.
A la hora de diseñar la clase, tendremos que analizar cuestiones como:
¿Cuáles son sus datos miembro? Parece claro que el capital y el interés sí lo
serán ya que cualquier operación que se nos ocurra hacer con un objeto de la
clase DepositoSimulacion involucra a ambas cantidades. ¿Pero y el número
de años?
 ¿Qué constructor definimos?
 ¿Queremos modificar el capital y el interés una vez creado el objeto?
 ¿Queremos poder modificarlos de forma independiente?
 ¿Hay alguna restricción a la hora de asignar un valor al capital e interés?
 ¿Es mejor un método para calcular el número de años hasta obtener el doble de
la cantidad inicial, o por el contrario es mejor un método para calcular el número
de años hasta obtener una cantidad específica?
*/

#include <iostream>

using namespace std;

class DepositoSimulacion{		
	private:
		double capital,interes;										//Creamos las variables de la clase
		int anios;
	public:
		DepositoSimulacion(){										//Constructor por defecto
			capital=0.0;
			interes=0;
			anios=0;
		}
		DepositoSimulacion(double valorcapital, double valorinteres, int valoranios){			//Constructor para indicar los datos al crear el objeto
			SetCapital(valorcapital);
			SetInteres(valorinteres);
			SetAnios(valoranios);
		}
		
		void SetValores(double valorcapital, double valorinteres, int valoranios){				//Creamos un modulo para insertar todos los valores a la vez
			SetCapital(valorcapital);
			SetInteres(valorinteres);
			SetAnios(valoranios);
		}
		
		void SetCapital(double valorcapital){							//Modulo para meter el valor del capital
			if(valorcapital>0)
				capital=valorcapital;
		}
		double GetCapital(){													//Modulo que nos devuelve el valor del capital
			return capital;
		}
		
		void SetInteres(double valorinteres){							//Modulo para meter el interes
			if(valorinteres>0)
				interes=valorinteres;
		}
		double GetInteres(){													//Modulo que nos muestra el valor del interes
			return interes;
		}
		
		void SetAnios(int valoranios){									//Modulo para insertar los años
			if(valoranios>0)
				anios=valoranios;
		}
		int GetAnios(){														//Modulo que nos mestra el valor de la variale años
			return anios;
		}
		
		double CapitalAnios(){												//Modulo que nos calcula el capital que tenemos al pasar los años preguntados al usuario.
			int i=1;
			double cap=GetCapital();
			
			while(i<=GetAnios()){
				cap += cap * (interes/100);
				i++;
			}
		return cap;
		}
		
		int DobleCapital(){													//Modulo que nos calcula cuando llegaremos al doble del capital, dandonos el numero de años
			double cap=GetCapital(),doblecap=GetCapital()*2;
			int cantanios=0;
			
			while(cap<=doblecap){
				cap += cap * (interes/100);
				cantanios++;	
			}
		return cantanios;
		}
};

int main(){

	DepositoSimulacion probando;													//Creamos el objeto y las variable de entrada
	double capital,interes;
	int anios;
	
	do{
	cout << "Introduce el capital: ";											//Pedimos los datos de entrada
	cin >> capital;
	}while(capital<1);
	do{
	cout << "Introduce el interes: ";
	cin >> interes;
	}while(interes<1);
	do{
	cout << "Introduce la cantidad de años: ";
	cin >> anios;
	}while(anios<1);
	
	probando.SetValores(capital,interes,anios);								//Pasamos todos los datos introducidos a las variables de la clase
	
	cout << "\nCAPITAL: " << probando.GetCapital() << "; INTERES: " << probando.GetInteres() << "%; AÑOS: " << probando.GetAnios() << ":\n";
	cout << probando.CapitalAnios() << " seria el capital que tendriamos al cabo de " << probando.GetAnios() << " años con un " << probando.GetInteres() << "% de interes.";
	//MOSTRAMOS LOS RESULTADOS
	cout << "\n\nCAPITAL: " << probando.GetCapital() << "; INTERES: " << probando.GetInteres() << "%; DOBLE CAPITAL: " << probando.GetCapital()*2 << ":\n";
	cout << "Tardariamos " << probando.DobleCapital() << " años en conseguir el doble del capital con un " << probando.GetInteres() << "% de interes.\n\n";

system("pause");
}
