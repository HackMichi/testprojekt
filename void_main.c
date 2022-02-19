#include <stdio.h>
#include <stdlib.h>




/* void_ptr1.c */
#include <stdio.h>
#include <stdlib.h>

#define EE_ID_1   0
#define EE_ID_2   4
#define EE_ID_3   5
#define EE_ID_4   6
#define EE_ID_5   8

struct ee_para_t
{
  unsigned int ee_1;
  char ee_2;
  char ee_3;
  char ee_4[2];
  unsigned int ee_5;
};

struct ee_para_t ee_para;



/*
void get_para (void* para, unsigned int id, char ee_typ)
{
  char* ptr = (char*)&ee_para;
  ptr += id;
  
   if (id == 1)	
    *(char*)para = *(char*)&a;
  else
    *(unsigned int*)para = *(unsigned int*)&b;   
}
*/

char* get_para_b (unsigned int id)
{
  char* ptr = (char*)&ee_para;
  ptr += id;
  return (char*)ptr;	
}


unsigned int* get_para_w (unsigned int id)
{
  char* ptr = (char*)&ee_para;
  ptr += id;
  return (unsigned int*)ptr;	
}

void * get_para_1(unsigned int id, char ee_typ)
{
  char* ptr = (char*)&ee_para;
  ptr += id;
  if (ee_typ == 1)	
    return (char*)ptr;
  else
    return (unsigned int*)ptr;
}

void set_para(unsigned int id, char ee_typ, void* value)
{
	  char* ptr = (char*)&ee_para;
  ptr += id;
  if (ee_typ == 1)	
    *(char*)ptr = *(char*)value;
  else
    *(unsigned int*)ptr = *(unsigned int*)value;
}

int main(void) {

ee_para.ee_1 = 0;
ee_para.ee_2 = 0;
ee_para.ee_3 = 0;
ee_para.ee_4[0] = 0;
ee_para.ee_4[1] = 0;
ee_para.ee_5 = 0;


  unsigned int v1 = 1234;
    char v2 = 1;
      char v3 = 2;
        char v4_0 = 3;
                char v4_1 = 4;
          unsigned int v5 = 9876;

            
  set_para(EE_ID_1, 2, (unsigned int*)&v1);
  set_para(EE_ID_2, 1, (char*)&v2);
    set_para(EE_ID_3, 1, (char*)&v3);
  set_para(EE_ID_4, 1, (char*)&v4_0);
    set_para(EE_ID_4+1, 1, (char*)&v4_1);
  set_para(EE_ID_5, 2, (unsigned int*)&v5);

  char* p;
  char ree_2;
  unsigned int ree_1;
  char ree_3;
  char ree_4[2];
  unsigned int ree_5;
   ree_1 = *(unsigned int*)get_para_1(EE_ID_1, 2);
   ree_2 = *(char*)get_para_1(EE_ID_2, 1);
   ree_3 = *(char*)get_para_1(EE_ID_3, 1);
   p = (char*)get_para_1(EE_ID_4, 1);
   ree_4[0] = *p;
   ree_4[1] = *(p+1);
   ree_5 = *(unsigned int*)get_para_1(EE_ID_5, 2);
   	        
   printf("ee_1 = %u\n",ree_1);
   printf("ee_2 = %d\n",ree_2);
   printf("ee_3 = %d\n",ree_3);
   printf("ee_4_0 = %d\n",ree_4[0]);
   printf("ee_4_1 = %d\n",ree_4[1]);
      printf("ee_5 = %u\n",ree_5);
    //----------------
	
	ee_para.ee_1 = 5632;
ee_para.ee_2 = 22;
ee_para.ee_3 = 33;
ee_para.ee_4[0] = 44;
ee_para.ee_4[1] = 55;
ee_para.ee_5 = 2980;  
      
         ree_1 = *(unsigned int*)get_para_1(EE_ID_1, 2);
   ree_2 = *(char*)get_para_1(EE_ID_2, 1);
   ree_3 = *(char*)get_para_1(EE_ID_3, 1);
   p = (char*)get_para_1(EE_ID_4, 1);
   ree_4[0] = *p;
   ree_4[1] = *(p+1);
   ree_5 = *(unsigned int*)get_para_1(EE_ID_5, 2);
   
      printf("ee_1 = %u\n",*get_para_w(EE_ID_1));
   printf("ee_2 = %d\n",*get_para_b(EE_ID_2));
   printf("ee_3 = %d\n",*get_para_b(EE_ID_3));
   printf("ee_4_0 = %d\n",*get_para_b(EE_ID_4));
   printf("ee_4_1 = %d\n",*get_para_b(EE_ID_4+1));
      printf("ee_5 = %u\n",*get_para_w(EE_ID_5));
}
