#include <stdio.h>
#include <math.h>
#include <string.h>
#define ARRAY_SIZE  20


char buffer[10];

unsigned int get_diff (void);
void add_diff (char* buf);

unsigned int get_diff (void)
{
	return 0x0045;
}

void add_diff (char* buf)
{
  		char result[10] = {0};
	unsigned int diff = get_diff();
	if (diff > 9999)
      diff = 9999;
    int i;
    sprintf(result, "%04d", diff); 
        printf("\n The string for the diff is %s\n", result); 
    
    for (i=0; i<4; i++)
    {
      result[i] -= 0x30;
      *buf++ = result[i];
    }


}

int main()
{
	int i;
    buffer[0] = 0x32;
    buffer[1] = 0x33;
    add_diff(&buffer[2]);
    
    for (i=0; i<6; i++)
      printf("%x\n", buffer[i]); 
                                     
}



