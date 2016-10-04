#include "StopWatch.hpp"
#include <cassert>
#include <sys/time.h>

StopWatch::StopWatch():
data(nullptr)
{
	data = new double[2];
};

StopWatch::~StopWatch()
{
	if(data!=nullptr)
	 delete [] data;
};

double StopWatch::operator[](unsigned int i)
{
	assert(i<2);
	assert(data!=nullptr);
	return data[i];
}

void StopWatch::startpunkt()
{
  struct timeval t;
  gettimeofday(&t,0);
  double start=t.tv_sec+(t.tv_usec/1000000.0);
	data[0]=start;
}
void StopWatch::endpunkt()
{
  struct timeval t;
  gettimeofday(&t,0);
  double end=t.tv_sec+(t.tv_usec/1000000.0);
	  data[1]=end;
}

double StopWatch::diff()
{
  assert(data[0]<=data[1]);
  double result=data[1]-data[0];
  return result;
}
