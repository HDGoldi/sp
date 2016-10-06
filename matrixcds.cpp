#include "matrixcoo.hpp"
#include "matrixcds.hpp"
#include "vector.hpp"
#include <cassert>
#include <iostream>

template<class T>
// Benutzerdefinierter Konstruktor
MatrixCDS<T>::MatrixCDS(MatrixCOO<T>& other):
zeilen(other.get_zei()), spalten(other.get_spa()), val(nullptr), diag(nullptr), anzdiag(0)
{
  assert(zeilen == spalten);	// nur quadratische Matrizen
  
  int* diag_temp =new int[2*zeilen-1]; // temporärer Array soll später die Diagonalen angeben, welche nicht nur nullen enthalten:: temporär, weil wir nicht wissen wieviele =-Diagonalen es gibt.
  
  for(unsigned int ld(zeilen-1); ld>0; ld--) // geht (unteren)Diagonalen durch
  {
    bool bol(false);
    for(unsigned int k(0); k<other.get_k(); k++) // geht zeilenindex durch
    {
      for(unsigned int m(0); m<(zeilen-ld);m++) // geht die jeweiligen Paare durch
      {
	if(other.get_zeilenindex(k)==(ld+m) && other.get_spaltenindex(k)==m)
	{
	  int ld1 = ld;
	  diag_temp[anzdiag]=-ld1;	// Abspeicherung der Diagonalen, welche nicht Null sind
	  anzdiag++;
	  bol=true;
	  break;
	}
      }
      if(bol)
	break;
    }
  }
  
  diag_temp[anzdiag]=0;	// Hauptdiagonale
  anzdiag++;
  
  for(unsigned int rd(1); rd<(zeilen); rd++) // geht (oberen)Diagonalen durch
  {
    bool bol(false);
    for(unsigned int k(0); k<other.get_k(); k++) // geht spaltenindex durch
    {
      for(unsigned int m(0); m<(zeilen-rd);m++) // geht die jeweilige Paare durch
      {
	if(other.get_spaltenindex(k)==rd+m && other.get_zeilenindex(k)==m)
	{
	  int rd1=rd;
	  diag_temp[anzdiag]=rd1;
	  anzdiag++;
	  bol=true;
	}
	if(bol)
	  break;
      }
      if(bol)
	break;
    }
  }
  diag = new int[anzdiag];	//komprimiertes diagonal-array
  for(unsigned int i(0); i<anzdiag;i++)
    diag[i]=diag_temp[i];
  delete [] diag_temp;
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  val = new T[anzdiag*zeilen];
  if(anzdiag!=1)	// Other enthält nicht nur Hauptdiagonale
  {
    unsigned int z(0);
    for(unsigned int i(0); i<anzdiag*zeilen;i++)
    {
      if(diag[z]<=0)	// Nullen vor den Unter-Diagonal-Einträgenn 
      {
	for(unsigned int j(0); j<abs(diag[z]); j++)	// setzt Nullen
	{
	  val[i]=0;
	  i++;
	}
	for(unsigned int j(0); j<(zeilen+diag[z]); j++)	//fügt die Diagonaleinträge hinzu
	{
	  bool bol(true);
	  for(unsigned int k(0); k<other.get_k(); k++)	// findet heraus, wo diese sich im val-array befinden
	  {
	    if(other.get_zeilenindex(k)==(abs(diag[z])+j) && other.get_spaltenindex(k)==j)
	    {
	      val[i]=other(other.get_zeilenindex(k),other.get_spaltenindex(k));
	      i++;
	      bol=false;
	      break;
	    }
	  }
	  if(bol)	//wenn eine Null in der Diagonale ist
	  {
	    val[i]=0;
	    i++;
	  }
	}
	z++;
	i--;
      }
      else	// rechten neben-diagonalen
      {
	for(unsigned int j(0); j<(zeilen-diag[z]); j++)	//fügt die Diagonaleinträge hinzu
	{
	  bool bol(true);
	  for(unsigned int k(0); k<other.get_k(); k++)	// findet heraus, wo diese sich im val-array befinden
	  {
	    if(other.get_spaltenindex(k)==(diag[z]+j) && other.get_zeilenindex(k)==j)
	    {
	      val[i]=other(other.get_zeilenindex(k),other.get_spaltenindex(k));
	      i++;
	      bol=false;
	      break;
	    }
	  }
	  if(bol)	//wenn eine Null in der Diagonale ist
	  {
	    val[i]=0;
	    i++;
	  }
	}
	for(unsigned int j(0); j<abs(diag[z]); j++)	// setzt Nullen nach den Diagonaleinträgen
	{
	  val[i]=0;
	  i++;
	}
	z++;
	i--;
      }
    }
  }
  else	// Other enthält nur Hauptdiagonale
  {
    for(unsigned int i(0); i<zeilen; i++)	// Durchgehen der Diagonaleinträge
    {
      for(unsigned int k(0); k<other.get_k(); k++)	//Abfrage wo diese sind
      {
	if(other.get_zeilenindex(k)==i)
	{
	  val[i]=other(other.get_zeilenindex(k),other.get_spaltenindex(k));	// Läuft altar
	}
      }
    }
  }
}

template<class T>
// diag
int& MatrixCDS<T>::get_diag(unsigned int i)
{
  if(anzdiag==1)
  {
    std::cout << "Es gibt keine neben Hauptdiagonalen" << std::endl;
    return diag[0];
  }
  else
  {
    assert(i < anzdiag*zeilen);
    return diag[i];
  }
}

template<class T>
//diag
void MatrixCDS<T>::diagonalen()		//Gibt diag einmal schön aus
{
  for(unsigned int i(0); i<anzdiag-1; i++)
  {
    std::cout << diag[i] << ", ";
  }
  std::cout << diag[anzdiag-1] << std::endl;
}

template<class T>
// val
T& MatrixCDS<T>::get_val(unsigned int i)
{
  assert(i < anzdiag*zeilen);
  return val[i];
}

template<class T>	// gibt die abgespeicherten werte aus
//val
void MatrixCDS<T>::value()
{
  for(unsigned int i(0); i<(anzdiag*zeilen-1); i++)
  {
    std::cout << val[i] << " ";
    if((i+1)%zeilen==0)
      std::cout << std::endl;
  }
  std::cout << val[anzdiag*zeilen-1] << std::endl;
}

template<class T>
// Destruktor
MatrixCDS<T>::~MatrixCDS() 
{
  if(val != nullptr)
    delete [] val;
  if(diag != nullptr)
    delete [] diag;
};


template<class T>
// Speicherverbrauch
unsigned int MatrixCDS<T>::byte()
{
  T a(0);
  for(unsigned int i(0); i < zeilen*anzdiag; i++)
    a += sizeof(val[i]);
  for(unsigned int i(0); i<anzdiag; i++)
    a+=sizeof(diag[i]);
  return a;
}


template<class T>
// Matrix-Vektor-Multiplikation
void MatrixCDS<T>::apply(Vector<T>& other, Vector<T>& result)
{
  assert(spalten == other.get_size());
  assert(val != nullptr);
  assert(zeilen == result.get_size()); 
  for(int i(zeilen-1); i >=0; i--) 	// geht die Zeilen von unten nach oben durch, da erst die unterdiagonalen in val abgespeichert wurden
  {
    result[i]=0;
    int p(zeilen-1-i);		// Umwandlung von einem unsigned int in int, 
    int zaehl(0);		// für die spätere Zählung der Zählvariable zaehl, benutzen zaehl um keine Kollision mit den anderen Laufparametern zu haben
    for(int k(-i); k<=p; k++)	// gehen diag durch
    {
     bool bol(true);
      for(unsigned int j(0); j<=(anzdiag-1); j++)	// Überprüfung von diag, ob k drinne ist
      {
	if(diag[j]==k)
	{
	  result[i] += val[j*zeilen+i]*other[zaehl];
	  zaehl++;
	  bol =false;
	  break;
	}
      }
      if(bol)
      zaehl++;
    }
  }
}

template class MatrixCDS<double>;
template class MatrixCDS<float>;
template class MatrixCDS<int>;
