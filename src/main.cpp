#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/stat.h>

#include "Tors.h"
#include "dumps.h"
#include "addrem.h"
#include "insdel.h"

int main()
{
    ListStruct List = {};

    ListStructCtor(&List);

    for(int i = 10; i < 90; i += 10)
    {
        addElem(&List, i);
    }
    
    remElem(&List);
    remElem(&List);
    remElem(&List);
    remElem(&List);
    addElem(&List, 90);
    addElem(&List, 100);
    addElem(&List, 110);
    addElem(&List, 120);
    remElem(&List);
    remElem(&List);
    remElem(&List);
    remElem(&List);
    ListDump(&List);
    remElem(&List);
    ListDump(&List);
    remElem(&List);
    insElem(&List, 2, 47);
    ListDump(&List);

    

    ListStructDtor(&List);
}