/*Datos miembro privados
Cambie ahora los datos miembro públicos y póngalos privados. Tendrá que añadir
métodos para asignar y ver los valores de los datos miembro. Añada métodos
para asignar un valor a cada uno de los tres datos miembro. Modifique el main
para tener en cuenta estos cambios.
*/

#include <iostream>

using namespace std;

class Recta{																	//Creamos la clase igual que antes, cambiando el modo a privado para las variables
	private:
		double A,B,C;
	
	public:
		
		double GetA(){															//Al crear una parte en privado, necesitamos crear las funciones get y set de cada variable
			return A;															// para que podamos llamarlas y meterles valores.
		}
		void SetA(double valor){
			A=valor;
		}
		
		double GetB(){
			return B;
		}
		void SetB(double valor){
			B=valor;
		}
		
		double GetC(){
			return C;
		}
		void SetC(double valor){
			C=valor;
		}
		
		double ObtenerOrdenada(double x){												//Creamos las mismas funciones que teniamos anteriormente
	
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

	static const int TAMANIO=6;														//Creamos las variables
	Recta uno,dos;
	double reales[TAMANIO],ordenada,abcisa;
	int i;

	for (i=0;i<6;i++){																		//Preguntamos por los datos de entrada
	
		cout << "Introduce el " << i+1 << " numero: ";
		cin >> reales[i];
	
	}
	
	cout << "\nLOS TRES PRIMEROS VALORES VAN PARA LA PRIMERA RECTA, Y EL RESTO PARA LA SEGUNDA.\n";
	uno.SetA(reales[0]);																					//Damos valor a los datos de cada objeto usando esta vez los Set
	uno.SetB(reales[1]);
	uno.SetC(reales[2]);	
	dos.SetA(reales[3]);
	dos.SetB(reales[4]);
	dos.SetC(reales[5]);
	
	cout << "\nLa pendiente de la recta uno es: " << uno.Pendiente() << ".\nY la pendiente de la recta dos es: " << dos.Pendiente() << "\n\n"; //Mostramos el resultado
	
	cout << "Introduce la abcisa de la primera recta: ";														//Pedimos la abcisa
	cin >> abcisa;
	
	cout << "\nLa ordenada que correspondiente a esa abcisa en la recta 1 es: " << uno.ObtenerOrdenada(abcisa) << "\n\n";		//Mostramos la ordenada
	
	cout << "Introduce la ordenada de la primera recta: ";													//Pedimos la ordenada
	cin >> ordenada;
	
	cout << "\nLa abcisa que correspondiente a esa ordenada en la recta 1 es: " << uno.ObtenerAbcisa(ordenada) << "\n\n";		//Mostramos la abcisa

system("pause");
}
