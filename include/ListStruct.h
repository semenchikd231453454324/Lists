#ifndef LISTSTRUCT_H
#define LISTSTRUCT_H

#define Size 10

#include <stdlib.h>

struct ListStruct
{
    int* FiFo;
    int* Next;
    int* Prev;

    int Tail, Head, free;

    bool SameCircle;
};

#endif