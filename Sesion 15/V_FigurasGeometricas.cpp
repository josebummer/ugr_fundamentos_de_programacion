////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

// Cuadrado, Punto, Segmento y Circunferencia

/*
 Recuperad las implementaciones de las clases Punto2D , SegmentoDirigido ,
Circunferencia y Cuadrado , disponibles en el fichero
FigurasGeometricas.cpp disponible en decsai . Las tres primeras se han
visto en clase de teoría. Con respecto al cuadrado, éste viene determinado por el
punto correspondiente a la esquina inferior izquierda y por la longitud de cualquiera de
sus lados (estos serán sus datos miembros). Supondremos que sólo representamos
cuadrados cuya base es paralela al eje de las abscisas.

Definid sobre la clase Cuadrado los siguientes métodos:

• Métodos para calcular el área y el perímetro del cuadrado.
• Obtener el punto central interior al cuadrado:
Punto2D Centro()
Para calcular las coordenadas basta sumar la mitad de la longitud del cuadrado
a las coordenadas de la esquina inferior izquierda.
• Obtener la circunferencia inscrita al cuadrado (la que está por dentro):
Circunferencia CircunferenciaInscrita()
Esta circunferencia es la que tiene como centro el centro del cuadrado y como
radio la mitad de la longitud del cuadrado.
• Obtener la circunferencia circunscrita al cuadrado (la que está por fuera):
Circunferencia CircunferenciaCircunscrita()
Esta circunferencia es la que tiene como centro el centro del cuadrado y como
radio, la longitud del segmento que une el centro con la esquina inferior izquier-
da. Obtened la longitud creando el objeto de la clase SegmentoDirigido y a
continuación llamad al método Longitud.

Complete el programa principal de prueba que se encuentra en el fichero
FigurasGeometricas.cpp
*/

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415927;

bool SonIguales(double uno, double otro){
    return abs(uno-otro) <= 1e-6;
}

/////////////////////////////////////////////////////////////////////////
class Punto2D{
private:
   double abscisa  = 0.0;
   double ordenada = 0.0;
public:
   Punto2D(double abscisaPunto, double ordenadaPunto)
   {
      SetCoordenadas(abscisaPunto, ordenadaPunto);
   }
   
   double Abscisa(){
      return abscisa;
   }
   
   double Ordenada(){
      return ordenada;
   }
   
   void SetCoordenadas(double abscisaPunto, double ordenadaPunto){
      if (! SonIguales(abscisaPunto, ordenadaPunto)){
         abscisa = abscisaPunto;
         ordenada = ordenadaPunto;
      }
   }
   
   bool EsIgual_a (Punto2D otro_punto){
      return (SonIguales(abscisa, otro_punto.abscisa)
              &&
              SonIguales(ordenada, otro_punto.ordenada));
   }
};

/////////////////////////////////////////////////////////////////////////
class SegmentoDirigido{
private:
   double x_1 = 0.0,
          y_1 = 0.0,
          x_2 = 0.0,
          y_2 = 0.0;
   
   bool SonCorrectos(double origen_abscisa, double origen_ordenada,
                     double final_abscisa,  double final_ordenada){
 
      return !(origen_abscisa == final_abscisa
               &&
               origen_ordenada == final_ordenada);
   }
   
public:
   SegmentoDirigido(double origen_abscisa, double origen_ordenada,
                    double final_abscisa, double final_ordenada){

      SetCoordenadas(origen_abscisa, origen_ordenada,
                     final_abscisa, final_ordenada);
   }
   
   void SetCoordenadas(double origen_abscisa, double origen_ordenada,
                       double final_abscisa,  double final_ordenada){
      if (SonCorrectos(origen_abscisa, origen_ordenada,
                       final_abscisa, final_ordenada)){
         x_1 = origen_abscisa;
         y_1 = origen_ordenada;
         x_2 = final_abscisa;
         y_2 = final_ordenada;
      }
   }
   
   double OrigenAbscisa(){
      return x_1;
   }
   
   double OrigenOrdenada(){
      return y_1;
   }
   
   double FinalAbscisa(){
      return x_2;
   }
   
   double FinalOrdenada(){
      return y_2;
   }
   
   double Longitud(){
      return sqrt((x_2 - x_1)*(x_2 - x_1) +
                  (y_2 - y_1)*(y_2 - y_1));
   }
   
   void TrasladaHorizontal(double unidades){
      x_1 = x_1 + unidades;
      x_2 = x_2 + unidades;
   }
   
   void TrasladaVertical(double unidades){
      y_1 = y_1 + unidades;
      y_2 = y_2 + unidades;
   }
};


/////////////////////////////////////////////////////////////////////////
class Circunferencia{
private:
   double centro_x = 0.0;
   double centro_y = 0.0;
   double radio    = 0.0;
      
   bool EsCorrectoRadio(double longitud_radio){
      return longitud_radio > 0; 
   }
public:
   Circunferencia(double abscisa_centro, double ordenada_centro,
                  double longitud_radio){
      SetCentro(abscisa_centro, ordenada_centro);
      SetRadio(longitud_radio);
   }
   
   void SetRadio(double longitud_radio){
      if (EsCorrectoRadio(longitud_radio))
         radio = longitud_radio;
   }
   
   void SetCentro(double abscisa_centro, double ordenada_centro){
      centro_x = abscisa_centro;
      centro_y = ordenada_centro;
   }

   double AbscisaCentro(){
      return centro_x;
   }
   
   double OrdenadaCentro(){
      return centro_y;
   }
   
   double Radio(){
      return radio;
   }
   
   double Longitud(){
      return 2*PI*radio;
   }
   
   double Area(){
      return PI*radio*radio;
   }
   
   void Traslada(double en_horizontal, double en_vertical){
      centro_x = centro_x + en_horizontal;
      centro_y = centro_y + en_vertical;
   }
};


/////////////////////////////////////////////////////////////////////////

class Cuadrado{
private:
   double esquina_abscisa;
   double esquina_ordenada;
   double longitud;

   bool EsCorrectaLongitud(double longitud){
      return longitud > 0; 
   }
public:
   Cuadrado(double esquina_abscisa_cuadrado,
            double esquina_ordenada_cuadrado,
            double longitud_cuadrado){

      SetLongitud(longitud_cuadrado);
      SetEsquinaInfIzq(esquina_abscisa_cuadrado, esquina_ordenada_cuadrado);
   }
   
   void SetLongitud(double longitud_cuadrado){
      if (EsCorrectaLongitud(longitud_cuadrado))
         longitud = longitud_cuadrado;
   }

   void SetEsquinaInfIzq(double esquina_abscisa_cuadrado,
                         double esquina_ordenada_cuadrado){
      esquina_abscisa = esquina_abscisa_cuadrado;
      esquina_ordenada = esquina_ordenada_cuadrado;
   }
   
   double AbscisaEsquina(){
      return esquina_abscisa;
   }

   double OrdenadaEsquina(){
      return esquina_ordenada;
   }

   double Longitud(){
      return longitud;
   }


   double Area(){
      return longitud*longitud;
   }

   double Perimetro(){
      return longitud*4;
   }

   SegmentoDirigido Lado1(){
      SegmentoDirigido lado(esquina_abscisa, esquina_ordenada, 
                            esquina_abscisa + longitud, esquina_ordenada);
      return lado;
   }
   
   SegmentoDirigido Lado2(){
      SegmentoDirigido lado(esquina_abscisa + longitud, esquina_ordenada, 
                            esquina_abscisa + longitud, esquina_ordenada + longitud);
      return lado;
   }
   
   SegmentoDirigido Lado3(){
      SegmentoDirigido lado(esquina_abscisa + longitud, esquina_ordenada + longitud, 
                            esquina_abscisa, esquina_ordenada + longitud);
      return lado;
   }
   
   SegmentoDirigido Lado4(){
      SegmentoDirigido lado(esquina_abscisa, esquina_ordenada + longitud, 
                            esquina_abscisa, esquina_ordenada);
      return lado;
   }
   
   Punto2D Centro(){
   	Punto2D centro(esquina_abscisa+longitud/2,esquina_ordenada+longitud/2);
      return centro;
   }

   Circunferencia CircunferenciaInscrita(){
      Circunferencia cir_interior(esquina_abscisa+longitud/2,esquina_ordenada+longitud/2,longitud/2);
      return cir_interior;
   }

   Circunferencia CircunferenciaCircunscrita(){
      SegmentoDirigido segmento(esquina_abscisa+longitud/2,esquina_ordenada+longitud/2,esquina_abscisa,esquina_ordenada);
      float longitud = segmento.Longitud();
      Circunferencia cir_exterior(esquina_abscisa+longitud/2,esquina_ordenada+longitud/2,longitud);
      return cir_exterior;
   }

   bool MayorArea_que(Cuadrado otro_cuadrado){
   	bool mayor=false;
      if (Area()>otro_cuadrado.Area())
			mayor=true;
		return mayor; 
   }

   bool Contiene(Cuadrado otro){
   	bool contiene=false;
      if(otro.AbscisaEsquina()>=esquina_abscisa && otro.AbscisaEsquina()+otro.Longitud()<=esquina_abscisa+longitud && otro.OrdenadaEsquina()>=esquina_ordenada && otro.OrdenadaEsquina()+otro.Longitud()<=esquina_ordenada+longitud)
      	contiene=true;
      return contiene;
   }
};

/////////////////////////////////////////////////////////////////////////



int main(){
   double esquina_x, esquina_y, long_cuadrado;

   cout << "Introduzca la abscisa de la esquina inferior izquierda del cuadrado ";
   cin >> esquina_x;
   cout << "\nIntroduzca la ordenada de la esquina inferior izquierda del cuadrado  ";
   cin >> esquina_y;
   cout << "\nIntroduzca la longitud del cuadrado ";
   cin >> long_cuadrado;

   // Creamos el objeto cuadrado_A como un cuadrado con los datos anteriores

   Cuadrado cuadrado_A(esquina_x, esquina_y, long_cuadrado);      // Constructor usual con parámetros
   
   // Creamos las circunferencias inscritas y circunscritas a cuadrado_A
   // Las llamamos circunf_interior_cuadrado y circunf_exterior_cuadrado
   // Calculamos e imprimimos sus longitudes,
   // así como las áreas de los correspondientes círculos
   // Imprimimos el área de cuadrado_A
   
   Circunferencia circunf_interior_cuadrado=cuadrado_A.CircunferenciaInscrita();
   Circunferencia circunf_exterior_cuadrado=cuadrado_A.CircunferenciaCircunscrita();

   cout << "\nCuadrado: ";
   cout << "\nÁrea:     " << cuadrado_A.Area();
   cout << "\n\nCircunferencia interior:";
   cout << "\nLongitud:     " << circunf_interior_cuadrado.Longitud();
   cout << "\nÁrea circulo: " << circunf_interior_cuadrado.Area();

   cout << "\n\nCircunferencia exterior:";
   cout << "\nLongitud:     " << circunf_exterior_cuadrado.Longitud();
   cout << "\nÁrea circulo: " << circunf_exterior_cuadrado.Area();


   // Creamos cuadrado_B a partr de los datos introducidos para el primero
   // Imprimimos las coordenas del punto central

   Cuadrado cuadrado_B(esquina_x + 1, esquina_y + 1, long_cuadrado - 2);   // Constructor usual con parámetros
   
   // Obtenemos el punto central de cuadrado_B
   
   Punto2D centro=cuadrado_B.Centro();
   
   cout << "\n\nSegundo cuadrado.";
   cout << "\nCoordenadas del punto central: ";
   cout << centro.Abscisa() << " , " << centro.Ordenada();
   
   // Comprobamos si cuadrado_B contiene a cuadrado_A

   if (cuadrado_B.Contiene(cuadrado_A))
      cout << "\nCuadrado B contiene a cuadrado A";
   else
      cout << "\nCuadrado B no contiene a cuadrado A";

   cout << "\n\n";
   
   // Entrada:
   // 3 2   7
   // Área: 49
   // Interior: Longitud: 21.9911, Área: 38.4845
   // Exterior: Longitud: 31.1002, Área: 76.969
   // Centro del segundo: 6.5, 5.5
   // B no contiene a A
}
