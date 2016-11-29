/*
con SecuenciaEnteros hay que hacer 3 metodos.
1. PuntoEquilibrio: 
2. rotar.
3. insertar.
*/

#include <iostream>
#include <stdlib.h>

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
		
		int SumaPosiciones(int posicion1, int posicion2){
			int suma=0;
			
			if((posicion1>=0 && posicion1<total_utilizados) && (posicion2>=0 && posicion2<total_utilizados))
				for(int i=posicion1;i<=posicion2;i++)
					suma+=Elemento(i);
		return suma;
		}
		
		int PuntoEquilibrio(){
			int minima=SumaPosiciones(0,total_utilizados-1),resta;
			
			for(int i=0;i<total_utilizados;i++){
				resta=SumaPosiciones(0,i)-SumaPosiciones(i+1,total_utilizados-1);
				resta=abs(resta);
				if(resta<minima)
					minima=resta;
			}
		return minima;
		}
		
		SecuenciaEnteros Rotar(int posicion){
			SecuenciaEnteros rotada;
			if(posicion<total_utilizados){
				posicion=total_utilizados-posicion;
				for(int i=posicion;i<total_utilizados;i++)
					rotada.Aniade(Elemento(i));
				for(int i=0;i<posicion;i++)
					rotada.Aniade(Elemento(i));
			}
		return rotada;
		}
		
		SecuenciaEnteros Insertar(SecuenciaEnteros s, int j){
			SecuenciaEnteros secuencia;
			
			for(int i=0;i<j;i++)
				secuencia.Aniade(Elemento(i));
			for(int i=0;i<s.TotalUtilizados();i++)
				secuencia.Aniade(s.Elemento(i));
			for(int i=j;i<total_utilizados;i++)
				secuencia.Aniade(Elemento(i));
			
		return secuencia;
		}
			
};

int main(){
	SecuenciaEnteros secuencia,rotado,insertado,otro;
	int entero;
	
	cout << "Introduce numeros enteros para el vector(-1 para salir): ";
	cin >> entero;
	
	while(entero!=-1){
	
		secuencia.Aniade(entero);
		
		cout << "Introduce numeros enteros para el vector(-1 para salir): ";
		cin >> entero;
	}

	cout << "El vector original es:\n";
	for(int i=0;i<secuencia.TotalUtilizados();i++)
		cout << secuencia.Elemento(i);
		
	cout << "\nEl punto de equilibrio de este vector es: " << secuencia.PuntoEquilibrio() << ".\n\n";
	
	cout << "Introduce un numero de elementos para rotarlos desde el final hacia el principio: ";
	cin >> entero;

	rotado=secuencia.Rotar(entero);
	
	cout << "El vector rotado es:\n";
	for(int i=0;i<rotado.TotalUtilizados();i++)
		cout << rotado.Elemento(i);
		
	cout << "\nIntroduce numeros enteros para el segundo vector que vamos a unir al primero(-1 para salir): ";
	cin >> entero;
	
	while(entero!=-1){
	
		otro.Aniade(entero);
		
		cout << "Introduce numeros enteros para el segundo vector que vamos a unir al primero(-1 para salir): ";
		cin >> entero;
	}
	
	cout << "\nIntroduce la posicion donde quieres insertarlo: ";
	cin >> entero;
	
	insertado=secuencia.Insertar(otro,entero);
	
	cout << "\n\nEl vector con el segundo vector insertado es:\n";
	for(int i=0;i<insertado.TotalUtilizados();i++)
		cout << insertado.Elemento(i);
	cout << "\n\n";
system("pause");
}
