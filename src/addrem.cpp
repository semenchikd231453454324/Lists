#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/stat.h>

#include "addrem.h"

int addElem(ListStruct* List, int NewElem)
{
    assert(List);

    if(!(List->Head % Size))
    {
        List->Head += 1;
        List->SameCircle = !List->SameCircle;
    }

    if(List->SameCircle)
    {
        List->FiFo[(List->Head) % Size] = NewElem;

        if(List->Head % Size == Size - 1)
        {
            List->Next[(List->Head) % Size] = (List->Head + 2) % Size;
        }
        else
        {
            List->Next[(List->Head) % Size] = (List->Head + 1) % Size;
        }

        List->Prev[(List->Head) % Size] = (List->Head - 1) % Size;
    }
    else
    {

        if(List->Head %  Size < List->Tail % Size)
        {
            printf("HUI\n");
            if (List->FiFo[(List->Head) % Size] == 0)
            {
                List->FiFo[(List->Head) % Size] = NewElem;

                List->Next[(List->Head) % Size] = (List->Head + 1) % Size;

                if(!((List->Head - 1) % Size))
                {
                    List->Prev[(List->Head) % Size] = Size - 1;
                }
                else
                {
                    List->Prev[(List->Head) % Size] = (List->Head - 1) % Size;
                }
            }
        }
        else
        {
            printf("Can't add element\n");
        }
    }

    List->Head += 1;
    List->free = (List->Head % Size) + 1;

    return 0;
}

int remElem(ListStruct* List)
{
    assert(List);

    if(!(List->Tail % Size))
    {
        List->Tail += 1;
        List->SameCircle = !List->SameCircle;

        List->Head -= Size;
        List->Tail -= Size;
    }

    if(List->SameCircle)
    {
        if(List->Tail  % Size < List->Head  % Size)
        {
            List->FiFo[List->Tail  % Size] = 0;

            List->Prev[List->Next[List->Tail  % Size]] = -1;

            List->Next[List->Tail  % Size] = -1;

            List->Prev[List->Tail  % Size] = -1;
        }
        else  
        {
            printf("Same Circle Tail >= Head\n");
        }
    }
    else if(!List->SameCircle)
    {
        if(List->Tail % Size > List->Head % Size)
        {
            List->FiFo[List->Tail % Size] = 0;

            List->Prev[List->Next[List->Tail % Size]] = -1;

            List->Next[List->Tail % Size] = -1;

            List->Prev[List->Tail % Size] = -1;
        }
        else  
        {
            printf("!Same Circle Tail <= Head\n");
        }
    }
    else
    {
        printf("Can't remove element unknown circle\n");
    }

    List->Tail += 1;

    return 0;
}