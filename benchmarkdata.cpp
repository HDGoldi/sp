#include "benchmarkdata.hpp"

//Standardkonstruktor
BenchmarkData::BenchmarkData():
time(0), transfers(0), operations(0) { }; 

//Benutzerdefinierter Konstruktor
BenchmarkData :: BenchmarkData(double _time, unsigned long int _transfers, unsigned long int _operations) :
time(_time), transfers(_transfers), operations(_operations) { };

// Kopier-Konstruktor
BenchmarkData :: BenchmarkData(const BenchmarkData& other) { };

//Destruktor
BenchmarkData :: ~BenchmarkData() { };

//Bandbreite berechnen
long double BenchmarkData :: bandbreite()
{
  return (double(transfers)/time)/1000000000.0;
}

//Bandbreite berechnen
long double BenchmarkData :: performance()
{
  return (double(operations)/time)/1000000000.0;
}

//Bandbreite berechnen
double BenchmarkData :: arith_int()
{
  return performance()/bandbreite();
}
