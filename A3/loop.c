#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stackDefs.h"

void sumIterative(StackType* stk, int numElements, int* intArray, int *sum)
{   
    ParamType* tempParams[2];
    ParamType* tp1;
    ParamType* tp2;
        
    st_createParam("numElements", &numElements, &tp1);
    st_createParam("sum", sum, &tp2);
        
    tempParams[0] = tp1;
    tempParams[1] = tp2;
    
    char funcName[] = "sumIterative";
    st_push(stk, funcName, 2, tempParams);
    
    int i;
    *sum = 0;

    for (i=0; i<numElements; ++i) {
      *sum += intArray[i];
    }
    
    st_pop(stk);
    free(tp1);
    free(tp2);
}


void sumRecursive(StackType* stk, int numElements, int *intArray, int *sum)
{
  if(numElements == 0) {
    *sum = 0;
    return;
  }
  
  printf("SUM: %d\n", *sum);
  printf("NUM ELEMENTS: %d\n", numElements);
  
  ParamType* tempParams[2];
  ParamType* tp1;
  ParamType* tp2;
  
  printf("New numElements: %d\n", numElements);
  numElements--;
  st_createParam("numElements", &numElements, &tp1);
  st_createParam("sum", sum, &tp2);
    
  tempParams[0] = tp1;
  tempParams[1] = tp2;

  char funcName[] = "sumRecursive";
  st_push(stk, funcName, 2, tempParams);
  
  sumRecursive(stk, numElements, intArray, sum);
  *sum += intArray[numElements];
    
  st_pop(stk);

}

