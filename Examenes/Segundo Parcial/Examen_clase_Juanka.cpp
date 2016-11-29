/*
Utilizando SecuenciaEnteros añada los siguientes metodos:
1. Frecuencia: dado un valor k, delvuelve cuantas veces aparece k en la secuencia.
2. sinRepetidos: Construye y devuelve una nueva secuencia de enteros que contiene los elementos de la secuencia
original, pero sin repetidos.
3. Interseccion: Construye y devuelve una nueva secuencia de enteros que contiene la interseccion, sin repetidos,
entre la secuencia original y otra que recibe como parametro.
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
		
		int Frecuencia(int valor){
			int frecuencia=0;
				
				for(int i=0;i<total_utilizados;i++)
					if(Elemento(i)==valor)
						frecuencia++;
		
		return frecuencia;
		}
		
		SecuenciaEnteros sinRepetidos(){
			SecuenciaEnteros secuencia;
			bool existe;
			
			for(int pos_lectura=0;pos_lectura<total_utilizados;pos_lectura++){
				existe=false;
				for(int i=0;i<secuencia.TotalUtilizados() && !existe;i++)
					if(Elemento(pos_lectura)==secuencia.Elemento(i))
						existe=true;
				if(!existe)
					secuencia.Aniade(Elemento(pos_lectura));			
			}
		return secuencia;
		}
		
		SecuenciaEnteros Interseccion(SecuenciaEnteros otra){
			SecuenciaEnteros secuencia;
			bool existe;
			
			for(int i=0;i<total_utilizados;i++)
				for(int j=0;j<otra.TotalUtilizados();j++){
					if(Elemento(i)==otra.Elemento(j)){
						existe=false;
						for(int c=0;c<secuencia.TotalUtilizados() && !existe;c++)
							if(Elemento(i)==secuencia.Elemento(c))
								existe=true;
						if(!existe)
							secuencia.Aniade(Elemento(i));
					}
				}					
		
		return secuencia;
		}
};

int main(){
	SecuenciaEnteros original,otro,sin_repetidos,interseccion;
	int entero;
	
	cout << "Introduce numeros enteros para el vector(-1 para salir): ";
	cin >> entero;
	
	while(entero!=-1){
	
		original.Aniade(entero);
		
		cout << "Introduce numeros enteros para el vector(-1 para salir): ";
		cin >> entero;
	}
	
	cout << "\nIntroduce un valor del vector para saber el numero de veces que aparece: ";
	cin >> entero;
	
	cout << "\nEl entero " << entero << " aparece " << original.Frecuencia(entero) << " veces.\n\n";
	
	cout << "El vector original es:\n";
	for(int i=0;i<original.TotalUtilizados();i++)
		cout << original.Elemento(i);
	
	
	sin_repetidos=original.sinRepetidos();
	
	cout << "\nEl vector sin repetidos es:\n";
	for(int i=0;i<sin_repetidos.TotalUtilizados();i++)
		cout << sin_repetidos.Elemento(i);
		
	cout << "\n\nIntroduce numeros enteros para el segundo vector(-1 para salir): ";
	cin >> entero;
	
	while(entero!=-1){
	
		otro.Aniade(entero);
		
		cout << "Introduce numeros enteros para el segundo vector(-1 para salir): ";
		cin >> entero;
	}
	
	interseccion=original.Interseccion(otro);
	
	cout << "\nLa interseccion del primer vector con este es:\n";
	for(int i=0;i<interseccion.TotalUtilizados();i++)
		cout << interseccion.Elemento(i);
	cout << "\n\n";
system("pause");
}
