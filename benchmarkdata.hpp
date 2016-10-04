#ifndef BENCHMARKDATA_HPP
#define BENCHMARKDATA_HPP

class BenchmarkData
{
  private:
    double time;
    unsigned long transfers;
    unsigned long operations;
    BenchmarkData();
    BenchmarkData(const BenchmarkData& other);
    
  public:
    ~BenchmarkData();
    explicit BenchmarkData(double _time, unsigned long int _transfers, unsigned long int _operations);
    long double bandbreite();
    long double performance();
    double arith_int();
};

#endif // BENCHMARKDATA_HPP
