#ifndef MATRIX_HPP
#define MATRIX_HPP
#include "vector.hpp"

template<class T>
class Vector;

template<class T>
class Matrix
{
  private:
  unsigned long zeilen;
  unsigned long spalten;
  T* data;
  Matrix();
  Matrix(const Matrix<T>& other);
  
  public:
  void copy(const Matrix<T>& other);
  explicit Matrix(unsigned long zei, unsigned long spa);
  ~Matrix();
  unsigned int get_zei();
  unsigned int get_spa();
  T& operator()(unsigned int i, unsigned int j);
  Matrix<T>& operator=(const Matrix<T>& other);
  Vector<T> apply(Vector<T>& other);
};

#endif // MATRIX_HPP