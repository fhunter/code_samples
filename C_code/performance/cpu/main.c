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
	for(iter=iterations;iter!=0;iter--)
	{
		asm("push %eax");
		asm("push %ebx");
		asm("pop %ebx");
		asm("pop %eax");
	}
	clock_gettime(CLOCK_ID,&tv2);
	result=(tv2.tv_nsec+tv2.tv_sec*1000000000ul)-(tv1.tv_nsec+tv1.tv_sec*1000000000ul);
	return result;
}

inline uint64_t notempty_loop( uint64_t iterations )
{
	uint64_t iter;
	uint64_t result=0;
	struct timespec tv1,tv2;
	clock_gettime(CLOCK_ID,&tv2);
	for(iter=iterations;iter!=0;iter--)
	{
		asm("push %eax");
		asm("push %ebx");
		asm("mov %ax,%bx");
		asm("mov %bx,%ax");
		asm("mov %ax,%ax");
		asm("mov %bx,%bx");
		asm("mov %ax,%bx");
		asm("mov %ax,%bx");
		asm("mov %ax,%bx");
		asm("mov %ax,%bx");
		asm("mov %ax,%bx");
		asm("mov %ax,%bx");
		asm("pop %ebx");
		asm("pop %eax");
	}
	clock_gettime(CLOCK_ID,&tv2);
	result=(tv2.tv_nsec+tv2.tv_sec*1000000000ul)-(tv1.tv_nsec+tv1.tv_sec*1000000000ul);
	return result;
}

int main( int argc, char **argv )
{
  uint64_t empty,notempty;
  uint64_t iterations = 1000000ul;
  double instructions_per_second = 0;
  empty = empty_loop(iterations);
  notempty = notempty_loop(iterations);
  printf("Empty loop=%ld nanoseconds\n",empty);
  printf("Nonempty loop=%ld nanoseconds\n",notempty);
  instructions_per_second = (notempty*1.0-empty*1.0);
  printf("Time taken by the instructions = %f nanoseconds\n", instructions_per_second);
  instructions_per_second = instructions_per_second/(10.0*iterations);//One instruction time
  printf("Time taken by one instruction  = %f nanoseconds \n",instructions_per_second);
  instructions_per_second = 1000000000.0/instructions_per_second;
  printf("Instuctions per second = %f \n",instructions_per_second);
  printf("MIPS = %f \n", instructions_per_second/1000000);
  return 0;
}
