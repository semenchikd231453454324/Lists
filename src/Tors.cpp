#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/stat.h> 

#include "Tors.h"

#define calmacro(array)                         \
    array = (int*) calloc(Size, sizeof(int));   \
    if (!array)                                 \
    {                                           \
        printf("Pointer array error in ctor\n");\
                                                \
        return 1;                               \
    }                                           
    
int ListStructCtor(ListStruct* List)
{
    assert(List);

    calmacro(List->FiFo);
    calmacro(List->Next);
    calmacro(List->Prev);

    for (int i = 1; i < Size; i++)
    {
        List->Next[i] = -1;
        List->Prev[i] = -1;
    }

    List->Head = 1;
    List->Tail = 1;
    List->SameCircle = 1;

    return 0;
}

int ListStructDtor(ListStruct* List)
{
    assert(List);

    free(List->FiFo);
    free(List->Next);
    free(List->Prev);

    List = {};

    return 0;
}