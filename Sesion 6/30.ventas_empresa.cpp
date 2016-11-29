/*Una empresa que tiene tres sucursales decide llevar la contabilidad de las ventas
de sus productos a lo largo de una semana. Para ello registra cada venta con
tres números, el identificador de la sucursal (1, 2 o 3), el código del producto codificado
como un carácter (a, b ó c) y el número de unidades vendidas. Diseñar
un programa que lea desde el teclado una serie de registros compuestos por
sucursal, producto, unidades y diga cuál es la sucursal que más productos
ha vendido. La serie de datos termina cuando la sucursal introducida vale -1.*/

#include <iostream>

using namespace std;

int main(){
	
	const int FIN=-1;
	char producto;
	int sucursal, cantidad,suma1 = 0, suma2 = 0, suma3 = 0;
	
	do{	 
		cout << "\nIntroduce la sucursal(1,2,3), el codigo(a,b,c) y las ventas separado por un espacio: ";
		cin >> sucursal;
		cin >> producto;
		cin >> cantidad;
	}while((sucursal !=1 && sucursal !=2 && sucursal !=3 && sucursal !=FIN) || (producto !='a' && producto !='b' && producto!='c') || (cantidad<=0));
	
	while(sucursal!=FIN){
	
		if (sucursal == 1)
			suma1 += cantidad;
		else
			if (sucursal == 2)
				suma2 += cantidad;
			else
				suma3+=cantidad;
		
		do{	 
			cout << "\nIntroduce la sucursal(1,2,3), el codigo(a,b,c) y las ventas separado por un espacio: ";
			cin >> sucursal;
			cin >> producto;
			cin >> cantidad;
		}while((sucursal !=1 && sucursal !=2 && sucursal !=3 && sucursal !=-1) || (producto !='a' && producto !='b' && producto!='c') || (cantidad<=0));
	}
		
	if (suma1 !=0)
	cout << "\nLa sucursal 1 a vendido en total " << suma1 << " productos.";
	if (suma2!=0)
	cout << "\nLa sucursal 2 a vendido en total " << suma2 << " productos.";
	if (suma3!=0)
	cout << "\nLa sucursal 3 a vendido en total " << suma3 << " productos.";
	
	cout << "\n\n";
system("pause");

}
