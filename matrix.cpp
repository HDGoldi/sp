#include "matrix.hpp"
#include "vector.hpp"
#include <cassert>

template<class T>
// Standardkonstruktor
Matrix<T>::Matrix():
zeilen(0u), spalten(0u), data(nullptr) { };

template<class T>
// Benutzerdefinierter Konstruktor
Matrix<T>::Matrix(unsigned long zei, unsigned long spa) :
	zeilen(zei), spalten(spa), data(nullptr)
	{
	 if(zei > 0u && spa >0u)
	   data = new T[zei*spa];
	};

template<class T>
// Kopier-Konstruktor
Matrix<T>::Matrix(const Matrix& other)
{
  data = new T[spalten*zeilen];
};

template<class T>
// Destruktor
  Matrix<T>::~Matrix() 
  {
   if(data != nullptr)
     delete [] data;
  };
  
template<class T>
// Zeilen
  unsigned int Matrix<T>::get_zei()
  {
    return zeilen;
  }
  
template<class T>
// Spalten
  unsigned int Matrix<T>::get_spa()
  {
    return spalten;
  }
  
template<class T>
// Überladung (), Matrixeinträge
  T& Matrix<T>::operator()(unsigned int i, unsigned int j)
  {
    assert(i < zeilen);
    assert(j < spalten);
    assert(data != nullptr);
    return data[i*spalten+j];
  }
  
template<class T>
// Kopier-Funktion
 void Matrix<T>::copy(const Matrix<T>& other) 
  {
   if(zeilen > 0u && spalten > 0u)
   {
    assert(other.data != nullptr);
    
    //kopiere Array-Inhalte
    for(unsigned int i(0); i <= spalten*zeilen; i++)
      this->data[i] = other.data[i];
   }
  }
  
template<class T>
// Überladung =
  Matrix<T>& Matrix<T> :: operator=(const Matrix<T>& other)
  {
    assert(this->get_zei() == other.zeilen && this->get_spa() == other.spalten);
    this->copy(other);
    return *this;
  }
  
template<class T>
// Matrix-Vektor-Multiplikation
  Vector<T> Matrix<T>::apply(Vector<T>& other)
  {
    assert(this->get_spa() == other.get_size());
    assert(data != nullptr);
    
    Vector<T> result(zeilen);
    
    for(unsigned int i(0); i < zeilen; i++)
    {T k(0);
      for(unsigned int j(0); j < spalten; j++)
	{
	  k += (this->data[(i)*spalten+j]*other[j]);
	};
      result[i] = k;
    }; 
    return result;
  }
  
  
  
  template class Matrix<double>;
  template class Matrix<float>;
  template class Matrix<int>;
