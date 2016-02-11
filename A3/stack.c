#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stackDefs.h"

void st_init(StackType *stk)
{
	stk->numFrames = 0;
}

void st_dump(StackType *stk)
{
  int i, j, k;

  printf("     -- STACK --\n");

  for (i=0; i<stk->numFrames; ++i) {
    printf("     ---- FRAME #%d:  %s \n", i, 
             stk->frames[i].funcName);

    for (j=0; j<stk->frames[i].numParams; j++) {
      printf("     ------ param %s: %4d \n", stk->frames->params[j]->name, *stk->frames->params[j]->value);
    }
  }
  printf("     -- END OF STACK --\n\n");
}

void st_createParam(char *name, int *valuePtr, ParamType **newParam)
{
    *newParam = (ParamType*)malloc(sizeof(ParamType));
	strcpy((*newParam)->name, name);
	(*newParam)->value = valuePtr;
}

void st_push(StackType* stk, char *fname, int num, ParamType **paramArr)
{
    //stk->frames[stk->numFrames] = (FrameType*)malloc(sizeof(FrameType));
	
	stk->frames[stk->numFrames].numParams = num; //copy numFrames into new numFrames
	strcpy(stk->frames[stk->numFrames].funcName, fname); //copy fname into name
	
	stk->frames[stk->numFrames].params[0] = paramArr[0];
	stk->frames[stk->numFrames].params[1] = paramArr[1];
	
	stk->numFrames++; //increment numframes
}

void st_pop(StackType* stk)
{
    if(stk->numFrames == 0)
        return;
    printf("stk->numFrames: %d\n\n", stk->numFrames);
    st_dump(stk);

	int i;
	for(i = 0; i < stk->numFrames-1; i++) {
	    free(stk->frames[stk->numFrames].params[i]); //free the allocated memory
    }
    
	free(&(stk->frames[stk->numFrames])); //free the allocated memory
	stk->numFrames = (stk->numFrames-1); //decrement the total amount of frames so the next call to st_pop is accurate
	
}

