/*
Una empresa que tiene tres sucursales decide llevar la contabilidad de las ventas
de sus productos a lo largo de una semana. Para ello registra cada venta con
tres números, el identificador de la sucursal (1, 2 o 3), el código del producto codificado
como un carácter (a, b ó c) y el número de unidades vendidas. Diseñar
un programa que lea desde el teclado una serie de registros compuestos por
sucursal, producto, unidades y diga cuál es la sucursal que más productos
ha vendido. La serie de datos termina cuando la sucursal introducida vale -1.
*/
#include <iostream>

using namespace std;

//Nos va a devolver el valor de la sucrsal
int Sucursal(){

	int sucursal;
	
do{
		cout << "Introduce la sucursal (1,2,3): ";
		cin >> sucursal;
	}while(sucursal !=1 && sucursal !=2 && sucursal!=3 && sucursal!=-1);

return sucursal;
}
// Nos va a delvolver el valor del producto
char Producto(){
	char producto;
	
	do{
			cout << "Introduce el producto (a,b,c): ";
			cin >> producto;
	}while(producto!='a' && producto!='b' && producto!='c');
return producto;
}
//Nos va a devolver el valor de la cantidad
int Cantidad(){
	int cantidad;
	do{
			cout << "Introduce la cantidad: ";
			cin >> cantidad;
		}while(cantidad<=0);
return cantidad;
}

// Con esta funcion preguntamos la cantidad mayor de las tres sumas.
int Maximo(int suma1, int suma2, int suma3){

	int mayor=suma1;						
	
	if (suma1<suma2)
		mayor=suma2;

	if(suma3>mayor)
		mayor=suma3;
	
return mayor;
	
}

// Con esta funcion vamos a sacar cual es el identificador de la sucurasl con mas productos.
char SucursalMayor(int suma1, int suma2, int suma3){

	int mayor=Maximo(suma1,suma2,suma3);			// Samos el mayor con la funcion anterior y ya no guiamos de esa variable
	char sucursalmax;
	
	if (suma1==mayor)
		sucursalmax='1';
	
	else if(suma2==mayor)
		sucursalmax='2';
		
	else{
		sucursalmax='3';
	}
return sucursalmax;
}

// Esta funcion no va a calcular la suma de una sucursal concreta.
int Suma(int total, int cantidad){

return total+cantidad;
}

int main(){

	char producto,sucursalmax;													//Metemos la variables que vamos a necesitar.
	int cantidad,sumauno=0,sumados=0,sumatres=0,maximo,sucursal;
	
	sucursal=Sucursal();								//Con esto pedimos lo datos de entrada
	
	while(sucursal!=-1){
		
		producto=Producto();
		cantidad=Cantidad();
		
		if(sucursal==1)											//Vamos realizando las sumas de la sucursales
			sumauno=Suma(sumauno,cantidad);
		else if (sucursal==2)
			sumados=Suma(sumados,cantidad);
		else
			sumatres=Suma(sumatres,cantidad);
		
		sucursal=Sucursal();											//Volvemos a preguntar
		
	}
	
	maximo=Maximo(sumauno,sumados,sumatres);							//Calculamo el numero maximo de productos
	sucursalmax=SucursalMayor(sumauno,sumados,sumatres);			//Calculamos el numero de la sucursal que corresponde al maximo
	
	if(sumauno==0 && sumados==0 && sumatres==0)
		cout << "\nNo has introducido datos.\n\n";
	else
		cout << "\nLa sucursal " << sucursalmax << " es la que mas ha vendido, vendiendo " << maximo << " productos.\n\n";
		
system("pause");
}
