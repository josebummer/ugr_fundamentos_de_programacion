#include <iostream>

using namespace std;

class SecuenciaEnteros{
	private:
		static const int TAMANIO=50;
		int vector_privado[TAMANIO],total_utilizados;
	public:
		SecuenciaEnteros(){
			total_utilizados=0;
		}

		int TotalUtilizados(){
			return total_utilizados;
		}
		
		int Capacidad(){
			return TAMANIO;
		}
		
		void Aniade(int elemento){
			if(total_utilizados<TAMANIO){
				vector_privado[total_utilizados]=elemento;
				total_utilizados++;
			}
		}
		
		int Elemento(int posicion){
			if(posicion>=0 && posicion<total_utilizados)
				return vector_privado[posicion];
		}
		
		void Elimina(int posicion){
			if(posicion>=0 && posicion<total_utilizados){
				for(int i=posicion;i<total_utilizados;i++)
					vector_privado[i]=Elemento(i+1);
				total_utilizados--;
			}	
		}
		
		void Inserta(SecuenciaEnteros elementos,int posicion){
			int salto=elementos.TotalUtilizados();
			
			for(int i=total_utilizados;i>=posicion;i--)
				vector_privado[i+salto]=Elemento(i);
				
			for(int i=0;i<elementos.TotalUtilizados();i++,posicion++){
				vector_privado[posicion]=elementos.Elemento(i);
				total_utilizados++;
			}
		}
		
		void IntercambiaComponentes(int posicion1, int posicion2){
			if((posicion1>=0 && posicion1<total_utilizados) && (posicion2>=0 && posicion2<total_utilizados)){
				int aux=Elemento(posicion1);
				
				vector_privado[posicion1]=Elemento(posicion2);
				vector_privado[posicion2]=aux;
			}
		}
		
		void Invierte(){
			int j=total_utilizados-1;
			
			for(int i=0;i<j;i++,j--)
				IntercambiaComponentes(i,j);
		}
		
		void EliminaVarios(SecuenciaEnteros eliminar){
			int pos_escritura=0,posicion=0,tope=total_utilizados;
			
			for(int pos_lectura=0;pos_lectura<tope;pos_lectura++)
				if(pos_lectura!=eliminar.Elemento(posicion)){
					vector_privado[pos_escritura]=Elemento(pos_lectura);
					pos_escritura++;
				}
				else{
					posicion++;
					total_utilizados--;
				}
		}
		
		void EliminaRepetidos(){
			int pos_escritura=0,tope=total_utilizados;
			bool existe;
			
			for(int pos_lectura=0;pos_lectura<tope;pos_lectura++){
				existe=false;
				for(int i=0;i<pos_escritura && !existe;i++)
					if(vector_privado[pos_lectura]==vector_privado[i])
						existe=true;
				if(!existe){
					vector_privado[pos_escritura]=vector_privado[pos_lectura];
					pos_escritura++;
				}
				else
					total_utilizados--;	
			}		
		}
		
		void Ordenar(){
			for(int i=0;i<total_utilizados;i++)
				for(int j=total_utilizados-1;j>i;j--)
					if(Elemento(j-1)>Elemento(j))
						IntercambiaComponentes(j-1,j);
		}
};

int main(){
	SecuenciaEnteros probando,insertar;
	int entero,pos1,pos2;
	
	cout << "Introduce un numero entero(-1 para salir): ";
	cin >> entero;

	while(entero!=-1){
		
		probando.Aniade(entero);
		
		cout << "Introduce un numero entero(-1 para salir): ";
		cin >> entero;
	}
	
	cout << "\nVamos ha mostrar el vector original:\n";
	for(int i=0;i<probando.TotalUtilizados();i++)
		cout << probando.Elemento(i);
	
	cout << "\n\nIntroduce una posicion para eliminar el elmento(-1 para salir): ";
	cin >> entero;
	
	probando.Elimina(entero);
	
	cout << "\nAhora el vector es:\n";
	for(int i=0;i<probando.TotalUtilizados();i++)
		cout << probando.Elemento(i);
	
	cout << "\n\nIntroduce un numero entero para el vector a insertar(-1 para salir): ";
	cin >> entero;

	while(entero!=-1){
		
		insertar.Aniade(entero);
		
		cout << "Introduce un numero entero para el vector a insertar(-1 para salir): ";
		cin >> entero;
	}
	
	cout << "\nIntroduce la posicion donde quieres insertarlo(-1 para salir): ";
	cin >> entero;
	
	probando.Inserta(insertar,entero);
	
	cout << "\nAhora el vector es:\n";
	for(int i=0;i<probando.TotalUtilizados();i++)
		cout << probando.Elemento(i);
	
	cout << "\nIntroduce la posicion1 para intercambiar dos componentes(-1 para salir): ";
	cin >> pos1;
	cout << "\nIntroduce la posicio2 para intercambiar dos componentes(-1 para salir): ";
	cin >> pos2;
	
	probando.IntercambiaComponentes(pos1,pos2);
	
	cout << "\nAhora el vector es:\n";
	for(int i=0;i<probando.TotalUtilizados();i++)
		cout << probando.Elemento(i);
		
	cout << "\n\nVamos a invertir el vector:\n";
	probando.Invierte();
	for(int i=0;i<probando.TotalUtilizados();i++)
		cout << probando.Elemento(i);
	
	cout << "\n\nVamos a ordenar el vector:\n";
	probando.Ordenar();
	for(int i=0;i<probando.TotalUtilizados();i++)
		cout << probando.Elemento(i);
	
	cout << "\n\nVamos a elminar repetidos el vector:\n";
	probando.EliminaRepetidos();
	for(int i=0;i<probando.TotalUtilizados();i++)
		cout << probando.Elemento(i);
	
	cout << "\n\n";
system("pause");
}
