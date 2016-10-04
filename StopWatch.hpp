#ifndef StopWatch_HPP
#define StopWatch_HPP

class StopWatch
{
	private:
	double* data;
    
  public:
    StopWatch();				//Konstruktor
    ~StopWatch();				//Destruktor
	double operator[](unsigned int i);    
	void startpunkt();
    void endpunkt();
    double diff();
};

#endif // StopWatch_HPP
