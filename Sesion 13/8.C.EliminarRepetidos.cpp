/*
Sobre la clase SecuenciaCaracteres, añada un método EliminaRepetidos
que quite los elementos repetidos, de forma que cada componente sólo aparezca una
única vez. Se mantendrá la primera aparición, de izquierda a derecha. Por ejemplo, si
la secuencia contiene
{'b','a','a','h','a','a','a','a','c','a','a','a','g'}
después de quitar los repetidos, se quedaría como sigue:
{'b','a','h','c','g'}
Implemente los siguientes algoritmos para resolver ester problema:
a) Usando un vector local sin_repetidos en el que almacenamos una única
aparición de cada componente:
Recorrer todas las componentes de la secuencia original
Si la componente NO está en "sin_repetidos",
añadirla (al vector "sin_repetidos")
Asignar las componentes de "sin_repetidos" a la secuencia
b) El problema del algoritmo anterior es que usa un vector local, lo que podría suponer
una carga importante de memoria si trabajásemos con vectores grandes.
Por lo tanto, vamos a resolver el problema sin usar vectores locales.
Si una componente está repetida, se borrará de la secuencia. Para borrar una
componente, llamamos al método Elimina.
c) El anterior algoritmo nos obliga a desplazar muchas componentes cada vez que
encontremos una repetida. Proponga una alternativa (sin usar vectores locales)
para que el número de desplazamientos sea el menor posible e impleméntela.
	Consejo: Use la misma técnica que se indicó en el ejercicio 7 de eliminar las
mayúsculas.
*/
#include <iostream>

using namespace std;

//Ejercicio 8, PARTE C)

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
		void Invierte(){											//Invierte el vector

			char aux;
			int aux_utilizados=total_utilizados;
			int i;
	
			for(i=0;i<aux_utilizados;i++,aux_utilizados--){
				aux=vector_privado[i];
				vector_privado[i]=vector_privado[aux_utilizados-1];
				vector_privado[aux_utilizados-1]=aux;
			}
		}
		int NumeroMayusculas(){									//Nos devuelve el numero de mayusculas que tiene el vector

			int mayusculas=0,i;
	
			for(i=0;i<total_utilizados;i++){
				if(vector_privado[i]>='A' && vector_privado[i]<='Z')
					mayusculas++;
			}
		return mayusculas;
		}
		
		void EliminaMayusculas(){
			
			for(int i=0;i<total_utilizados;i++)
				if(isupper(vector_privado[i])){
					Elimina(i);
					i--;
				}
		}
		
		void EliminaRepetidos(){
			int pos_escritura=0,tope=total_utilizados;
			bool encontrado;
			
			for(int pos_lectura=0;pos_lectura<tope;pos_lectura++){
				encontrado=false;
				for(int i=0;i<pos_escritura && !encontrado;i++)
					if(vector_privado[pos_lectura]==vector_privado[i])
						encontrado=true;
				if(!encontrado){
					vector_privado[pos_escritura]=vector_privado[pos_lectura];
					pos_escritura++;
				}
				else
					total_utilizados--;
			}
		}
};

int main(){

	char caracter;														//Creamos las variables de entrada
	SecuenciaCaracteres vector;
	int i;
	
		cout << "Introduce la primera letra (# para salir): ";							//Pedimos los valores de entrada
		cin >> caracter;
	
	while(caracter!='#' && vector.TotalUtilizados()<vector.Capacidad()){
		
		vector.Aniade(caracter);												//Añadimos el valor introducido al vector
		
		cout << "Introduce otra letra (# para salir): ";
		cin >> caracter;
	}

	cout << "El vector es:\n";								//Mostramos el vector
	cout << vector.Elemento(0);
	for(i=1;i<vector.TotalUtilizados();i++){
		cout << ", " << vector.Elemento(i);
	}
	cout << "\n\n";
	
	cout << "Vamos ahora a eliminar los elementos repetidos: ";
	
	vector.EliminaRepetidos();
	
	cout << "El vector ahora es:\n";								//Mostramos el vector con lo elemenetos repetidos eliminados
	cout << vector.Elemento(0);
	for(i=1;i<vector.TotalUtilizados();i++){
		cout << ", " << vector.Elemento(i);
	}
	cout << "\n\n";

system("pause");
}
