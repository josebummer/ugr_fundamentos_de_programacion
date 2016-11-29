/*
Métodos privados
Añada un método privado que nos indique si los coeficientes son correctos, es
decir, A y B no pueden ser simultáneamente nulos. Llame a este método en el
constructor y en el método SetCoeficientes y realice las operaciones que
estime oportuno en el caso de que los coeficientes pasados como parámetros no
sean correctos.
*/

#include <iostream>

using namespace std;

class Recta{													//Creamos la clase como en el apartado e, añadiendo ahora una funcion que nos va comprobar si los coeficientes
	private:														// son correctos.
		double A,B,C;
		
		bool CoeficientesCorrectos(double valorA, double valorB){		//Nos permite verificar que los coeficientes introducidos son los correctos.
																							
			bool correctos=true;
			
			if(valorA==0 && valorB==0)
				correctos=false;
				
			return correctos;
		}
	
	public:
		
		Recta(double valorA, double valorB, double valorC){
		
			if(CoeficientesCorrectos(valorA,valorB)){							//Llamamos a la funcion creada en este apartado para verificar los valores que se introducen
				A=valorA;																// y si no son correctos se da 1 como valor.
				B=valorB;
			}
			else{
				A=1;
				B=1;
			}
			C=valorC;
		}
		
		void SetCoeficientes(double valorA, double valorB, double valorC){
			
			if(CoeficientesCorrectos(valorA,valorB)){										//Hacemos lo mismo que anteriormente
				A=valorA;
				B=valorB;
			}
			else{
				A=1;
				B=1;	
			}
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

	static const int TAMANIO=6;								//Creamos las variables y los objetos
	Recta uno(5,4,9),dos(3,6,4);
	double reales[TAMANIO],ordenada,abcisa;
	int i;
	
	for (i=0;i<6;i++){										//Pedimos los datos de entrada
	
		cout << "Introduce el " << i+1 << " numero: ";
		cin >> reales[i];
	
	}
	
	cout << "\nLOS TRES PRIMEROS VALORES VAN PARA LA PRIMERA RECTA, Y EL RESTO PARA LA SEGUNDA.\n";
	uno.SetCoeficientes(reales[0],reales[1],reales[2]);										//Metemos los datos
	dos.SetCoeficientes(reales[3],reales[4],reales[5]);
	
	cout << "\nLa pendiente de la recta uno es: " << uno.Pendiente() << ".\nY la pendiente de la recta dos es: " << dos.Pendiente() << "\n\n";	//Mostramos la pendiente
	
	cout << "Introduce la abcisa de la primera recta: ";											//Pedimos la abcisa
	cin >> abcisa;
	
	cout << "\nLa ordenada que correspondiente a esa abcisa en la recta 1 es: " << uno.ObtenerOrdenada(abcisa) << "\n\n";	//Mostramos la ordenada
	
	cout << "Introduce la ordenada de la primera recta: ";											//Pedimos la ordenada
	cin >> ordenada;
	
	cout << "\nLa abcisa que correspondiente a esa ordenada en la recta 1 es: " << uno.ObtenerAbcisa(ordenada) << "\n\n";	//Mostramos la abcisa

system("pause");
}
