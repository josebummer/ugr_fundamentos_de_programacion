/*
Defina la clase SecuenciaEnteros análoga a SecuenciaCaracteres pero para
que trabaje sobre enteros. Defina en el main un vector clásico de corchetes de tipo de
dato char. Lea desde el main varios caracteres y asígnelos al vector de char. Lea
también varios enteros y asígnelos a un objeto de la clase SecuenciaEnteros.
Implemente ahora directamente en el main un algoritmo para que elimine eficientemente
todas las posiciones indicadas en la secuencia de enteros. Por ejemplo, si
el vector de caracteres contiene Fundamentos, después de eliminar el conjunto de
posiciones dado por 2 5 3, el vector se quedará como Fuaentos.
Observe que una posibilidad sería sustituir los caracteres a borrar por un carácter especial,
por ejemplo # y luego pasarle un algoritmo que eliminase todas las ocurrencias
de #. Sin embargo, nunca debemos recurrir a esta técnica ya que no podemos presuponer
que tenemos la posibilidad de elegir tal carácter especial, ya que puede ser un
carácter válido de la secuencia.
Se recomienda implementar el siguiente algoritmo:
Utilizar dos índices: pos_escritura y pos_lectura que marquen
las posiciones de lectura y escritura en el vector de char
Ordenar la secuencia de enteros
Recorrer con pos_lectura los caracteres del vector de char
Si el carácter actual no está en una posición a borrar,
colocarlo en pos_escritura.
*/
#include <iostream>

using namespace std;

class SecuenciaEnteros {									//Creamos la clase secuencia enteros al igual que secuencia caracteres
	private:
		static const int TAMANIO = 50;
		int vector_privado[TAMANIO],total_utilizados;
	public:
		SecuenciaEnteros()
			:total_utilizados(0){
		}
		int TotalUtilizados(){
			return total_utilizados;
		}
		int Capacidad(){
			return TAMANIO;
		}
		void Aniade(int nuevo){
			if (total_utilizados < TAMANIO){
				vector_privado[total_utilizados] = nuevo;
				total_utilizados++;
			}
		}
		int Elemento(int indice){
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
		bool EsPalindromo(){										//Nos devuelve true o false dependiendo si el vector es palindromo o no

			bool palindromo=true;
			int i,aux_utilizados=total_utilizados;
	
			for(i=0;i<aux_utilizados && palindromo;i++,aux_utilizados--)
				if(vector_privado[i]!=vector_privado[aux_utilizados-1])
					palindromo=false; 

		return palindromo;
		}
		void Invierte(){											//Invierte el vector

			int aux,aux_utilizados=total_utilizados;
			int i;
	
			for(i=0;i<aux_utilizados;i++,aux_utilizados--){
				aux=vector_privado[i];
				vector_privado[i]=vector_privado[aux_utilizados-1];
				vector_privado[aux_utilizados-1]=aux;
			}
		}
		
		void EliminaRepetidos(){								//Elimina repetidos
			
			for(int i=0;i<total_utilizados;i++){
				for(int j=i+1;j<total_utilizados;j++)
					if(vector_privado[i]==vector_privado[j]){
						Elimina(j);
						j--;
					}
			}
		}
		
		int SecuenciasAscendentes(){							//Devuelve el numero de secuencias ascendentes
			
			int secuencias=0;
			
			for(int i=0;i<total_utilizados;i++)
				if(vector_privado[i+1]!=vector_privado[i] && vector_privado[i+1]<vector_privado[i])
					secuencias++;
			
		return secuencias;
		}
		
		void IntercambiaComponentes(int posicion1, int posicion2){								//Con este metodo cambiamos dos valores de dos posiciones del vector.
			if((posicion1<total_utilizados && posicion2<total_utilizados) && (posicion1>=0 && posicion2>=0)){
				int aux;
			
				aux=vector_privado[posicion1];
				vector_privado[posicion1]=vector_privado[posicion2];
				vector_privado[posicion2]=aux;
			}
		}
		
		void Ordenar(){									//Ordena el vector
		
			for(int i=0;i<total_utilizados;i++)
				for(int j=total_utilizados-1;j>i;j--)
					if(vector_privado[j]<vector_privado[j-1])
						IntercambiaComponentes(j,j-1);
		}
};

int main(){

	const int TAMANIO=50;										//Creamos las variables necesarias
	char secuencia[TAMANIO],caracter;
	SecuenciaEnteros vector;
	int entero,total_util=0,pos_escritura=0,pos_lectura=0,i=0,tope=0;
	
	cout << "Introduce la primera letra (# para salir): ";							//Pedimos los valores de entrada
	cin >> caracter;
	
	while(caracter!='#'){
		
		secuencia[total_util]=caracter;												//Añadimos el valor introducido al vector
		total_util++;
		
		cout << "Introduce otra letra (# para salir): ";
		cin >> caracter;
	}	
	
	do{
	cout << "Introduce un numero entero positivo para eliminar las posiciones(<0 para salir): ";		//Introducimos los datos para el vector de enteros
	cin >> entero;
	}while(entero>total_util-1);
	
	while(entero>=0){
		
		vector.Aniade(entero);													//Añadimos el dato al vector
		
		do{
			cout << "Introduce un numero entero positivo para eliminar las posiciones(<0 para salir): ";
			cin >> entero;
		}while(entero>total_util-1);
	}
	
	cout << "\nVamos a eliminar los caracteres de las posiciones indicadas:\n";
	
	vector.Ordenar();							//Ordenamos el vector ascendentemente.
	tope=total_util;
	
	for(pos_lectura=0;pos_lectura<tope;pos_lectura++)				//Recorremos el vector de caracteres.
		if(pos_lectura!=vector.Elemento(i)){							//Si la posicion donde estamos leyendo no es una posicion a eliminar, 
			secuencia[pos_escritura]=secuencia[pos_lectura];		//escribimos el caracter y pasamos al siguiente.
			pos_escritura++;
		}
		else{																		//El en caso de que sea una posicion a eliminar, pasamos a la siguiente letra
			total_util--;														//pero el pos_escritura lo dejamos ahí y a total_utilizados le restamos 1
			i++;
		}
	
	cout << "\n\nTu palabra finalmente es:\n";					//Mostramos el resultado
	for(int i=0;i<total_util;i++)
		cout << secuencia[i];
	
	cout << "\n\n";


system("pause");
}
