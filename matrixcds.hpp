#ifndef MATRIXCDS_HPP
#define MATRIXCDS_HPP
#include "vector.hpp"

template<class T>
class Vector;


template<class T>
class MatrixCDS
{
	private:
	unsigned int zeilen;
	unsigned int spalten;
	T* val;
	int* diag;
	unsigned int anzdiag;
	MatrixCDS<T>();
	MatrixCDS(const MatrixCDS<T>& other);

	public:
	MatrixCDS(MatrixCOO<T>& other);
	~MatrixCDS();
	int& get_diag(unsigned int i);
	T& get_val(unsigned int i);
	void diagonalen();
	void value();
	unsigned int byte();
	void apply(Vector<T>& other, Vector<T>& result);
};
#endif // MATRIXCDS_HPP
