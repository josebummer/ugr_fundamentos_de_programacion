/*
Constructor
Modifique el programa principal del último apartado e imprima los valores de los
datos miembros de una recta, antes de asignarles los coeficientes. Mostrará, obviamente,
un valor indeterminado. Para evitar este problema, añada un constructor
a la recta para que el objeto esté en un estado válido en el mismo momento
de su definición. El constructor deberá tener como parámetros, obligatoriamente,
los tres coeficientes de la recta. Tendrá que modificar convenientemente el main
para tener en cuenta este cambio.
*/

#include <iostream>

using namespace std;

class Recta{															//Creamos la clase como hasta ahora
	private:
		double A,B,C;
	
	public:
		
		Recta(double valorA, double valorB, double valorC){			//Creamos un constructor que nos va a permitir meterle valores iniciales a los obejtos de
																						// esta clase
			A=valorA;
			B=valorB;
			C=valorC;
		
		}
		
		void SetCoeficientes(double valorA, double valorB, double valorC){
			A=valorA;
			B=valorB;
			C=valorC;
		}
		
		double GetA(){
			return A;
		}
		
		double GetB(){
			return B;
		}
		
		double GetC(){
			return C;
		}
		
		double ObtenerOrdenada(double x){
	
			return (-C -x*A)/B;
	
		}
	
		double ObtenerAbcisa(double y){
	
			return (-C -y*B)/A;
	
		}	
	
		double Pendiente(){
	
			return (-A)/B;				
		}
	
};

int main(){

	static const int TAMANIO=6;
	Recta uno(5,4,9),dos(3,6,4);							//Creamos los objetos con la diferencia de que ahora le metemos los valores al crearlos.
	double reales[TAMANIO],ordenada,abcisa;
	int i;

	cout << uno.GetA() << "\n";						//Mostramos los valores ahora para comprobar que los tiene
	cout << uno.GetB() << "\n";
	cout << uno.GetC() << "\n\n";

	for (i=0;i<6;i++){										//Pedimos los datos de entrada
	
		cout << "Introduce el " << i+1 << " numero: ";
		cin >> reales[i];
	
	}
	
	cout << "\nLOS TRES PRIMEROS VALORES VAN PARA LA PRIMERA RECTA, Y EL RESTO PARA LA SEGUNDA.\n";
	uno.SetCoeficientes(reales[0],reales[1],reales[2]);							//Metemos los datos a las cajas
	dos.SetCoeficientes(reales[3],reales[4],reales[5]);
	
	cout << "\nLa pendiente de la recta uno es: " << uno.Pendiente() << ".\nY la pendiente de la recta dos es: " << dos.Pendiente() << "\n\n"; //Mostramos la pendiente
	
	cout << "Introduce la abcisa de la primera recta: ";					//Pedimo la abcisa
	cin >> abcisa;
	
	cout << "\nLa ordenada que correspondiente a esa abcisa en la recta 1 es: " << uno.ObtenerOrdenada(abcisa) << "\n\n";	//Mostramos la ordenada
	
	cout << "Introduce la ordenada de la primera recta: ";								//Pedimos la ordenada
	cin >> ordenada;
	
	cout << "\nLa abcisa que correspondiente a esa ordenada en la recta 1 es: " << uno.ObtenerAbcisa(ordenada) << "\n\n";	//Mostramos la abcisa

system("pause");
}
