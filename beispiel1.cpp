#include "matrixcoo.hpp"
#include "matrixcsr.hpp"
#include "matrixcds.hpp"
#include "vector.hpp"
#include <iostream>

int main()
{
  MatrixCOO<double> A(6u, 6u);
  A(0,0)=1.0; A(0,1)=2.0; A(1,1)=2.0; A(1,4)=5.0; A(2,2)=6.0; A(2,4)=1.0; A(3,0)=7.0; A(3,1)=7.0; A(3,3)=6.0; A(4,1)=8.0; A(4,2)=4.0; A(0,5)=8; A(5,1)=6;
  //A(0,0)=1; A(1,1)=2; A(2,2)=2; A(3,3)=5; A(4,4)=6; A(5,5)=7;
  MatrixCDS<double> Ac(A);
  Ac.diagonalen();
  Ac.value();
  std::cout << Ac.byte() << std::endl;
  
  Vector<double> multi(6u); Vector<double> ziel(6u);
  multi[0]=1; multi[1]=2; multi[2]=3; multi[3]=4; multi[4]=5; multi[5]=10;
  Ac.apply(multi, ziel);
  std::cout << ziel[0]<<"," << ziel[1]<<","  << ziel[2]<<","  << ziel[3]<<","  << ziel[4]<<"," <<ziel[5] << std::endl;
  return 0;
}