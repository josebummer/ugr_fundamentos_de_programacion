/*Dadas dos secuenciasEnteros ordenadas S1, S2, construir una nueva
secuencia S3m tambien ordenada, que contenga los elementos de S1 y S2.
S3=s1.fusionar(s2). Muestre el contenido de S3.

Vamos comparando los dos vectores, a ver cual es el numero menor, el que sea
se añade al S3 y avanza posicion.
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
		
		SecuenciaEnteros Fusionar(SecuenciaEnteros otro){
			SecuenciaEnteros fusion;
			int i=0,j=0;
			
			Ordenar();
			otro.Ordenar();
			
			while(i<total_utilizados || j<otro.TotalUtilizados())
				if(i>=total_utilizados){
					fusion.Aniade(otro.Elemento(j));
					j++;
				}
				else if(j>=otro.TotalUtilizados()){
					fusion.Aniade(Elemento(i));
					i++;
				}
				else if(Elemento(i)==otro.Elemento(j)){
					fusion.Aniade(Elemento(i));
					i++;
					j++;
				}
				else if(Elemento(i)<otro.Elemento(j)){
					fusion.Aniade(Elemento(i));
					i++;
				}
				else{
					fusion.Aniade(otro.Elemento(j));
					j++;
				}		
		return fusion;
		}
};

int main(){

	SecuenciaEnteros S1,S2,S3;
	
	S1.Aniade(1);
	S1.Aniade(4);
	S1.Aniade(5);
	S1.Aniade(6);
	S1.Aniade(8);
	
	S2.Aniade(3);
	S2.Aniade(8);
	S2.Aniade(2);
	S2.Aniade(9);

	S3=S1.Fusionar(S2);
	
	cout << "\n\n";
	for(int i=0;i<S3.TotalUtilizados();i++)
		cout << S3.Elemento(i);
	cout << "\n\n";
system("pause");
}
