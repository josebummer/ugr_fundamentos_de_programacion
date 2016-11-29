/*
Política de acceso a los datos miembros
En vez de usar un método para asignar un valor a cada dato miembro, defina un
único método SetCoeficientes para asignar los tres a la misma vez.
Observad que los métodos permiten definir la política de acceso a los datos
miembro. Si tengo previsto cambiar por separado los coeficientes de la recta,
usaré métodos de asignación individuales. En caso contrario, usaré un único método
que modifique a la misma vez todos los datos miembro. Incluso pueden
dejarse en la clase ambos tipos de métodos para que así el cliente de la clase
pueda usar los que estime oportunos en cada momento. Por ahora, mantenga
únicamente el método de asignación en bloque SetCoeficientes.
*/

#include <iostream>

using namespace std;

class Recta{														//Creamos la clase como anteriormente.
	private:
		double A,B,C;
	
	public:
		
		void SetCoeficientes(double valorA, double valorB, double valorC){			//Creamos esta vez una funcion que nos va a permitir meter los valores de la
			A=valorA;																					// recta de una sola vez.
			B=valorB;
			C=valorC;
		}
		
		double GetA(){											//Creamos las mismas funciones que teniamos con anterioridad
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
	
	static const int TAMANIO=6;											//Creamos las varialbes
	Recta uno,dos;
	double reales[TAMANIO],ordenada,abcisa;
	int i;

	for (i=0;i<6;i++){															//Pedimos los datos de entrada
	
		cout << "Introduce el " << i+1 << " numero: ";
		cin >> reales[i];
	
	}
	
	cout << "\nLOS TRES PRIMEROS VALORES VAN PARA LA PRIMERA RECTA, Y EL RESTO PARA LA SEGUNDA.\n";
	uno.SetCoeficientes(reales[0],reales[1],reales[2]);											//Asignamos los valores de las rectas pero esta vez usando la funcion
	dos.SetCoeficientes(reales[3],reales[4],reales[5]);											// y como podemos ver lo hacemos de una sola vez
	
	cout << "\nLa pendiente de la recta uno es: " << uno.Pendiente() << ".\nY la pendiente de la recta dos es: " << dos.Pendiente() << "\n\n";	//Mostramos la pendiente
	
	cout << "Introduce la abcisa de la primera recta: ";											//Pedimos la abcisa
	cin >> abcisa;
	
	cout << "\nLa ordenada que correspondiente a esa abcisa en la recta 1 es: " << uno.ObtenerOrdenada(abcisa) << "\n\n";	//Mostramos la ordenada
	
	cout << "Introduce la ordenada de la primera recta: ";									//Pedimoos la ordenada
	cin >> ordenada;
	
	cout << "\nLa abcisa que correspondiente a esa ordenada en la recta 1 es: " << uno.ObtenerAbcisa(ordenada) << "\n\n";		//Mostramos la abcisa

system("pause");
}
