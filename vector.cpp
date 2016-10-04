#include "vector.hpp"
#include <cassert>

//Standardkonstruktor
template<class T>
Vector<T>::Vector():
 size(0u), data(nullptr) { }; 
  
  //Benutzerdefinierter Konstruktor
  template<class T>
  Vector<T>::Vector(unsigned long _size) :
   size(_size), data(nullptr)
   {
     if(size > 0u)
       data=new T[size];
   };

   // Kopier-Konstruktor
   template<class T>
   Vector<T> :: Vector(const Vector<T>& other) 
   {
     data = new T[other.size];
   };
   
 //Destruktor
 template<class T>
  Vector<T>::~Vector() 
  {
   if(data != nullptr)
     delete [] data;
  };
  
  //Länge Vektor
  template<class T>
  unsigned int Vector<T> :: get_size()
  {
    return size;
  }
  
  //Überladung []
  template<class T>
  T& Vector<T> :: operator[](unsigned int i)
  {
    assert(i < size);
    assert(data != nullptr);
    return data[i];
  }

 //Kopier-Funktion
 template<class T>
 void Vector<T>::copy(const Vector<T>& other) 
  {
   if(size > 0u)
   {
    assert(other.data != nullptr);
    
    //kopiere Array-Inhalte
    for(unsigned int i(0); i < size; i++)
      this->data[i] = other.data[i];
   }
  }
  
  //Überladung =
  template<class T>
  Vector<T>& Vector<T> :: operator=(const Vector<T>& other)
  {
    assert(this->get_size() == other.size);
    this->copy(other);
    return *this;
  }
  
  
  // Überladung +
  template<class T>
  Vector<T> Vector<T> :: operator+(const Vector<T>& other)
  {
   assert(this->size == other.size);
   Vector<T> result(other.size);
   for(unsigned int i(0); i < other.size; i++)
   result.data[i] = this->data[i] + other.data[i];
   return result;
  }
  
  // Überladung -
  template<class T>
  Vector<T> Vector<T> :: operator-(const Vector<T>& other)
  {
   assert(this->size == other.size);
   Vector<T> result(other.size);
   for(unsigned int i(0); i < other.size; i++)
   result.data[i] = this->data[i] - other.data[i];
   return result;
  }
  
  // Skalarprodukt
  template<class T>
  T Vector<T> :: operator*(const Vector<T>& other)
  {
   assert(this->size == other.size);
   T result(0);
   for(unsigned int i(0); i < other.size; i++)
     result += this->data[i]*other.data[i];
   return result;
  }
  
  // 
  template<class T>
  Vector<T> Vector<T>::axpy(Vector<T>& y, T alpha)
  {
    assert(this->size == y.size);
    assert(data != nullptr);
    
    Vector<T> result(size);
    
    for(unsigned int i(0); i < size; i++)
    {T k(0);
	  k += (this->data[i]*alpha + y[i]);
      result[i] = k;
    }
    return result;
  }
  
  template class Vector<double>;
  template class Vector<float>;
  template class Vector<int>;