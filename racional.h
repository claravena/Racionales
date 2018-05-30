// ------------- Archivo racional.h-----------
#ifndef RACIONAL_H
#define RACIONAL_H
#include <iostream>
#include <cmath>
using namespace std;


//----------- Definicion de la clase------------------

template <class T>
class Racional {  

 private:
  T numerador; 
  T denominador;

 public:
  Racional();
  Racional(T , T=1 ); // constructor
  ~Racional(); //destructor racional
  void set_numerador(T);
  void set_denominador(T);
  T get_numerador() const;
  T get_denominador() const; 
  Racional(const Racional &); 
  
};
             
//constructor
template <class T>
Racional<T>::Racional( T x,  T y){
  numerador=x;
  denominador=y;
  
}
template <class T>
Racional<T>::Racional(){
}

template <class T>
Racional<T>::~Racional(){
}

//funcion que asigna numerador
template <class T>
void Racional<T>::set_numerador(T x){
  numerador = x; 
} 
//funcion que asigna denominador  
template <class T>
void Racional<T>::set_denominador(T x){
  denominador = x; 
}

//funcion retorna numerador 
template <class T>
T Racional<T>::get_numerador() const {
  return numerador;  
  }

//funcion retorna denominador
template <class T>
T Racional<T>::get_denominador() const {
  return denominador; 
  }


//Construcctor de copia
template <class T>
Racional<T>::Racional(const Racional<T> & z){
  numerador = z.numerador; 
  denominador = z.denominador;
    }

//MAXIMO COMUN DIVISOR
template<class T>
T MCD(T z1, T z2)
{
  T(0);
  if ( z2==T(0))
    return z1;
  else{
    MCD(z2, z1-(z1*z2/z2));
  }
}

//Simplificar una fraccion 
template <class T>
Racional<T> simplificar(Racional<T> z1){
  return(z1.get_numerador()/(MCD(z1.get_numerador(), z1.get_denominador())), z1.get_denominador()/(MCD(z1.get_numerador(), z1.get_denominador())));

}


//Operador suma
template <class T>
Racional<T> operator + (Racional<T> z1 , Racional<T> z2 ){
  return Racional<T>((z1.get_numerador()*z2.get_denominador()+z2.get_numerador()*z1.get_denominador()),z1.get_denominador()*z2.get_denominador());
}

//Operador resta
template <class T>
Racional<T> operator - (Racional<T> z1, Racional<T> z2){
  return Racional<T>((z1.get_numerador()*z2.get_denominador()-z2.get_numerador()*z1.get_denominador()),z1.get_denominador()*z2.get_denominador());
}

//Operador producto para cualquier tipo  
template <class T>
Racional<T> operator * (Racional<T> z1, Racional<T> z2){
  return Racional<T>(z1.get_numerador()*z2.get_numerador(),z1.get_denominador()*z2.get_denominador());
}


//funcion elevar a un numero entero  
template <class T>
Racional<T> elevar(Racional<T> z1, int z){
  if (z==0){
    return Racional<T>(1);
      }
  
  else if (z>0){
    return Racional<T>(pow(z1.get_numerador(),z), pow(z1.get_denominador(),z));
	}

  else if (z<0){
    return Racional<T>(pow(z1.get_denominador(),fabs(z)),pow(z1.get_numerador(),fabs(z)));
  };
}
	
//Operador division
template <class T>
Racional<T> operator / (Racional<T> z1, Racional<T> z2){
  Racional<T> z3=elevar(z2,-1); 
  return z1*z3; 
}

//operador cout
template <class T>
ostream & operator << (ostream & os, Racional<T> c){
  os << c.get_numerador() << "/" << c.get_denominador(); 
  return os; 
}


#endif
