#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// new varibale

int a = 8;
int c = 23;
void* b;

//#define size_t unsigned int

void value_in_bounds(size_t v);

void Errors(void *ptr, unsigned int z)
{
  const size_t* a = (size_t*)ptr;
  size_t i;
  //ptr = (void *)a; //Invalid pointer
  //Infinity loop if array size > UINT_MAX
  for (i = 0; i != z; i++)
    printf("!!! Hallo !!!\n %zu\n", i);
	printf("*a=%zu\n", *a);
  value_in_bounds(*a);
}

void value_in_bounds(size_t v)
{
	v=v+1;
	printf("v=%zu\n", v);
}

struct st_t
{
	unsigned op;
	char* name;
};
struct st_t st = {
	.op = 7,
	.name = "Ursela Karioth",
};

unsigned int tt = 9;

int main(int argc, char *argv[]) {
	//const size_t* value = (size_t*)&a;
	b = (size_t*)&a;
	const size_t* value = (size_t*)b;
	printf("value: %zu\n", *value);
	value_in_bounds(*value);
	printf("size: %zu\n", sizeof(size_t));
	printf("%lu", SIZE_MAX);
	
	
	Errors(&tt, 3);
	
	unsigned long counter = 234;
	unsigned long start_tv_sec = 1000;
	unsigned long start_tv_usec = 14;
	unsigned long tv_sec = start_tv_sec + counter / 1000000;
	unsigned long tv_usec = start_tv_usec + counter % 1000000;
	if (tv_usec >= 1000000)
	{
				printf("Überlauf\n");
		tv_usec %= 1000000;
		tv_usec = start_tv_usec;
		tv_sec++;
	}
	printf("tv_sec: %d\n", tv_sec);
	printf("tv_usec: %d\n", tv_usec);
	
    counter = 2999990;
    start_tv_sec = 1002;
    start_tv_usec = 122;
	tv_sec = start_tv_sec + counter / 1000000;
    tv_usec = start_tv_usec + counter % 1000000;
	if (tv_usec >= 1000000)
	{
		printf("Überlauf\n");
		tv_usec %= 1000000;
		tv_sec++;
	}
	printf("tv_sec: %d\n", tv_sec);
	printf("tv_usec: %d\n", tv_usec);
		
	return 0;
}

// #define size_t unsigned
