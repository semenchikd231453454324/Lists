#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/stat.h>

#include "insdel.h"

int insElem(ListStruct* List, int AnchElem, int NewElem)
{
    assert(List);

    List->FiFo[List->free - 1] = NewElem;

    List->Next[AnchElem] = List->free - 1;
    List->Next[List->free -1] = AnchElem + 1;

    List->Prev[List->free -1] = AnchElem;
    List->Prev[AnchElem + 1] = List->free -1;

    List->free += 1;

    return 0;
}