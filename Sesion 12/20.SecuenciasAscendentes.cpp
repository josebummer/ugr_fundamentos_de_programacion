/*
(Examen Septiembre Doble Grado 2013) Defina la clase SecuenciaEnteros análoga
a SecuenciaCaracteres. Defina lo que sea necesario para calcular el número
de secuencias ascendentes del vector. Por ejemplo, el vector {2,4,1,1,7,2,1} tiene
4 secuencias que son {2,4}, {1,1,7}, {2}, {1}.
*/

#include <iostream>

using namespace std;

	class SecuenciaEnteros {
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
		
		void EliminaRepetidos(){
			
			for(int i=0;i<total_utilizados;i++){
				for(int j=i+1;j<total_utilizados;j++)
					if(vector_privado[i]==vector_privado[j]){
						Elimina(j);
						j--;
					}
			}
		}
		
		int SecuenciasAscendentes(){
			
			int secuencias=0;
			
			for(int i=0;i<total_utilizados;i++)
				if(vector_privado[i+1]!=vector_privado[i] && vector_privado[i+1]<vector_privado[i])
					secuencias++;
			
		return secuencias;
		}
};

int main(){
	
	int entero,i;
	SecuenciaEnteros vector;
	
	cout << "Introduce un numero entero positivo(<0 para salir): ";
	cin >> entero;
	
	while(entero>=0 && vector.TotalUtilizados()<vector.Capacidad()){
		
		vector.Aniade(entero);
		
		cout << "Introduce un numero entero positivo(<0 para salir): ";
		cin >> entero;
	
	}

	cout << "El vector es:\n";								//Mostramos el vector
	cout << vector.Elemento(0);
	for(i=1;i<vector.TotalUtilizados();i++){
		cout << ", " << vector.Elemento(i);
	}
	cout << "\n\n";
	
	cout << "El numero de secuencias ascendentes de este vector es: " << vector.SecuenciasAscendentes() << ".\n\n";
	
system("pause");
}
