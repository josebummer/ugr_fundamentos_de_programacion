/*
Recupere la solución del ejercicio 28 (ventas de empresa) de la relación de problemas
III. Resuelva el problema pedido (calcular la sucursal con mayor número de ventas)
pero ahora considere que no conoce a priori el número de sucursales que hay, aunque
sabe que los códigos de éstas siempre son números entre 1 y 100 y que en total no
hay más de 100 sucursales. Por lo tanto, tendrá que añadir como dato miembro de
la clase, un vector con un tamaño máximo de 100. Cree un programa principal de
prueba.
*/

#include <iostream>

using namespace std;

class Ventas{
	private:
		static const int TAMANIO=100;																//Creamos la constante tamaño
		int id_sucursal[TAMANIO],productos_sucursal[TAMANIO],total_utilizados=0;	//Creamos los vectores y las demas variables
	
	public:
		int GetTamanio(){																	//Nos muestra el tamaño de los vectores
			return TAMANIO;
		}
		
		int GetTotalUtilizados(){														//Nos muestra el valor de total utilizados
			return total_utilizados;
		}
		
		int GetSucursal(int posicion){												//Nos muestra el id de la sucursal que corresponde a una posicion
			if(posicion<total_utilizados && posicion>=0)
				return id_sucursal[posicion];
		}
		void SetSucursal(int id, int productos){									//Nos permite añadir una sucursal con una cantidad de productos iniciales.
			if(total_utilizados<TAMANIO && productos>=0){
				id_sucursal[total_utilizados]=id;
				productos_sucursal[total_utilizados]=productos;
				total_utilizados++;
			}
		}
		
		int GetProductosSucursal(int posicion){									//Nos muestra los productos de una sucursal correspondiente a una posicion
			if(posicion<total_utilizados && posicion>=0)
				return productos_sucursal[posicion];
		}
		
		int MaximoSucursal(){															//Nos devuelve la cantidad maxima de productos entre todas las sucursales
			int maximo=productos_sucursal[0],i;
			
			for(i=1;i<total_utilizados;i++){
				if(GetProductosSucursal(i)>maximo)
					maximo=GetProductosSucursal(i);
			}
			return maximo;
		}
		int IdMaximoSucursal(){															//Nos devuelve el ID de la sucursal que mas productos tenga
			int id_maximo,i,maximo;
			maximo=MaximoSucursal();
			
			for(i=0;i<total_utilizados;i++)
				if(maximo==GetProductosSucursal(i))
					id_maximo=GetSucursal(i);
		return id_maximo;
		}
		
		bool ExisteSucursal(int id){													//Comprueba si la sucursal metida por el usuario existe; Nos sirve para validar
			bool existe=false;
			int i;
			
			for(i=0;i<total_utilizados && !existe;i++)
				if(id==GetSucursal(i))
					existe=true;
			return existe;
		}
	
		void SumarProductos(int sucursal, int cantidad){						//Nos va a sumar los productos indicados por el usuario a una sucursal determinada
			int i;
			bool existe;
			if(ExisteSucursal(sucursal)){												//Nos aseguramos de que la sucursal existe (aunque lo hemos validado en en main)
				for(i=0;i<total_utilizados;i++)
					if(GetSucursal(i)==sucursal)
						productos_sucursal[i]+=cantidad;
			}
		}
		
};

int main(){

	const int FIN=-1;													//Creamos la variable de parada
	char producto;														//Creamos las demas variables de control y de entrada
	bool existe=false;
	Ventas venta_empresa;
	int sucursal, cantidad;
	
	do{
			cout << "Introduce la sucursal (-1 para terminar): ";											//Creamos las sucursales que nosotros deseemos
			cin >> sucursal;
	}while(sucursal<1 && sucursal!=FIN);
		
	while(sucursal!=FIN){
		
		do{
			cout << "Introduce la cantidad inicial de la sucursal " << sucursal << ": ";			//Le ponemos una cantidad inicial a la sucursal
			cin >> cantidad;
		}while(cantidad<0);
		
		venta_empresa.SetSucursal(sucursal,cantidad);						//Creamos la sucursal con el ID obtenido y la cantidad inicial indicada
		
		do{
			cout << "Introduce la sucursal (-1 para terminar): ";							//Volvemos a pedir sucursal para seguir añadiendo mas
			cin >> sucursal;
		}while(sucursal<1 && sucursal!=FIN);
	
	}
	cout << "\nPASEMOS hA INTRODUCIR CANTIDADES A LAS SUCURSALES CREADAS.\n\n";
	
	do{
		cout << "Introduce la sucursal (-1 para salir): ";								//Ahora introducimos los valores para que vaya sumando
		cin >> sucursal;
		existe=venta_empresa.ExisteSucursal(sucursal);									//Comprobamos si el ID existe para poder proseguir y sumarle productos
	}while(!existe && sucursal!=FIN);
	
	while(sucursal!=FIN){
		do{
			cout << "Introduce el producto (a,b,c): ";										//Introducimos un producto (aunque no es relevante)
			cin >> producto;
		}while(producto!='a' && producto!='b' && producto!='c');
		do{
			cout << "Introduce la cantidad: ";											//Introducimos la cantidad de productos a sumar a una sucursal
			cin >> cantidad;
		}while(cantidad<0);
		
		venta_empresa.SumarProductos(sucursal,cantidad);							//Sumamos los productos indicados a la sucurusal indicada
		
		do{
			cout << "Introduce la sucursal (-1 para salir): ";						//Volvemos a introducir sucursal para seguir sumando
			cin >> sucursal;
			existe=venta_empresa.ExisteSucursal(sucursal);
		}while(!existe && sucursal!=FIN);
		
	}
	
	//Mostramos los resultados
	cout << "\nLa sucursal con id " << venta_empresa.IdMaximoSucursal() << " es la sucursal que mas productos a vendido con " << venta_empresa.MaximoSucursal() << " productos.\n\n";
	
system("pause");
}
