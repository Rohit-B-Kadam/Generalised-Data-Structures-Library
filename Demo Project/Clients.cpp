//Clients.cpp
using namespace std;

#include<iostream>
#include<stdio.h>
#include <dlfcn.h>
#include "CommonHeaderFile.h"
#include <stdlib.h>
#include <gnu/lib-names.h>

int main()
{
    int iNo1 , iNo2;
    int iAnswer;
    void* p;

    int (*fp)(int , int);

    p = dlopen("SharedObject.so", RTLD_LAZY);
    if( p == NULL)
    {
        printf("Error: Unable to load Library\n");
        return 0;
    }

    printf("Enter the 2 number: ");
    scanf("%d %d" , &iNo1 , &iNo2 );

    fp = (int (*)(int , int )) dlsym(p , "iAdd2i");
    iAnswer = fp( iNo1 , iNo2);
    printf("Addition of %d and %d is %d \n",iNo1 , iNo2 , iAnswer);
    
    fp = (int (*)(int , int )) dlsym(p , "iSub2i");
    iAnswer = fp( iNo1 , iNo2);
    printf("Substraction of %d and %d is %d\n",iNo1 , iNo2 , iAnswer);
    
    fp = (int (*)(int , int )) dlsym(p , "iMult2i");
    iAnswer = fp( iNo1 , iNo2);
    printf("Multiplication of %d and %d is %d\n",iNo1 , iNo2 , iAnswer);
    
    fp = (int (*)(int , int )) dlsym(p , "iDiv2i");
    iAnswer = fp( iNo1 , iNo2);
    printf("Division of %d and %d is %d\n",iNo1 , iNo2 , iAnswer);
    
    return 0;
}