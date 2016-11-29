/*
Recupere la solución del ejercicio 31 de la Relación de Problemas IV (elimina varios
caracteres de una secuencia). Defina el método EliminaVarios sobre la clase
SecuenciaCaracteres para que haga la tarea pedida. Tendrá que pasarle al método
un objeto de la clase SecuenciaEnteros con los índices de las posiciones a
eliminar.
*/
#include <iostream>

using namespace std;

class SecuenciaEnteros{									//Creamos la clase secuencia enteros al igual que secuencia caracteres
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
			if(indice<total_utilizados && indice>=0)
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

class SecuenciaCaracteres {											//Cojemos la clase de decsai
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
		
		void EliminaMayusculas(){						//Creamos el metodo elimina mayusculas
			
			int posicion_lectura=0,posicion_escritura=0,tope=total_utilizados;
			
			for(int i=posicion_lectura;i<tope;i++)								//Recorremos el vector
				if(islower(vector_privado[i])){									//Comprobamos si la letra en la que nos encontramos es minuscula
					vector_privado[posicion_escritura]=vector_privado[i];	// Si es minuscula la escribimos en la posicion de escritua y pasamos a la siguiente
					posicion_escritura++;
				}
				else																		//Si la letra es mayusucla no la escribimos para borrarla y quitamos 1 a utilizados
					total_utilizados--;
		}
		
		bool Similar(SecuenciaCaracteres otro){
			bool similares=true,encontrada;
			
			if(Elemento(0)==otro.Elemento(0) && Elemento(total_utilizados-1)==otro.Elemento(otro.TotalUtilizados()-1) && total_utilizados==otro.TotalUtilizados()){
				int tope=total_utilizados-1;
		// Comrpobamos en el if que la primera letra y la ultima son iguales y que el tamaño de los dos vectores es el mismo.
				for(int i=1;i<tope && similares;i++){				//Recorremos el vector cojiendo cada letra
					encontrada=false;
					for(int j=1;j<tope && !encontrada;j++)					
						if(Elemento(i)==otro.Elemento(j))					//Si la encuentra, salimos y pasamos a la siguiente letra
							encontrada=true;
					if(!encontrada)														//Si termina y no la ha encontrado ya tenemos que no son similares.
					similares=false;
				}
			}
			else
				similares=false;	
		return similares;
		}
		
		void EliminaVarios(SecuenciaEnteros posiciones){
			posiciones.Ordenar();
			int tope=total_utilizados,i=0,pos_escritura=0;
			
			for(int pos_lectura=0;pos_lectura<tope;pos_lectura++)				//Recorremos el vector de caracteres.
				if(pos_lectura!=posiciones.Elemento(i)){							//Si la posicion donde estamos leyendo no es una posicion a eliminar, 
					vector_privado[pos_escritura]=Elemento(pos_lectura);		//escribimos el caracter y pasamos al siguiente.
					pos_escritura++;
				}
				else{																		//El en caso de que sea una posicion a eliminar, pasamos a la siguiente letra
					total_utilizados--;														//pero el pos_escritura lo dejamos ahí y a total_utilizados le restamos 1
					i++;
				}
		}
};

int main(){
	
	SecuenciaCaracteres texto;
	SecuenciaEnteros posiciones;
	int entero;
	char caracter;
	
	cout << "Introduce la primera letra (# para salir): ";							//Pedimos los valores de entrada
	cin >> caracter;
	
	while(caracter!='#'){
		
		texto.Aniade(caracter);												//Añadimos el valor introducido al vector
		
		cout << "Introduce otra letra (# para salir): ";
		cin >> caracter;
	}	
	
	do{
	cout << "Introduce un numero entero positivo para eliminar las posiciones(<0 para salir): ";		//Introducimos los datos para el vector de enteros
	cin >> entero;
	}while(entero>texto.TotalUtilizados()-1);
	
	while(entero>=0){
		
		posiciones.Aniade(entero);													//Añadimos el dato al vector
		
		do{
			cout << "Introduce un numero entero positivo para eliminar las posiciones(<0 para salir): ";
			cin >> entero;
		}while(entero>texto.TotalUtilizados()-1);
	}
	
	cout << "\nVamos a eliminar los caracteres de las posiciones indicadas:\n";
	texto.EliminaVarios(posiciones);
	
	cout << "\n\nTu palabra finalmente es:\n";					//Mostramos el resultado
	for(int i=0;i<texto.TotalUtilizados();i++)
		cout << texto.Elemento(i);
	
	cout << "\n\n";
	
system("pause");
}
