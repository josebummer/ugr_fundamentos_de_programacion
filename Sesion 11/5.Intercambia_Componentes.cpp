/*
Añada el método IntercambiaComponentes para intercambiar dos componentes
de la secuencia. Por ejemplo, si la secuencia contiene {'h','o','l','a'}, después
de intercambiar las componentes 1 y 3, se quedaría con {'h','a','l','o'}.
¿Qué debería hacer este método si los índices no son correctos?
Modifique la implementación del método Invierte del ejercicio 4, para que lo haga
llamando a IntercambiaComponentes.
Imprima las componentes de la secuencia desde el main, antes y después
de llamar a dicho método. Para ello, use el método ToString() de la clase
SecuenciaCaracteres.
*/

#include <iostream>
#include <string>

using namespace std;

class SecuenciaCaracteres {
	private:
		static const int TAMANIO = 50;
		char vector_privado[TAMANIO];
		int total_utilizados;
	public:
		SecuenciaCaracteres()
			:total_utilizados(0){
		}
		int TotalUtilizados(){
			return total_utilizados;
		}
		int Capacidad(){
			return TAMANIO;
		}
		void Aniade(char nuevo){
			if (total_utilizados < TAMANIO){
				vector_privado[total_utilizados] = nuevo;
				total_utilizados++;
			}
		}
		char Elemento(int indice){
			return vector_privado[indice];
		}
		void Elimina (int posicion){
			if (posicion >= 0 && posicion < total_utilizados){
				int tope = total_utilizados-1;
				for (int i = posicion ; i < tope ; i++)
					vector_privado[i] = vector_privado[i+1];
					total_utilizados--;
			}
		}
		string ToString(){
			string cadena;
			for (int i=0; i<total_utilizados; i++)
				cadena = cadena + vector_privado[i];
			return cadena;
		}
		bool EsPalindromo(){										//Nos devuelve true o false dependiendo si el vector es palindromo o no

			bool palindromo=true;
			int i,aux_utilizados=total_utilizados;
	
			for(i=0;i<aux_utilizados && palindromo;i++,aux_utilizados--)
				if(vector_privado[i]!=vector_privado[aux_utilizados-1])
					palindromo=false; 

		return palindromo;
		}
		int NumeroMayusculas(){									//Nos devuelve el numero de mayusculas que tiene el vector

			int mayusculas=0,i;
	
			for(i=0;i<total_utilizados;i++){
				if(vector_privado[i]>='A' && vector_privado[i]<='Z')
					mayusculas++;
			}
		return mayusculas;
		}
		void IntercambiaComponentes(int posicion1, int posicion2){								//Con este metodo cambiamos dos valores de dos posiciones del vector.
			if((posicion1<total_utilizados && posicion2<total_utilizados) && (posicion1>=0 && posicion2>=0)){
				char aux;
			
				aux=vector_privado[posicion1];
				vector_privado[posicion1]=vector_privado[posicion2];
				vector_privado[posicion2]=aux;
			}
		}
		void Invierte(){											//Con este metodo invertimos el vector al contrario de como esté.

			int aux_utilizados=total_utilizados;
			int i;
	
			for(i=0;i<aux_utilizados;i++,aux_utilizados--)
				IntercambiaComponentes(i,aux_utilizados-1);
			
		}
};

int main(){

	char caracter;												//Creamos las variables de entradas
	SecuenciaCaracteres vector;
	int i,posicion1,posicion2;
	
	cout << "Introduce la primera letra (# para salir): ";									//Pedimos los datos de entrada
	caracter=cin.get();
	
	while(caracter!='#' && vector.TotalUtilizados()<vector.Capacidad()){
		
		vector.Aniade(caracter);				//Añadimos el valor introducido al vector.
		
		/* SI INTRODUCIMOS LOS DATOS POR TECLADO DESCOMENTAR LA SIGUIENTE LINEA:*/
		if(caracter=='\n')
			vector.Elimina(vector.TotalUtilizados()-1);
		
		cout << "Introduce otra letra (# para salir): ";
		caracter=cin.get();
	}
	
	cout << "El vector finalmente es:\n";							//Mostramos el vector mostrando caracter por caracter
	cout << vector.Elemento(0);
	for(i=1;i<vector.TotalUtilizados();i++){
		cout << ", " << vector.Elemento(i);
	}
	cout << "\n\n";
	
	vector.Invierte();										//Invertimos el vector
	cout << "El vector invertido es:\n";					//Mostramos de nuevo el vector pero esta vez ya invertido
	cout << vector.Elemento(0);
	for(i=1;i<vector.TotalUtilizados();i++){
		cout << ", " << vector.Elemento(i);
	}
	cout << "\n\n";
	
	do{
	cout << "Introduce una posicion a cambiar: ";								//Preguntamos por una posicion del vector para cambiarla por otra posicion
	cin >> posicion1;	
	}while(posicion1>=vector.TotalUtilizados() || posicion1<=0);
	do{
	cout << "Introduce la segunda posicion a cambiar: ";						//Preguntamos por la segunda posicion a cambiar
	cin >> posicion2;
	}while(posicion2>=vector.TotalUtilizados() || posicion2<=0);
	
	vector.IntercambiaComponentes(posicion1-1,posicion2-1);					//Intercambiamos los componentes que el usuario ha introducido
	cout << "\nEl vector ahora es:\n";												//Mostramos finalemente el vector con las posiciones cambiadas
	for(i=0;i<vector.TotalUtilizados();i++){
		cout << vector.Elemento(i) << ", ";
	}
	cout << "\n\n";


system("pause");
}
