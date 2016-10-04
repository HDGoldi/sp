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
	T* val1;
	T* val2;
	T* val3;
	MatrixCDS<T>();
	MatrixCDS(const MatrixCDS<T>& other);

	public:
	MatrixCDS(MatrixCOO<T>& other);
	~MatrixCDS();
	unsigned int get_zei();
	unsigned int get_spa();
	unsigned int byte();
	T& get_val1(unsigned int i);
	T& get_val2(unsigned int i);
	T& get_val3(unsigned int i);
	void apply(Vector<T>& other, Vector<T>& result);
};
#endif // MATRIXCDS_HPP
