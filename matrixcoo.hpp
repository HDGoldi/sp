#ifndef MATRIXCOO_HPP
#define MATRIXCOO_HPP

template<class T>
class MatrixCOO
{
  private:
  unsigned long k;
  unsigned long zeilen;
  unsigned long spalten;
  unsigned long* zeilenindex;
  unsigned long* spaltenindex;
  T* data;
  MatrixCOO();
  MatrixCOO(const MatrixCOO<T>& other);
  
  public:
  explicit MatrixCOO(unsigned long zei, unsigned long spa);
  ~MatrixCOO();
  T& operator()(unsigned long i, unsigned long j);
  unsigned long get_zei();
  unsigned long get_spa();
  unsigned long get_k();
  unsigned long get_spaltenindex(unsigned long i);
  unsigned long get_zeilenindex(unsigned long i);
};

#endif // MATRIXCOO_HPP
