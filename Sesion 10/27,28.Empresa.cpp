/*
Recuperad la solución del ejercicio 30 de la Relación de Problemas II (Empresa). Reescribid
el programa principal usando una clase Ventas para gestionar los cómputos
de las ventas realizadas. Únicamente se pide que se indiquen las cabeceras de los
métodos públicos de la clase y las llamadas a éstos en el programa principal. No hay
que implementar ninguno de los métodos.
Debe suponer que la clase gestionará las ventas de exactamente tres sucursales. Los
códigos de dichas sucursales son enteros cualesquiera (no necesariamente 1, 2, 3,
como ocurría en el ejercicio 30 de la Relación de Problemas II)
*/

#include <iostream>

using namespace std;

class Ventas{
	private:
		static const int TAMANIO=3;												//Creamos la constante para indicar el tamaño
		int id_sucursal[TAMANIO],productos_sucursal[TAMANIO];				//Creamos dos vectores que nos indicaran el id y la cantidad de cada sucursal
	
	public:
		Ventas(){																		//Creamos un constructor por defecto.
			int i;
			
			for(i=0;i<3;i++){
				id_sucursal[i]=i+1;
				productos_sucursal[i]=0;
			}
		}
		Ventas(int id_sucursal1, int productos_sucursal1, int id_sucursal2, int productos_sucursal2, int id_sucursal3, int productos_sucursal3){	/* Creamos un
		constructor que nos permitira introducir datos al crear el objeto de la clase.*/
			id_sucursal[0]=id_sucursal1;
			productos_sucursal[0]=productos_sucursal1;
			id_sucursal[1]=id_sucursal2;
			productos_sucursal[1]=productos_sucursal2;
			id_sucursal[2]=id_sucursal3;
			productos_sucursal[2]=productos_sucursal3;
		}
		
		int GetSucursal(int posicion){						//Con este metodo podremos ver el valor que tiene sucursal
			if(posicion<3 && posicion>=0)
				return id_sucursal[posicion];
		}
		void SetSucursal(int posicion, int id){			//Con este otro metodo podremos meterle un valor a una sucursal
			if(posicion<3 && posicion>=0)
				id_sucursal[posicion]=id;
		}
		
		int GetProductosSucursal(int posicion){				//Este modulo nos mostrara la cantidad de productos que tiene una sucursal determinada.
			if(posicion<3 && posicion>=0)
				return productos_sucursal[posicion];
		}
		void SetProductosSucursal(int posicion, int cantidad){			//Con este modulo podremos meter cantidad a una sucursal determinada.
			if(posicion<3 && posicion>=0)
				productos_sucursal[posicion]=cantidad;
		}
		
		void SumarProductos(int sucursal, int cantidad){			//Podremos sumar una cantidad al total de productos de una sucursal
			int i;
			for(i=0;i<3;i++)
				if(GetSucursal(i)==sucursal)
					productos_sucursal[i]+=cantidad;
		}
		
		int MaximoSucursal(){											//Con esto podremos obtener la cantidad maxima de productos de todas las sucursales
			int maximo=GetProductosSucursal(0);
			if(GetProductosSucursal(1)>maximo)
				maximo=GetProductosSucursal(1);
			if(GetProductosSucursal(2)>maximo)
				maximo=GetProductosSucursal(2);
			return maximo;
		}
		int IdMaximoSucursal(){											//Con esta tendremos el ID de la sucursal con mas productos de todas
			int id_maximo,i,maximo;
			maximo=MaximoSucursal();
			for(i=0;i<3;i++)
				if(maximo==GetProductosSucursal(i))
					id_maximo=GetSucursal(i);
		return id_maximo;
		}
};

int main(){

	const int FIN=-1;															//Creamos la constante FIN con el valor de parada
	char producto;
	Ventas venta_empresa;
	int sucursal, cantidad,i;
	
	for(i=0;i<3;i++){
		do{
			cout << "Introduce la sucursal: ";													//Pedimos los datos de entrada
			cin >> sucursal;
		}while(sucursal<1);
		venta_empresa.SetSucursal(i,sucursal);													//Si la sucursal es aceptable creamos la sucursal
		do{
			cout << "Introduce la cantidad inicial de la sucursal " << venta_empresa.GetSucursal(i) << ": ";		//Indicamos la cantidad de productos para la sucursal
			cin >> cantidad;
		}while(cantidad<0);
		venta_empresa.SetProductosSucursal(i,cantidad);		//Ponemos la cantidad indicada a la sucursal creada.
	}
	cout << "PASEMOS hA INTRODUCIR CANTIDADES A LAS SUCURSALES CREADAS.\n\n";
	
	do{
			cout << "Introduce la sucursal (-1 para salir): ";				//Metemos una sucursal de las que tenemos creadas.
			cin >> sucursal;
		}while(sucursal!=venta_empresa.GetSucursal(0) && sucursal!=venta_empresa.GetSucursal(1) && sucursal!=venta_empresa.GetSucursal(2) && sucursal!=FIN);
	
	while(sucursal!=FIN){
		do{
			cout << "Introduce el producto (a,b,c): ";			//Introducimos el producto
			cin >> producto;
		}while(producto!='a' && producto!='b' && producto!='c');
		do{
			cout << "Introduce la cantidad: ";									//Introducimos la cantidad de productos a sumar
			cin >> cantidad;
		}while(cantidad<0);
		
		venta_empresa.SumarProductos(sucursal,cantidad);											//Sumamos la cantidad a la sucursal indicada.
		
		do{
			cout << "\nIntroduce la sucursal (-1 para salir): ";						//Volvemos a introducir la sucursal para seguir sumando productos
			cin >> sucursal;
		}while(sucursal!=venta_empresa.GetSucursal(0) && sucursal!=venta_empresa.GetSucursal(1) && sucursal!=venta_empresa.GetSucursal(2) && sucursal!=FIN);
		
	}
	
	cout << "\nLa sucursal con id " << venta_empresa.IdMaximoSucursal() << " es la sucursal que mas productos a vendido con " << venta_empresa.MaximoSucursal() << " productos.\n\n";
	//Mostramos el resultado final como se pide en el ejercicio, mostrando el ID y la cantidad de la sucursal con mas productos vendidos.
	
system("pause");
}
