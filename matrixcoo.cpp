#include "matrixcoo.hpp"
#include <cassert>
#include <iostream>

template<class T>
// Standardkonstruktor
MatrixCOO<T>::MatrixCOO():
zeilen(0u), spalten(0u), data(nullptr) { };

template<class T>
// Benuterdefinierter Konstruktor
MatrixCOO<T>::MatrixCOO(unsigned long _zeilen, unsigned long _spalten) :
zeilen(_zeilen), spalten(_spalten), data(nullptr)
{
	if(_zeilen > 0u && _spalten >0u)
	{
		k=0;
		zeilenindex = new unsigned long[_zeilen*_spalten];
		spaltenindex = new unsigned long[_zeilen*_spalten];
		data = new T[_zeilen*_spalten];
	}
}
 


template<class T>
// Destruktor
  MatrixCOO<T>::~MatrixCOO() 
  {
   if(data != nullptr)
     delete [] data;
   if(spaltenindex != nullptr)
     delete [] spaltenindex;
   if(zeilenindex != nullptr)
     delete [] zeilenindex;
  };


template<class T>
// Überladung (), Matrixeinträge
T& MatrixCOO<T>::operator()(unsigned long i, unsigned long j)
{
	assert(i < zeilen);
        assert(j < spalten);
	assert(data != nullptr);
	for(unsigned long l(0u); l<k; l++)
	{
		if((zeilenindex[l] == i) && (spaltenindex[l] == j))
			return data[l];
			
	}
	k++;
	zeilenindex[k-1]=i;
	spaltenindex[k-1]=j;
	return data[k-1];
}


template<class T>
// Zeilen
  unsigned long MatrixCOO<T>::get_zei()
  {
    return zeilen;
  }
  
template<class T>
// Spalten
  unsigned long MatrixCOO<T>::get_spa()
  {
    return spalten;
  }

template<class T>
// k
  unsigned long MatrixCOO<T>::get_k()
  {
    return k;
  }


template<class T>
  unsigned long MatrixCOO<T>::get_zeilenindex(unsigned long i)
  {
    assert(i < k);
    assert(zeilenindex != nullptr);
    return zeilenindex[i];
  }

template<class T>
  unsigned long MatrixCOO<T>::get_spaltenindex(unsigned long i)
  {
    assert(i < k);
    assert(spaltenindex != nullptr);
    return spaltenindex[i];
  }











  template class MatrixCOO<double>;
  template class MatrixCOO<float>;
  template class MatrixCOO<int>;
