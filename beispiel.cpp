#include "matrixcoo.hpp"
#include "matrixcsr.hpp"
#include "matrixcds.hpp"
#include "vector.hpp"
#include <iostream>

int main()
{
	MatrixCOO<double> A(6u, 6u);
	A(0,0)=10;
	A(1,0)=3;
	A(1,1)=9;
	A(2,1)=7;
	A(2,2)=8;
	A(3,2)=8;
	A(3,3)=7;
	A(4,3)=9;
	A(4,4)=9;
	A(5,4)=2;
	A(5,5)=-1;
	A(0,1)=-3;
	A(1,2)=6;
	A(2,3)=7;
	A(3,4)=5;
	A(4,5)=13;




	MatrixCSR<double> B(A);
	for(unsigned int i(0); i<A.get_k(); i++)
		std::cout << B.get_col_ind(i) << " ";
	std::cout << std::endl;
	for(unsigned int i(0); i<A.get_k(); i++)
		std::cout << double(B.get_val(i)) << " ";
	std::cout << std::endl;
	for(unsigned int i(0); i<7; i++)
		std::cout << B.get_row_ptr(i) << " ";
	std::cout << std::endl;




	MatrixCDS<double> C(A);
	for(unsigned int i(0); i<6; i++)
		std::cout << C.get_val1(i) << " ";
	std::cout << std::endl;
	for(unsigned int i(0); i<6; i++)
		std::cout << C.get_val2(i) << " ";
	std::cout << std::endl;
	for(unsigned int i(0); i<6; i++)
		std::cout << C.get_val3(i) << " ";
	std::cout << std::endl;




	Vector<double> b(6u);
	b[0]=1;
	b[1]=2;
	b[2]=3;
	b[3]=4;
	b[4]=5;
	b[5]=6;



	Vector<double> c(6u);
	B.apply(b, c);
	for(unsigned int i(0); i<6; i++)
		std::cout << c[i] << "   ";
	std::cout << std::endl;



	Vector<double> d(6u);
	C.apply(b, d);
	for(unsigned int i(0); i<6; i++)
		std::cout << d[i] << "   ";
	std::cout << std::endl;




	std::cout << "Die Matrix B benötigt " << B.byte() << "Byte Speicher" << std::endl;
	std::cout << "Die Matrix C benötigt " << C.byte() << "Byte Speicher" << std::endl;
	return 0;
}
