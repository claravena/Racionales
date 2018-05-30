#include <iostream>
#include <cmath>
#include <complex>
#include "racional.h"

using namespace std;



int main()
{
  //Complejos para evaluar
  complex<double> z1(1.,1.);
  complex<double> z2(1.,-1.);

  //Complejos para para pasar al dual
  complex<double> cero(0.0,0.0);
  complex<double> uno(1.0,0.0);

  //hacer de los complejos racionales
  Racional<complex<double>> r1(z1,uno);
  Racional<complex<double>> r2(z2,uno);
  Racional<complex<double>> r0(cero,uno);
  Racional<complex<double>> uno1(uno,uno);

  cout << r1+r2 <<endl; 

  
 
  return 0; 
  
}





