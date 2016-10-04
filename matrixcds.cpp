#include "matrixcoo.hpp"
#include "matrixcds.hpp"
#include "vector.hpp"
#include <cassert>
#include <iostream>

template<class T>
// Benutzerdefinierter Konstruktor
MatrixCDS<T>::MatrixCDS(MatrixCOO<T>& other):
	zeilen(other.get_zei()), spalten(other.get_spa()), val1(nullptr), val2(nullptr), val3(nullptr)
{
	assert(zeilen == spalten);
	val1 = new T[zeilen];
	val2 = new T[zeilen];
	val3 = new T[zeilen];
	for(unsigned int i(0); i < zeilen; i++)
	{
		val2[i] = other(i,i); 
	}
	for(unsigned int i(0); i < zeilen-1; i++)
	{
		val1[i] = other(i,i+1);
	}	
	val1[zeilen-1]=0;
	for(unsigned int i(1); i < zeilen; i++)
	{
		val3[i] = other(i,i-1); 
	}	
	val3[0]=0;
}

template<class T>
// Destruktor
  MatrixCDS<T>::~MatrixCDS() 
  {
   if(val1 != nullptr)
     delete [] val1;
   if(val2 != nullptr)
     delete [] val2;
   if(val3 != nullptr)
     delete [] val3;
  };


template<class T>
// Speicherverbrauch
unsigned int MatrixCDS<T>::byte()
{
	T a(0);
	for(unsigned int i(0); i < zeilen; i++)
		a += sizeof(val1[i]) + sizeof(val2[i]) +sizeof(val3[i]);
	return a;
}


template<class T>
// Zeilen
  unsigned int MatrixCDS<T>::get_zei()
  {
    return zeilen;
  }
  
template<class T>
// Spalten
  unsigned int MatrixCDS<T>::get_spa()
  {
    return spalten;
  }


template<class T>
// Matrix-Vektor-Multiplikation
  void MatrixCDS<T>::apply(Vector<T>& other, Vector<T>& result)
  {
    assert(spalten == other.get_size());
    assert((val1 != nullptr) && (val2 !=nullptr) && (val3 != nullptr));
    assert(zeilen == result.get_size()); 
    result[0] = (other[1]*val1[0]) + (other[0]*val2[0]);
    for(unsigned int i(1); i < zeilen-1; i++)
    {
	result[i] = val1[i]*other[i+1]+val2[i]*other[i]+val3[i]*other[i-1];
    }
    result[zeilen-1] = val2[zeilen-1]*other[zeilen-1]+val3[zeilen-1]*other[zeilen-2]; 
    return;
  }

template<class T>
// val1
 T& MatrixCDS<T>::get_val1(unsigned int i)
{
assert(i < zeilen);
return val1[i];
}
template<class T>
// val2
 T& MatrixCDS<T>::get_val2(unsigned int i)
{
assert(i < zeilen);
return val2[i];
}
template<class T>
// val3
 T& MatrixCDS<T>::get_val3(unsigned int i)
{
assert(i < zeilen);
return val3[i];
}


template class MatrixCDS<double>;
template class MatrixCDS<float>;
template class MatrixCDS<int>;
