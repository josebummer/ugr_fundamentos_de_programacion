/*
Política de acceso a los datos miembro
Suprima ahora el método SetCoeficientes. De esta forma, una vez creado
el objeto (pasándole los datos apropiados en el constructor) ya no podremos
modificar los datos miembro. Esto es útil en aquellas situaciones en las que no
queremos permitir que el estado del objeto cambie, una vez se ha creado.
*/

#include <iostream>

using namespace std;

class Recta{											//Creamos la clase como anteriormente pero eliminamos el SetCoeficientes para que solo podamos meter los valores
	private:												// al inicializar los objetos
		double A,B,C;
	
	public:
		
		Recta(double valorA, double valorB, double valorC){
		
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

	Recta uno(5,4,9),dos(3,6,4);							//Inicializamos los objetos con sus valores
	double ordenada,abcisa;
	
	cout << "\nLa pendiente de la recta uno es: " << uno.Pendiente() << ".\nY la pendiente de la recta dos es: " << dos.Pendiente() << "\n\n"; //Mostramos la pendiente
	
	cout << "Introduce la abcisa de la primera recta: ";										//Pedimos la abcisa
	cin >> abcisa;
	
	cout << "\nLa ordenada que correspondiente a esa abcisa en la recta 1 es: " << uno.ObtenerOrdenada(abcisa) << "\n\n";			//Mostramos la ordenada
	
	cout << "Introduce la ordenada de la primera recta: ";								//Pedimos la ordenada
	cin >> ordenada;
	
	cout << "\nLa abcisa que correspondiente a esa ordenada en la recta 1 es: " << uno.ObtenerAbcisa(ordenada) << "\n\n";			//Mostramos la abcisa

system("pause");
}
