/*
//NOMBRE: Jose Antonio, Ruiz Millan, 26503402L
//PROBLEMA: hortalizas
*/

#include <iostream>

using namespace std;
class SecuenciaEnteros{
	private:
		static const int TAMANIO=100;												//Creamos la constante Tamanio para el vector.
		int vector_privado[TAMANIO],total_utilizados;						//Creamos la variable privada utilizados y el vector.
	public:
		SecuenciaEnteros(){															//Creamos un constructor que nos inicializa los utilizados a 0
			total_utilizados=0;
		}
		int TotalUtilizados(){														//Con este metodo devolvemos el total utilizados
			return total_utilizados;
		}
			
		int Capacidad(){																//Con este metodo devolvemos la capacidad del vector
			return TAMANIO;
		}
			
		int Elemento(int indice){													//Este metodo nos va a devolver un elemento del vector independientemente de ser pais,hortaliza o toneladas
			return vector_privado[indice];
		}
		
		void Aniade(int pais, int hortaliza, int toneladas){				//Este metodo nos permitira aniadir un pais con su hortaliza y sus toneladas al vector
			if((total_utilizados<TAMANIO) && (pais>=0 && pais<3) && (hortaliza>=0 && hortaliza<3) && toneladas>0){			//Hacemos las comprobaciones
				vector_privado[total_utilizados]=pais;
				vector_privado[total_utilizados+1]=hortaliza;																	//Aniadimos los 3 elementos y sumamos al total utilizados 3.
				vector_privado[total_utilizados+2]=toneladas;
				total_utilizados+=3;	
			}
		}
		
		bool EsPais(int indice){																						//Este metodo nos va a devolver si dado un indice, pertenece a un pais en el vector.
			bool espais=false;
			
			if(indice<total_utilizados && indice>=0 && indice%3==0)
				espais=true;
				
			return espais;	
		}
		
		void Elimina(int indice){																//Con este metodo, dado un indice eliminaremos ese pais, con su hortaliza y sus toneladas
			int tope=total_utilizados-3;
			
			if(indice<total_utilizados && EsPais(indice)){							//Comprobamos que es un pais y que el numero dado es correcto.
				for(int i=indice;i<tope;i++)
					vector_privado[i]=vector_privado[i+3];								//Eliminamos las 3 posiciones
				total_utilizados-=3;															//Restamos 3 al total utilizados
			}
		}
		
		int MaximoToneladas(){																//Este metodo nos va a calcular el numero maximo de toneladas respecto a un pais y a una hortaliza
			SecuenciaEnteros sumas;
			bool existe;
			int maximo,posicion,tope=total_utilizados-2;								//Creamos estas variables que nos serviran para la comprobacion
			
			for(int i=0;i<tope;i+=3){
				existe=false;
				for(int j=0;j<sumas.TotalUtilizados() && !existe;j+=3)					//Recorremos el vector de las sumas comprobando el elemento que tenemos del vector_privado, si existe como pais, 
					if(Elemento(i)==sumas.Elemento(j))											// comprueba si seguido existe la hortaliza y si existe cambiar la variable existe a true y guardamos la posicion
						if(Elemento(i+1)==sumas.Elemento(j+1)){								// donde se encuentra para despues sumarle.
							existe=true;
							posicion=j;
						}
				if(!existe)																				//Una vez recorrido el vector de sumas completo comprobamos el parametro de salida y si existe sigue siendo
					sumas.Aniade(Elemento(i),Elemento(i+1),Elemento(i+2));				// false, aniadimos como un valor normal el pais, hortaliza y toneladas que corresponde.
				else
					sumas.vector_privado[posicion+2]+=Elemento(i+2);						//En caso contrario de que sea true, suma las toneladas del vector_privado, al vector de sumas.
			}
			
			maximo=sumas.Elemento(2);																//Finalmente recorremos el vector de las sumas y sacamos la suma mas grande.
			for(int i=2;i<sumas.TotalUtilizados();i+=3)
				if(sumas.Elemento(i)>maximo)
					maximo=sumas.Elemento(i);
		return maximo;
		}
};
int main(){
	SecuenciaEnteros hortalizas;
	int pais,hortaliza,toneladas;
	
	do{
	cout << "Introduce un entero para el pais(-1 para salir): ";
	cin >> pais;
	}while(pais!=0 && pais!=1 && pais!=2 && pais!=-1);
	
	while(pais!=-1){
		
		do{
			cout << "Introduce un entero para la hortaliza: ";
			cin >> hortaliza;
		}while(hortaliza!=0 && hortaliza!=1 && hortaliza!=2);
		
		do{
			cout << "Introduce el numero de toneladas: ";
			cin >> toneladas;
		}while(toneladas<=0);
		
		hortalizas.Aniade(pais,hortaliza,toneladas);
		
		do{
		cout << "Introduce un entero para el pais(-1 para salir): ";
		cin >> pais;
		}while(pais!=0 && pais!=1 && pais!=2 && pais!=-1);
	}
	
	cout << "\n\nLa capacidad del vector es: " << hortalizas.Capacidad() << "\n";
	
	cout << "El vector es:\n";
	for(int i=0;i<hortalizas.TotalUtilizados();i++)
		cout << hortalizas.Elemento(i);
	cout << "\n\n";
	
	cout << "El numero de utilizados son: " << hortalizas.TotalUtilizados() << "\n";
	
	cout << "Introduce un indice para eliminar un pais: ";
	cin >> pais;

	hortalizas.Elimina(pais);
	
	cout << "\nEl vector ahora es:\n";
	for(int i=0;i<hortalizas.TotalUtilizados();i++)
		cout << hortalizas.Elemento(i);
	cout << "\n\n";
	
	cout << "El numero de toneladas respecto a un pais y una hortaliza es: " << hortalizas.MaximoToneladas() << "\n\n";
system("pause");
}
