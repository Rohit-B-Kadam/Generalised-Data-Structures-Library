using namespace std;

#include<iostream>
#include<stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <gnu/lib-names.h>

#include "SharedFile.h"

int main()
{
    void* p = NULL;
    SingleLL *ptr = NULL;

    // Function Pointer
    SingleLL* (*fp1)() = NULL;      // For CreateSingleLL Function
    void (*fp2)(SingleLL*) = NULL;  // For DeleteSingleLL Function

    // Link Dynamic library
    p = dlopen("Collection.so", RTLD_LAZY);

    if(!p)
    {
        printf("Unable to load Library");
    }
    
    // Get the function pointer
    fp1 = (SingleLL* (*)()) dlsym(p, "CreateSingleLL");
    fp2 = (void (*)(SingleLL*)) dlsym(p, "DestroySingleLL");

    ptr = fp1();

    ptr->InsertFirst(10);
    ptr->Insert(1, 70);
    ptr->Insert(2, 80);
    ptr->InsertLast(40);
    ptr->InsertFirst(50);
    ptr->Display();
    ptr->DeleteFirst();
    ptr->DeleteLast();
    ptr->Delete(2);
    ptr->Display();

    fp2(ptr);

    // UnLink the Library
    dlclose(p);
    return 0;
}