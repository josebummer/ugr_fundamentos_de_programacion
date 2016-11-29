//NOMBRE: Jose Antonio Ruiz Millan			26503402L
//PROBLEMA: hortalizas.

#include <iostream>
#include <string>

using namespace std;

//Esta funcion nos permitira leer el valor del pais, verificando que sea uno de los datos pedidos en el ejercicio, y devolverlo.
char LeerPais(){

	char pais;
	
	do{
		cout << "Introduce el indicativo del pais (E,F,A; @ para salir): ";
		cin >> pais;
	}while(pais!='E' && pais!='F' && pais!='A' && pais!='@');

return pais;
}

//Esta funcion va a leer el indicador de la hortaliza, validando lo datos como anteriormente, y nos devuelve el valor.
char LeerHortaliza(){

	char hortaliza;
	
	do{
		cout << "Introduce el indicativo de la hortaliza (T,P,E): ";
		cin >> hortaliza;
		
	}while(hortaliza!='T' && hortaliza!='P' && hortaliza!='E');

return hortaliza;
}

//Esta funcion va a leer y a devolvernos la cantidad de toneladas, verificando que sea un numero positivo.
int LeerCantidad(){

	int cantidad;
	
		do{
			cout << "Introuce la cantidad en toneladas: ";
			cin >> cantidad;
		}while(cantidad<0);

return cantidad;
}

//Esta funcion no va a realizar una suma entre dos valores que le indiquemos y no devuelve la suma total.
int Suma(int valor1, int valor2){

return valor1+valor2;
}

//Esta funcion calcula el maximo de 2 numeros que lo utilizaremos para devolver el maximo de 3.
int MaximoDos(int suma1, int suma2){

	int maximo=suma1;
	
	if(suma2>suma1)
		maximo=suma2;

return maximo;
}


//Esta funcion calcula el maximo de 3 numero, llamando a la funcion MaximoDos y comparando ese maximo con el tercer valor.
int MaximoTres(int suma1, int suma2, int suma3){

	int maximo;
	
	maximo=MaximoDos(suma1, suma2);
	
	if(suma3>maximo)
		maximo=suma3;

return maximo;
}

//Esta funcion nos devuelve el nombre del pais correspondiente al que tiene el maximo de toneladas.
string PaisMaximo(int maximo, int sumaF, int sumaA){		//No introducimos la suma de españa porque no necesitamo compararla.
	
	string pais;			
	
	if(maximo==sumaF)
		pais="FRANCIA";
	else if(maximo==sumaA)
		pais="ALEMANIA";
	else
		pais="ESPANA";

return pais;
} 

int main(){

	char pais, hortaliza;												//Creamos las variables.
	bool datosintroducidos=false;								//Esta variable la vamos a crear para verificar que el usuario a introducido
																		//	datos, por si no introduce datos, mostrar que no ha metido nada.
	int cantidad, sumaF=0, sumaE=0, sumaA=0, maximo;
	string paismax;

	pais=LeerPais();												//Leemos el pais primeramente.
	
	while(pais!='@'){												//Con esto aseguramos que no haya metido @, si la mete la primera vez que
																		// entra, se iria al final y como datointroducidos=false, te va a mostrar
																		// que no has introducido datos.
																		
		datosintroducidos=true;						//Activamos a true esta varaible que nos asegura que ya hemos introducido unos
															// valores y ya si tendremos pais maximo.
		
		hortaliza=LeerHortaliza();					//Leemos el resto de valores.
		cantidad=LeerCantidad();
	
		if(pais=='E')									//Dependiendo del pais introducido, sumamos la cantidad a una suma o otra.
			sumaE=Suma(sumaE,cantidad);
		else if (pais=='F')
			sumaF=Suma(sumaF,cantidad);
		else
			sumaA=Suma(sumaA,cantidad);
		
		pais=LeerPais();								//Volvemos a leer el pais para volver a empezar.
		
	}
	
	maximo=MaximoTres(sumaE,sumaF,sumaA);					//Calculamos el maximo de lo 3 llamando a la funcion.
	paismax=PaisMaximo(maximo,sumaF,sumaA);		//Calculamos el pais que corresponde al maximo de los 3, no pasamos la suma de
																// España porque no nos hace falta, en la funcion se ve perfectamente.
	
	if(datosintroducidos){										//Si hemos introducido datos nos muestra el resultado.
		cout << "\n\nPAIS= " << paismax << "\n";
		cout << "\nTONELADAS= " << maximo << "\n\n";
	}
	else																//Si la primera vez que entramos, metemos @, nos muestra el mensaje de error.
		cout << "\n\nNo has introducido ningun valor.\n\n";
		
system("pause");
}
