#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/stat.h>

#include "dumps.h"

int FiFoDump(ListStruct* List)
{
    assert(List);

    printf("           FiFo Dump\n");

    printf("  ");

    int logs [10] = {};

    for(int j = 1; j < Size; j++)
    {
        if(List->FiFo[j])
        {
            logs[j] = (int) log10(List->FiFo[j]);
        }
    }

    printf("0  ");

    for(int i = 1; i < Size; i++)
    {
        printf("%d  ", i);

        for(int k = 0; k < logs[i]; k++)
        {
            printf(" ");
        }

    }

    printf("\n");
    printf(" ");

    for (int i = 0; i < Size; i++)
    {
        printf("[%d]", List->FiFo[i]);
    }

    printf("\n\n");

    return 0;
}

int NEXTDump(ListStruct* List)
{
    assert(List);

    printf("           NEXT Dump\n");

    printf("  ");

    bool minusone [10] = {};

    for(int i = 0; i < Size; i++)
    {
        if(List->Next[i] == -1)
        {
            minusone[i] = 1;
        }
    }

    printf("0  ");

    for (int i = 1; i < Size; i++)
    {
        printf("%d  ", i);
        if(minusone[i])
        {
            printf(" ");
        }
    }

    printf("\n");
    printf(" ");

    for (int i = 0; i < Size; i++)
    {
        printf("[%d]", List->Next[i]);
    }

    printf("\n\n");

    return 0;
}

int PREVDump(ListStruct* List)
{
    assert(List);

    printf("           PREV Dump\n");

    printf("  ");
    bool minusone [10] = {};

    for(int i = 0; i < Size; i++)
    {
        if(List->Prev[i] == -1)
        {
            minusone[i] = 1;
        }
    }

    printf("0  ");

    for (int i = 1; i < Size; i++)
    {
        printf("%d  ", i);
        if(minusone[i])
        {
            printf(" ");
        }
    }

    printf("\n");
    printf(" ");

    for (int i = 0; i < Size; i++)
    {
        printf("[%d]", List->Prev[i]);
    }

    printf("\n\n");

    return 0;
}

int ListDump(ListStruct* List)
{
    assert(List);

    printf("           List Dump\n");

    printf("Head = %d    Tail = %d    free = %d\n\n", List->Head, List->Tail, List->free);

    FiFoDump(List);
    NEXTDump(List);
    PREVDump(List);

    return 0;
}