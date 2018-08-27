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
  Racional(T=T(1),T=T(1)); // constructor
  ~Racional(); //destructor racional
  void set_numerador(T);
  void set_denominador(T);
  T get_numerador() const;
  T get_denominador() const; 
  Racional(const Racional<T> &);
  Racional & operator = (const Racional<T> & ); 
  
};


//constructor
template <class T>
Racional<T>::Racional( T x,  T y){
  //implementacion del algoritmo de euclides para reducir la fraccion. 
  T X1=x;
  T X2=y;
  while(X2!=T(0)){
    T aux_X1=X1;
    T aux_X2=X2;
    X1=X2;
    X2=aux_X1-aux_X1/aux_X2*aux_X2;
  };
  numerador=x/X1;
  denominador=y/X1;
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


//######################################Operadores ##########################################################################


//Operador asignacion
template <class T>
Racional<T> &Racional<T>::operator = (const Racional<T> & R){
  numerador = R.get_numerador();
  denominador=R.get_denominador();
  return *this; 
}

//Operador suma
template <class T>
Racional<T> operator + (Racional<T> z1 , Racional<T> z2 ){
  return Racional<T>((z1.get_numerador()*z2.get_denominador()+z2.get_numerador()*z1.get_denominador()),z1.get_denominador()*z2.get_denominador());
}

//Operador producto para cualquier tipo  
template <class T>
Racional<T> operator * (Racional<T> z1, Racional<T> z2){
  return Racional<T>(z1.get_numerador()*z2.get_numerador(),z1.get_denominador()*z2.get_denominador());
}

//Operador producto por la izquierda para aumenta en a la fraccion 
template <class T>
Racional<T> operator * (T a, Racional<T> z1){
  Racional<T> z2(a,T(1)); 
  return z1*z2;
}


//Operador producto por la derecha para aumenta en a la fraccion 
template <class T>
Racional<T> operator * (Racional<T> z1, T a){ 
  return a*z1;
}

//Operador resta
template <class T>
Racional<T> operator - (Racional<T> z1, Racional<T> z2){
 return z1+T(-1)*z2;
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
ostream & operator << (ostream & os, Racional<T> & c){
  if (c.get_denominador()==T(1)){
    os << c.get_numerador(); 
    return os;
  }
  else{
    if(c.get_denominador()<T(0.0)){
      os << T(-1)*c.get_numerador() << "/" << abs(c.get_denominador()); 
      return os;
    }
    else{
      os << c.get_numerador() << "/" << c.get_denominador(); 
      return os;
    }
  }
}
#endif
