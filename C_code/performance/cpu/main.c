#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>

inline uint64_t empty_loop( uint64_t iterations )
{
	uint64_t iter;
	uint64_t result=0;
	struct timeval tv1,tv2;
	gettimeofday(&tv1,NULL);
	for(iter=iterations;iter!=0;iter--)
	{
		asm("push %eax");
		asm("push %ebx");
		asm("pop %ebx");
		asm("pop %eax");
	}
	gettimeofday(&tv2,NULL);
	result=(tv2.tv_usec+tv2.tv_sec*1000000ul)-(tv1.tv_usec+tv1.tv_sec*1000000ul);
	return result;
}

inline uint64_t notempty_loop( uint64_t iterations )
{
	uint64_t iter;
	uint64_t result=0;
	struct timeval tv1,tv2;
	gettimeofday(&tv1,NULL);
	for(iter=iterations;iter!=0;iter--)
	{
		asm("push %eax");
		asm("push %ebx");
		asm("mov %ax,%bx");
		asm("mov %ax,%bx");
		asm("mov %ax,%bx");
		asm("mov %ax,%bx");
		asm("mov %ax,%bx");
		asm("mov %ax,%bx");
		asm("mov %ax,%bx");
		asm("mov %ax,%bx");
		asm("mov %ax,%bx");
		asm("mov %ax,%bx");
		asm("pop %ebx");
		asm("pop %eax");
	}
	gettimeofday(&tv2,NULL);
	result=(tv2.tv_usec+tv2.tv_sec*1000000ul)-(tv1.tv_usec+tv1.tv_sec*1000000ul);
	return result;
}

int main( int argc, char **argv )
{
  uint64_t empty,notempty;
  uint64_t iterations = 1000000000ul;
  double instructions_per_second = 0;
  empty = empty_loop(iterations);
  notempty = notempty_loop(iterations);
  printf("Empty loop=%ld usec\n",empty);
  printf("Nonempty loop=%ld usec\n",notempty);
  instructions_per_second = (notempty*1.0-empty*1.0);
  printf("Time taken by the instructions = %f usec\n", instructions_per_second);
  instructions_per_second = instructions_per_second/(10.0*iterations);//One instruction time
  printf("Time taken by one instruction  = %f usec \n",instructions_per_second);
  instructions_per_second = 1000000/instructions_per_second;
  printf("Instuctions per second = %f \n",instructions_per_second);
  printf("MIPS = %f \n", instructions_per_second/1000000);
  return 0;
}
