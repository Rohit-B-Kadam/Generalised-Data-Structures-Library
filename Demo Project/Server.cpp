//Server.cpp
using namespace std;
#include<iostream>
#include "CommonHeaderFile.h"

//extern "c" is use to tell compiler to compile code as a c because cpp change the function name
extern "C"
{
    class Demo
    {
        public:
         Demo()
         {
             
         }
    };

    int iAdd2i( int iNo1 , int iNo2)
    {
        int iAnswer = 0;
        iAnswer = iNo1 + iNo2;
        return iAnswer;
    }

    int iSub2i( int iNo1 , int iNo2)
    {
        int iAnswer = 0;
        iAnswer = iNo1 - iNo2;
        return iAnswer;
    }

    int iMult2i( int iNo1 , int iNo2)
    {
        int iAnswer = 0;
        iAnswer = iNo1 * iNo2;
        return iAnswer;
    }

    int iDiv2i( int iNo1 , int iNo2)
    {
        int iAnswer = 0;
        if(iNo2 != 0 )
            iAnswer = iNo1 / iNo2;
        else
            iAnswer = 0;
        return iAnswer;
    }
}