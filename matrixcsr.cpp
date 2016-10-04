#include "matrixcoo.hpp"
#include "matrixcsr.hpp"
#include "vector.hpp"
#include <cassert>
#include <iostream>

template<class T>
// Standardkonstruktor
MatrixCSR<T>::MatrixCSR():
col_ind(nullptr), row_ptr(nullptr), val(nullptr) { };

template<class T>
// Benutzerdefinierter Konstruktor
MatrixCSR<T>::MatrixCSR(MatrixCOO<T>& other)
{
	size = other.get_k();
	zeilen = other.get_zei();
	spalten = other.get_spa();
	val = new T[size];
	col_ind = new unsigned int[size];
	row_ptr = new unsigned int[size+1];
	unsigned int counter1 = 0;
        unsigned int cr;
	unsigned int counter2 = 0;
	for(unsigned int i(0); i < zeilen; i++)
	{
		cr = 0;
		for(unsigned int j(0); j < spalten; j++)
		{
			for(unsigned int l(0); l < size; l++)
			{
				if((other.get_zeilenindex(l) == i) && (other.get_spaltenindex(l) == j))
				{
					col_ind[counter2] = j+1;
					val[counter2] = other(i,j);
					counter2++;
					cr++;
					break;
				}
			}

		}
		if(cr != 0)
		counter1++;
		row_ptr[i] = counter1;
		counter1+= cr -1;

	}		
row_ptr[zeilen]=counter1+1;		
		
}


template<class T>
// Destruktor
  MatrixCSR<T>::~MatrixCSR() 
  {
   if(val != nullptr)
     delete [] val;
   if(col_ind != nullptr)
     delete [] col_ind;
   if(row_ptr != nullptr)
     delete [] row_ptr;
  };



template<class T>
// Speicherverbrauch
unsigned int MatrixCSR<T>::byte()
{
	double a(0), b(0);
	for(unsigned int i(0); i < size; i++)
		a+= sizeof(col_ind[i])+sizeof(val[i]);
	for(unsigned int i(0); i < zeilen+1; i++)
		b+= sizeof(row_ptr[i]);
	return a+b;
}


template<class T>
// Zeilen
  unsigned int MatrixCSR<T>::get_zei()
  {
    return zeilen;
  }
  
template<class T>
// Spalten
  unsigned int MatrixCSR<T>::get_spa()
  {
    return spalten;
  }

template<class T>
// size
  unsigned int MatrixCSR<T>::get_size()
  {
    return size;
  }


template<class T>
  unsigned int MatrixCSR<T>::get_col_ind(unsigned int i)
  {
    assert(i < size);
    assert(col_ind != nullptr);
    return col_ind[i]-1;
  }

template<class T>
  T& MatrixCSR<T>::get_val(unsigned int i)
  {
    assert(i < size);
    assert(col_ind != nullptr);
    return val[i];
  }

template<class T>
  unsigned int MatrixCSR<T>::get_row_ptr(unsigned int i)
  {
    assert(i < size);
    assert(row_ptr != nullptr);
    return row_ptr[i];
  }

template<class T>
// Matrix-Vektor-Multiplikation
  void MatrixCSR<T>::apply(Vector<T>& other, Vector<T>& result)
  {
    assert(spalten == other.get_size());
    assert(val != nullptr);
    assert(zeilen == result.get_size());
    
    
    for(unsigned int i(0); i < zeilen; i++)
    {T k(0);
      for(unsigned int j(row_ptr[i]); j < row_ptr[i+1]; j++)
	{
	  k += (val[j-1]*other[col_ind[j-1]-1]);
	};
      result[i] = k;
    }; 
    return;
  }


template class MatrixCSR<double>;
template class MatrixCSR<float>;
template class MatrixCSR<int>;
