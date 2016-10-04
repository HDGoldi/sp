#ifndef MATRIXCSR_HPP
#define MATRIXCSR_HPP
#include "vector.hpp"

template<class T>
class Vector;


template<class T>
class MatrixCSR
{
	private:
	unsigned int* col_ind;
	unsigned int* row_ptr;
	unsigned int size;
	unsigned int zeilen;
	unsigned int spalten;
	T* val;
	MatrixCSR<T>();
	MatrixCSR(const MatrixCSR<T>& other);

	public:
	MatrixCSR(MatrixCOO<T>& other);
	~MatrixCSR();
	unsigned int get_zei();
	unsigned int get_spa();
	unsigned int get_size();
	unsigned int get_col_ind(unsigned int i);
	T& get_val(unsigned int i);
	unsigned int get_row_ptr(unsigned int i);
	unsigned int byte();

	void apply(Vector<T>& other, Vector<T>& result);
};



#endif // MATRIXCSR_HPP
