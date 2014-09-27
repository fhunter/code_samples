#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define CLOCK_ID CLOCK_PROCESS_CPUTIME_ID

inline uint64_t empty_loop( uint64_t iterations )
{
	uint64_t iter;
	uint64_t result=0;
	struct timespec tv1,tv2;
	clock_gettime(CLOCK_ID,&tv1);
	//Insert measurement here
	clock_gettime(CLOCK_ID,&tv2);
	result=(tv2.tv_nsec+tv2.tv_sec*1000000000ul)-(tv1.tv_nsec+tv1.tv_sec*1000000000ul);
	return result;
}

int main( int argc, char **argv )
{
  uint64_t empty;
  uint64_t iterations = 1000000ul;
  double instructions_per_second = 0;
  empty = empty_loop(iterations);
  printf("Empty loop=%ld nanoseconds\n",empty);
  return 0;
}
