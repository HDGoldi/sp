#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "matrix.hpp"

template<class T>
class Vector
{
  private:
  unsigned long size;
  T* data;
  Vector();
  Vector(const Vector<T>& other); //Kopier-Konstruktor
  
  public:
    template<class U>
    friend class Matrix;
  void copy(const Vector<T>& other);
  explicit Vector(unsigned long len);
  ~Vector();
  unsigned int get_size();
  T& operator[](unsigned int i);
  Vector<T>& operator=(const Vector<T>& other);
  Vector<T> operator+(const Vector<T>& other);
  Vector<T> operator-(const Vector<T>& other);
  T operator*(const Vector<T>& other);
  Vector<T> axpy(Vector<T>& y, T alpha);
};

#endif // VECTOR_HPP