/*
Sobre el ejercicio 10, construya una clase específica ContadorMayusculas que
implemente los métodos necesarios para llevar el contador de las mayúsculas. Lo que
se pretende es que la clase proporcione los métodos siguientes:
void IncrementaConteo (char mayuscula)
int CuantasHay (char mayuscula)
El primer método aumentará en uno el contador de la correspondiente mayúscula y el
segundo indicará cuántas hay. Modifique el programa principal para que cree un objeto
de esta clase y llame a sus métodos para realizar los conteos de las mayúsculas.
Finalmente, hay que imprimir en pantalla cuántas veces aparece cada mayúscula.
*/

#include <iostream>

using namespace std;

class ContadorMayusculas{
	private:
		static const int TAMANIO=26;
		int utilizados,contador_privado[TAMANIO];
	public:
		ContadorMayusculas(){
			utilizados=0;
			for(int i=0;i<TAMANIO;i++)
				contador_privado[i]=0;
		}
		
		int Capacidad(){
			return TAMANIO;
		}
		
		void IncrementaConteo(char mayuscula){
			if(mayuscula>='A' && mayuscula<='Z')
				contador_privado[mayuscula-'A']+=1;
		}
		
		int CuantasHay(char mayuscula){
			return contador_privado[mayuscula-'A'];
		}

};

int main(){

	ContadorMayusculas contador;
	char caracter;

	cout << "Introduce la primera letra (. para salir): ";							//Pedimos los valores de entrada
	cin >> caracter;
	
	while(caracter!='.'){
		
		contador.IncrementaConteo(caracter);															//Añadimos el valor introducido al vector
		
		cout << "Introduce otra letra (. para salir): ";
		cin >> caracter;
	}

	cout << "\n\n";
	for(int i=0;i<contador.Capacidad();i++)
		if(contador.CuantasHay('A'+i)!=0){
			caracter=i+'A';
			cout << "La letra " << caracter << " se ha repetido " << contador.CuantasHay(i+'A') << " veces.\n";
		}
	cout << "\n\n";
	
system("pause");
}
